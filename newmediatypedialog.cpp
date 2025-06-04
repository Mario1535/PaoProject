#include "newmediatypedialog.h"
#include "ui_newmediatypedialog.h"
#include "mediaeditor.h"
#include "mainwindow.h"
#include "abstractmedia.h"

newMediaTypeDialog::newMediaTypeDialog(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::newMediaTypeDialog)
{
    ui->setupUi(this);

    connect(ui->audiobookButton, &QPushButton::clicked, this, &newMediaTypeDialog::onAudiobookButtonClicked);
    connect(ui->musicButton, &QPushButton::clicked, this, &newMediaTypeDialog::onMusicButtonClicked);
    connect(ui->podcastButton, &QPushButton::clicked, this, &newMediaTypeDialog::onPodcastButtonClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &newMediaTypeDialog::onCancelButtonClicked);
}

newMediaTypeDialog::~newMediaTypeDialog()
{
    delete ui;
}

void newMediaTypeDialog::onAudiobookButtonClicked() {
    emit mediaTypeChosen(AbstractMedia::Audiobook);  // Notifica la MainWindow
    close();
}
void newMediaTypeDialog::onMusicButtonClicked() {
    emit mediaTypeChosen(AbstractMedia::Music);  // Notifica la MainWindow
    close();
}
void newMediaTypeDialog::onPodcastButtonClicked() {
    emit mediaTypeChosen(AbstractMedia::Podcast);  // Notifica la MainWindow
    close();
}
void newMediaTypeDialog::onCancelButtonClicked() {
    close();
}
