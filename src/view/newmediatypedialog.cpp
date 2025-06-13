#include "newmediatypedialog.h"
#include "ui_newmediatypedialog.h"

newMediaTypeDialog::newMediaTypeDialog(QWidget *parent)
    : QDialog(parent)
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
    qDebug() << "emit mediaTypeChosen(0);";
    emit mediaTypeChosen(0);  // Notifica la MainWindow
    close();
}
void newMediaTypeDialog::onMusicButtonClicked() {
    qDebug() << "emit mediaTypeChosen(1);";
    emit mediaTypeChosen(1);  // Notifica la MainWindow
    close();
}
void newMediaTypeDialog::onPodcastButtonClicked() {
    qDebug() << "emit mediaTypeChosen(2);";
    emit mediaTypeChosen(2);  // Notifica la MainWindow
    close();
}
void newMediaTypeDialog::onCancelButtonClicked() {
    close();
}
