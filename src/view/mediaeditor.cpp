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

void mediaEditor::loadMedia(ConcreteVisitor* visitor) {

    const ConcreteVisitor::Attributes &attributes = visitor->getAttributes();

    ui->photoLabel->setPixmap(QPixmap(QString::fromStdString(attributes.imagePath)).scaled(200, 200, Qt::KeepAspectRatio));
    ui->titleLine->setText(QString::fromStdString(attributes.title));
    ui->authorLine->setText(QString::fromStdString(attributes.author));
    ui->yearLine->setValue(attributes.year);
    ui->durationLine->setValue(attributes.duration);

    if (attributes.details.find("reader") != attributes.details.end()) {
        ui->stackedWidget->setCurrentIndex(0);
    } else if (attributes.details.find("album") != attributes.details.end()) {
        ui->stackedWidget->setCurrentIndex(1);
    } else if (attributes.details.find("episode") != attributes.details.end()) {
        ui->stackedWidget->setCurrentIndex(2);
    }

    if (ui->stackedWidget->currentIndex() == 0) {// Libro
        auto readerIter = attributes.details.find("reader");
        auto summaryIter = attributes.details.find("summary");

        ui->readerLine->setText((readerIter != attributes.details.end()) ? QString::fromStdString(readerIter->second) : "Unknown");
        ui->summaryText->setText((summaryIter != attributes.details.end()) ? QString::fromStdString(summaryIter->second) : "Unknown");
    }
    else if (ui->stackedWidget->currentIndex() == 1) {// Articolo
        auto albumIter = attributes.details.find("album");
        auto lyricsIter = attributes.details.find("lyrics");

        ui->albumLine->setText((albumIter != attributes.details.end()) ? QString::fromStdString(albumIter->second) : "Unknown");
        ui->lyricsText->setText((lyricsIter != attributes.details.end()) ? QString::fromStdString(lyricsIter->second) : "Unknown");
    }
    else if (ui->stackedWidget->currentIndex() == 2) {// Film
        auto episodeIter = attributes.details.find("episode");
        auto seasonIter = attributes.details.find("season");

        ui->episodeLine->setText((episodeIter != attributes.details.end()) ? QString::fromStdString(episodeIter->second) : "Unknown");
        ui->seasonLine->setText((seasonIter != attributes.details.end()) ? QString::fromStdString(seasonIter->second) : "Unknown");
    }

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
