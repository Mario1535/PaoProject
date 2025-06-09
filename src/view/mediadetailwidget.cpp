#include "mediadetailwidget.h"
#include "ui_mediadetailwidget.h"

mediaDetailWidget::mediaDetailWidget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mediaDetailWidget)
{
    ui->setupUi(this);

    //connssione pulsanti
    connect(ui->editButton, &QPushButton::clicked, this, &mediaDetailWidget::onEditButtonClicked);
    connect(ui->removeButton, &QPushButton::clicked, this, &mediaDetailWidget::onRemoveButtonClicked);
    connect(ui->closeButton, &QPushButton::clicked, this, &mediaDetailWidget::onCloseButtonClicked);
    //pulsanti dentro stacked widget
    connect(ui->closeButton, &QPushButton::clicked, this, &mediaDetailWidget::onLyricsButtonClicked);
    connect(ui->closeButton, &QPushButton::clicked, this, &mediaDetailWidget::onSummaryButtonClicked);
}

mediaDetailWidget::~mediaDetailWidget()
{
    delete ui;
}

void mediaDetailWidget::loadMediaDetails(AbstractMedia *media) {
    ui->titleLabel->setText("Titolo: " + (QString::fromStdString(media->getTitle())));
    ui->authorLabel->setText("Autore: " + (QString::fromStdString(media->getAuthor())));
    ui->yearLabel->setText("Anno: " + QString::number(media->getYear()));
    ui->durationLabel->setText("Durata: " + QString::number(media->getDuration()));

    if (auto audiobook = dynamic_cast<Audiobook*>(media)) {
        ui->stackedWidget->setCurrentIndex(0);  // Audiolibro
        ui->readerLabel->setText(QString::fromStdString(audiobook->getAuthor()));
        //summary button
    } else if (auto music = dynamic_cast<Music*>(media)) {
        ui->stackedWidget->setCurrentIndex(1);  // Musica
        ui->albumLabel->setText(QString::fromStdString(music->getAlbum()));
        //lyrics button
    } else if (auto podcast = dynamic_cast<Podcast*>(media)) {
        ui->stackedWidget->setCurrentIndex(2);  // Podcast
        ui->episodeLabel->setText(QString::fromStdString(podcast->getEpisode()));
        ui->seasonLabel->setText(QString::fromStdString(podcast->getSeason()));
    }
}

void mediaDetailWidget::onEditButtonClicked() {}
void mediaDetailWidget::onRemoveButtonClicked() {}
void mediaDetailWidget::onCloseButtonClicked() {}

void mediaDetailWidget::onLyricsButtonClicked() {}
void mediaDetailWidget::onSummaryButtonClicked() {}
