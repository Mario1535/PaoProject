#include "mediaeditor.h"
#include "ui_mediaeditor.h"
#include "newmediatypedialog.h"

#include "..\media\abstractMedia.h"
#include "..\media\podcast.h"
#include "..\media\music.h"
#include "..\media\audiobook.h"

#include "..\converter\converter.h"
#include "..\visitor\concretevisitor.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>


mediaEditor::mediaEditor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mediaEditor)
    , currentMedia(nullptr)
{
    ui->setupUi(this);

    // Connessione dei pulsanti
    connect(ui->saveButton, &QPushButton::clicked, this, &mediaEditor::onSaveButtonClicked);
    connect(ui->closeButton, &QPushButton::clicked, this, &mediaEditor::onCancelButtonClicked);
    connect(ui->photoButton, &QPushButton::clicked, this, &mediaEditor::onChangePhotoButtonClicked);

}

mediaEditor::~mediaEditor()
{
    delete ui;
}

void mediaEditor::onSaveButtonClicked() {

    newMediaTypeDialog dialog;
    short unsigned int index;
    QObject::connect(&dialog, &newMediaTypeDialog::mediaTypeChosen, [&index](int value) {
        index = value;
        //qDebug() << "index:" << index;
    });

    ui->stackedWidget->setCurrentIndex(index);

    AbstractMedia* media = nullptr;
    QString title = ui->titleLabel->text();
    QString author = ui->authorLabel->text();
    unsigned int duration = ui->durationLine->value();
    unsigned int year = ui->yearLine->value();
    QPixmap picture;


    if (ui->stackedWidget->currentIndex() == 0){// audiolibro
        std::string imagePath = Converter::convertPixmapToPath(picture);
        media = new Audiobook(
            title.toStdString(),
            author.toStdString(),
            imagePath,
            year,
            duration,

            (ui->readerLine->text()).toStdString(),
            (ui->summaryText->toPlainText()).toStdString()

            );


    }

    if (ui->stackedWidget->currentIndex()== 1){// musica
        std::string imagePath = Converter::convertPixmapToPath(picture);
        media = new Music(
            title.toStdString(),
            author.toStdString(),
            imagePath,
            year,
            duration,

            (ui->albumLine->text()).toStdString(),
            (ui->lyricsText->toPlainText()).toStdString()

            );


    }

    if (ui->stackedWidget->currentIndex() == 2){// podcast
        std::string imagePath = Converter::convertPixmapToPath(picture);
        media = new Podcast(
            title.toStdString(),
            author.toStdString(),
            imagePath,
            year,
            duration,

            (ui->episodeLine->text()).toStdString(),
            (ui->seasonLine->text()).toStdString()
            );
    }

    if (media) {
        emit newMediaCreated(media);  // Notifica il container
    }

    accept();
}

void mediaEditor::loadMedia(Visitor* visitor) {
    currentMedia = media;
    ui->photoLabel->setPixmap(QPixmap(QString::fromStdString(media->getImagePath())).scaled(200, 200, Qt::KeepAspectRatio));
    ui->titleLine->setText(QString::fromStdString(media->getTitle()));
    ui->authorLine->setText(QString::fromStdString(media->getAuthor()));
    ui->yearLine->setValue(media->getYear());
    ui->durationLine->setValue(media->getDuration());

    if (auto audiobook = dynamic_cast<Audiobook*>(media)) {
        ui->stackedWidget->setCurrentIndex(0);  // Audiolibro
        ui->readerLine->setText(QString::fromStdString(audiobook->getReader()));
        ui->summaryText->setText(QString::fromStdString(audiobook->getSummary()));
    } else if (auto music = dynamic_cast<Music*>(media)) {
        ui->stackedWidget->setCurrentIndex(1);  // Musica
        ui->albumLine->setText(QString::fromStdString(music->getAlbum()));
        ui->lyricsText->setText(QString::fromStdString(music->getLyrics()));
    } else if (auto podcast = dynamic_cast<Podcast*>(media)) {
        ui->stackedWidget->setCurrentIndex(2);  // Podcast
        ui->episodeLine->setText(QString::fromStdString(podcast->getEpisode()));
        ui->seasonLine->setText(QString::fromStdString(podcast->getSeason()));
    }
}

AbstractMedia* mediaEditor::getMedia() {
    return currentMedia;
}






void mediaEditor::onCancelButtonClicked() {
    // Chiudi la finestra senza salvare
    reject();
}

void mediaEditor::onChangePhotoButtonClicked() {
    QString newPhotoPath = QFileDialog::getOpenFileName(this, "Seleziona una foto", "", "Immagini (*.png *.jpg *.jpeg)");
    if (!newPhotoPath.isEmpty()) {
        photoPath = newPhotoPath;
        ui->photoLabel->setPixmap(QPixmap(photoPath).scaled(200, 200, Qt::KeepAspectRatio));
    }
}
