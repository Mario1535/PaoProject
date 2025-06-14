#include "mediawidget.h"
#include "ui_mediawidget.h"

mediaWidget::mediaWidget(const AbstractMedia *media, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mediaWidget)
    , media(media)
{
    ui->setupUi(this);
    qDebug() << "Titolo ricevuto:" << QString::fromStdString(media->getTitle());
    ui->titleLabel->setText(QString::fromStdString(media->getTitle()));
    ui->photoLabel->setPixmap(QPixmap(QString::fromStdString(media->getImagePath())).scaled(200, 200, Qt::KeepAspectRatio));
}

mediaWidget::~mediaWidget()
{
    delete ui;
}

void mediaWidget::mousePressEvent(QMouseEvent *event) {
    emit mediaClicked(media);
    QWidget::mousePressEvent(event);
}
