/********************************************************************************
** Form generated from reading UI file 'textdetailwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTDETAILWIDGET_H
#define UI_TEXTDETAILWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_textDetailWidget
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *widget;
    QLabel *textLabel;

    void setupUi(QWidget *textDetailWidget)
    {
        if (textDetailWidget->objectName().isEmpty())
            textDetailWidget->setObjectName("textDetailWidget");
        textDetailWidget->resize(294, 365);
        scrollArea = new QScrollArea(textDetailWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 0, 291, 361));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 289, 359));
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 291, 361));
        textLabel = new QLabel(widget);
        textLabel->setObjectName("textLabel");
        textLabel->setGeometry(QRect(0, 0, 281, 351));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(textDetailWidget);

        QMetaObject::connectSlotsByName(textDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *textDetailWidget)
    {
        textDetailWidget->setWindowTitle(QCoreApplication::translate("textDetailWidget", "Form", nullptr));
        textLabel->setText(QCoreApplication::translate("textDetailWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class textDetailWidget: public Ui_textDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTDETAILWIDGET_H
