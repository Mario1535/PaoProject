#include "mediadetailwidget.h"
#include "ui_mediadetailwidget.h"
#include "textdetailwidget.h"

mediaDetailWidget::mediaDetailWidget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mediaDetailWidget)
{
    //connect(ui->editButton, &QPushButton::clicked, this, &mediaDetailWidget::onEditButtonClicked);
    //connect(ui->removeButton, &QPushButton::clicked, this, &mediaDetailWidget::onRemoveButtonClicked);
    //connect(ui->closeButton, &QPushButton::clicked, this, &mediaDetailWidget::onCloseButtonClicked);

    ui->setupUi(this);
}

mediaDetailWidget::~mediaDetailWidget()
{
    delete ui;
}

void mediaDetailWidget::loadMediaDetails(const AbstractMedia* media) {

    ConcreteVisitor visitor;
    media->accept(&visitor);

    ConcreteVisitor::Attributes attributes = visitor.getAttributes();

    ui->stackedWidget->setCurrentIndex(attributes.index);
    qDebug() << "index:" << attributes.index;

    ui->titleLabel->setText(QString::fromStdString(attributes.title));
    ui->authorLabel->setText(QString::fromStdString(attributes.author));
    ui->yearLabel->setText(QString::number(attributes.year));
    ui->durationLabel->setText(QString::number(attributes.duration) + " min");

    QPixmap image(QString::fromStdString(attributes.imagePath));
    ui->photoLabel->setPixmap(image.scaled(200, 200, Qt::KeepAspectRatio));

    switch (attributes.index) {
    case 0:
        ui->readerLabel->setText(QString::fromStdString(attributes.details.at("reader")));
        connect(ui->lyricsButton, &QPushButton::clicked, this, [=]() {
            onLyricsButtonClicked(media);
        });
        break;
    case 1:
        ui->albumLabel->setText(QString::fromStdString(attributes.details.at("album")));
        connect(ui->summaryButton, &QPushButton::clicked, this, [=]() {
            onSummaryButtonClicked(media);
        });
        break;
    case 2:
        ui->episodeLabel->setText(QString::fromStdString(attributes.details.at("episode")));
        ui->seasonLabel->setText(QString::fromStdString(attributes.details.at("season")));
        break;
    }

}

void mediaDetailWidget::onEditButtonClicked() {

}
void mediaDetailWidget::onRemoveButtonClicked() {

}
void mediaDetailWidget::onCloseButtonClicked() {
    close();
}

void mediaDetailWidget::onLyricsButtonClicked(const AbstractMedia* media) {
    auto *textWidget = new textDetailWidget(this);
    textWidget->showLyrics(media);
    textWidget->show();
}
void mediaDetailWidget::onSummaryButtonClicked(const AbstractMedia* media) {
    auto *textWidget = new textDetailWidget(this);
    textWidget->showSummary(media);
    textWidget->show();
}
