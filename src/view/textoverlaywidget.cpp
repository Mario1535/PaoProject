#include "textoverlaywidget.h"
#include "ui_textoverlaywidget.h"

textOverlayWidget::textOverlayWidget(const QString &text, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::textOverlayWidget)
{
    ui->setupUi(this);
    ui->textLabel->setText(text);
    connect(ui->closeButton, &QPushButton::clicked, this, &textOverlayWidget::onCloseButtonTriggered);
}

textOverlayWidget::~textOverlayWidget()
{
    delete ui;
}

void textOverlayWidget::onCloseButtonTriggered()
{

}
