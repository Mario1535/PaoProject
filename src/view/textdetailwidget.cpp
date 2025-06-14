#include "textdetailwidget.h"
#include "ui_textdetailwidget.h"
#include "../visitor/concretevisitor.h"

textDetailWidget::textDetailWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::textDetailWidget)
{
    ui->textLabel->setWordWrap(true);
    ui->textLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    ui->setupUi(this);
}

textDetailWidget::~textDetailWidget()
{
    delete ui;
}

void textDetailWidget::showLyrics(const AbstractMedia* media){
    ConcreteVisitor visitor;
    media->accept(&visitor);

    ConcreteVisitor::Attributes attributes = visitor.getAttributes();

    ui->textLabel->setText(QString::fromStdString(attributes.details.at("lyrics")));
}
void textDetailWidget::showSummary(const AbstractMedia* media){
    ConcreteVisitor visitor;
    media->accept(&visitor);

    ConcreteVisitor::Attributes attributes = visitor.getAttributes();

    ui->textLabel->setText(QString::fromStdString(attributes.details.at("summary")));
}
