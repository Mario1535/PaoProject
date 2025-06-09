#include "mediaeditor.h"
#include "ui_mediaeditor.h"

#include "..\media\abstractMedia.h"
#include "..\media\podcast.h"
#include "..\media\music.h"
#include "..\media\audiobook.h"

#include "..\converter\converter.h"

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

/*
void mediaEditor::setupUI()
{
    // Main vertical layout (already created in .ui)
    QVBoxLayout *mainLayout = this->findChild<QVBoxLayout*>("verticalLayout");

    // Configure stretch factors for resizing behavior
    if (mainLayout) {
        // Make stacked widget expand (index 5 in your layout)
        mainLayout->setStretch(0, 1);  // Photo section
        mainLayout->setStretch(1, 1);  // Title
        mainLayout->setStretch(2, 1);  // Author
        mainLayout->setStretch(3, 1);  // Year
        mainLayout->setStretch(4, 1);  // Duration
        mainLayout->setStretch(5, 3);  // Stacked widget (gets more space)
        mainLayout->setStretch(6, 1);  // Save button
        mainLayout->setStretch(7, 1);  // Close button

        // Configure margins and spacing
        mainLayout->setContentsMargins(15, 15, 15, 15);
        mainLayout->setSpacing(10);
    }

    // Configure the stacked widget
    QStackedWidget *stackedWidget = this->findChild<QStackedWidget*>("stackedWidget");
    if (stackedWidget) {
        // Remove maximum height constraint to allow resizing
        stackedWidget->setMaximumHeight(QWIDGETSIZE_MAX);

        // Configure each page's layout
        QStringList pages = {"music", "podcast", "audiobook"};
        foreach (const QString &page, pages) {
            QWidget *pageWidget = stackedWidget->findChild<QWidget*>(page);
            if (pageWidget) {
                QVBoxLayout *pageLayout = pageWidget->findChild<QVBoxLayout*>();
                if (pageLayout) {
                    pageLayout->setContentsMargins(0, 0, 0, 0);
                    pageLayout->setSpacing(10);
                }
            }
        }
    }

    // Configure all line edits to expand horizontally
    QList<QLineEdit*> lineEdits = this->findChildren<QLineEdit*>();
    foreach (QLineEdit *lineEdit, lineEdits) {
        lineEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    }

    // Configure all buttons
    QList<QPushButton*> buttons = this->findChildren<QPushButton*>();
    foreach (QPushButton *button, buttons) {
        button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    }

    // Special handling for the photo label (if you want it to scale)
    QLabel *photoLabel = this->findChild<QLabel*>("photoLabel");
    if (photoLabel) {
        photoLabel->setScaledContents(true);
        photoLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    }
}
*/

void mediaEditor::loadMedia(AbstractMedia *media) {
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

void mediaEditor::onSaveButtonClicked() {

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
