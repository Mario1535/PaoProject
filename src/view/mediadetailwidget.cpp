#include "mediadetailwidget.h"
#include "ui_mediadetailwidget.h"
#include "mainwindow.h"

mediaDetailWidget::mediaDetailWidget(MainWindow* mainWin, Container* c, std::string t, QWidget *parent)
    : QDialog(parent) , title(t), container(c), mainWindow(mainWin)
    , ui(new Ui::mediaDetailWidget)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("../../assets/window_icons/mediadetailwidget_icon.png"));

    connect(ui->editButton, &QPushButton::clicked, this, &mediaDetailWidget::onEditButtonClicked);
    connect(ui->removeButton, &QPushButton::clicked, this, &mediaDetailWidget::onRemoveButtonClicked);
    connect(ui->closeButton, &QPushButton::clicked, this, &mediaDetailWidget::onCloseButtonClicked);
}

mediaDetailWidget::~mediaDetailWidget()
{
    delete ui;
}

void mediaDetailWidget::loadMediaDetails(ConcreteVisitor* visitor) {

    ConcreteVisitor::Attributes attributes = visitor->getAttributes();

    ui->stackedWidget->setCurrentIndex(attributes.index);
    qDebug() << "index:" << attributes.index;

    ui->titleLabel->setText(QString::fromStdString(attributes.title));
    ui->authorLabel->setText(QString::fromStdString(attributes.author));
    ui->yearLabel->setText(QString::number(attributes.year));
    ui->durationLabel->setText(QString::number(attributes.duration) + " min");

    QPixmap image(QString::fromStdString(attributes.imagePath));
    ui->photoLabel->setPixmap(image.scaled(350, 350, Qt::KeepAspectRatio));

    switch (attributes.index) {
    case 0:
        ui->readerLabel->setText(QString::fromStdString(attributes.details.at("reader")));
        ui->summaryLabel->setText(QString::fromStdString(attributes.details.at("summary")));
        break;
    case 1:
        ui->albumLabel->setText(QString::fromStdString(attributes.details.at("album")));
        ui->lyricLabel->setText(QString::fromStdString(attributes.details.at("lyrics")));
        break;
    case 2:
        ui->episodeLabel->setText(QString::fromStdString(attributes.details.at("episode")));
        ui->seasonLabel->setText(QString::fromStdString(attributes.details.at("season")));
        break;
    }

}

void mediaDetailWidget::onEditButtonClicked() {
    qDebug() << "edit media button";
    mainWindow->editMedia(container, title);
    close();
}
void mediaDetailWidget::onRemoveButtonClicked() {
    qDebug() << "remove media button";
    mainWindow->removeMedia(container, title);
    close();
}
void mediaDetailWidget::onCloseButtonClicked() {
    close();
}
