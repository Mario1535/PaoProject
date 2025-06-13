#include "mediaeditor.h"
#include "ui_mediaeditor.h"
#include "newmediatypedialog.h"

#include "..\media\abstractMedia.h"
#include "..\media\podcast.h"
#include "..\media\music.h"
#include "..\media\audiobook.h"
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

    dialog = new newMediaTypeDialog();
    unsigned short int index = 0;
    QObject::connect(dialog, &newMediaTypeDialog::mediaTypeChosen, this, [&index](unsigned short int value) {
        index = value;

    });
    dialog->exec();

    qDebug() << "index:" << index;
    ui->stackedWidget->setCurrentIndex(index);

}

mediaEditor::~mediaEditor()
{
    delete ui;
    delete dialog;
}

void mediaEditor::onSaveButtonClicked() {

    AbstractMedia* media = nullptr;
    QString title = ui->titleLine->text();
    QString author = ui->authorLine->text();
    unsigned int duration = ui->durationLine->value();
    unsigned int year = ui->yearLine->value();

    if (ui->stackedWidget->currentIndex() == 0){// audiolibro

        QString imagePathToSave;
        if (!photoPath.isEmpty()) {
            imagePathToSave = photoPath;
        } else {
            imagePathToSave = "../../assets/audiobook_default.png";
        }
        std::string imagePath = imagePathToSave.toStdString();

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

        QString imagePathToSave;
        if (!photoPath.isEmpty()) {
            imagePathToSave = photoPath;
        } else {
            imagePathToSave = "../../assets/music_default.png";
        }
        std::string imagePath = imagePathToSave.toStdString();

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

        QString imagePathToSave;
        if (!photoPath.isEmpty()) {
            imagePathToSave = photoPath;
        } else {
            imagePathToSave = "../../assets/podcast_default.png";
        }
        std::string imagePath = imagePathToSave.toStdString();

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

    qDebug() << "Titolo:" << QString::fromStdString(media->getTitle());
    qDebug() << "Autore:" << QString::fromStdString(media->getAuthor());
    qDebug() << "immagine:" << QString::fromStdString(media->getImagePath());
    //qDebug() << "anno:" << QString::fromStdString(media->getYear());
    //qDebug() << "durata:" << QString::fromStdString(media->getDuration());



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
