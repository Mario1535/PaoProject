#include "mediawidget.h"
#include "ui_mediawidget.h"

mediaWidget::mediaWidget(ConcreteVisitor *visitor, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mediaWidget)
    , visitor(visitor)
{
    ui->setupUi(this);
    qDebug() << "Titolo ricevuto:" << QString::fromStdString(visitor->getAttributes().title);
    ui->titleLabel->setText(QString::fromStdString(visitor->getAttributes().title));
    ui->photoLabel->setPixmap(QPixmap(QString::fromStdString(visitor->getAttributes().imagePath)).scaled(200, 200, Qt::KeepAspectRatio));
}

mediaWidget::~mediaWidget()
{
    delete ui;
}

void mediaWidget::mousePressEvent(QMouseEvent *event) {
    emit mediaClicked(visitor);
    QWidget::mousePressEvent(event);
}
