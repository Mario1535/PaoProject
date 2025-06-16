/********************************************************************************
** Form generated from reading UI file 'textoverlaywidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTOVERLAYWIDGET_H
#define UI_TEXTOVERLAYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_textOverlayWidget
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *textLabel;
    QPushButton *closeButton;

    void setupUi(QWidget *textOverlayWidget)
    {
        if (textOverlayWidget->objectName().isEmpty())
            textOverlayWidget->setObjectName("textOverlayWidget");
        textOverlayWidget->resize(304, 300);
        scrollArea = new QScrollArea(textOverlayWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(-1, 0, 301, 301));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 299, 299));
        verticalLayoutWidget = new QWidget(scrollAreaWidgetContents);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 301, 301));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textLabel = new QLabel(verticalLayoutWidget);
        textLabel->setObjectName("textLabel");

        verticalLayout->addWidget(textLabel);

        closeButton = new QPushButton(verticalLayoutWidget);
        closeButton->setObjectName("closeButton");

        verticalLayout->addWidget(closeButton);

        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(textOverlayWidget);

        QMetaObject::connectSlotsByName(textOverlayWidget);
    } // setupUi

    void retranslateUi(QWidget *textOverlayWidget)
    {
        textOverlayWidget->setWindowTitle(QCoreApplication::translate("textOverlayWidget", "Form", nullptr));
        textLabel->setText(QCoreApplication::translate("textOverlayWidget", "TextLabel", nullptr));
        closeButton->setText(QCoreApplication::translate("textOverlayWidget", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class textOverlayWidget: public Ui_textOverlayWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTOVERLAYWIDGET_H
