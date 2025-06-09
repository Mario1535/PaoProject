/********************************************************************************
** Form generated from reading UI file 'newmediatypedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWMEDIATYPEDIALOG_H
#define UI_NEWMEDIATYPEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newMediaTypeDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QPushButton *audiobookButton;
    QPushButton *musicButton;
    QPushButton *podcastButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *newMediaTypeDialog)
    {
        if (newMediaTypeDialog->objectName().isEmpty())
            newMediaTypeDialog->setObjectName("newMediaTypeDialog");
        newMediaTypeDialog->resize(442, 300);
        verticalLayoutWidget = new QWidget(newMediaTypeDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 441, 301));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(verticalLayoutWidget);
        textBrowser->setObjectName("textBrowser");

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        audiobookButton = new QPushButton(verticalLayoutWidget);
        audiobookButton->setObjectName("audiobookButton");

        horizontalLayout->addWidget(audiobookButton);

        musicButton = new QPushButton(verticalLayoutWidget);
        musicButton->setObjectName("musicButton");

        horizontalLayout->addWidget(musicButton);

        podcastButton = new QPushButton(verticalLayoutWidget);
        podcastButton->setObjectName("podcastButton");

        horizontalLayout->addWidget(podcastButton);

        cancelButton = new QPushButton(verticalLayoutWidget);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(newMediaTypeDialog);

        QMetaObject::connectSlotsByName(newMediaTypeDialog);
    } // setupUi

    void retranslateUi(QWidget *newMediaTypeDialog)
    {
        newMediaTypeDialog->setWindowTitle(QCoreApplication::translate("newMediaTypeDialog", "Form", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("newMediaTypeDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:700;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-ind"
                        "ent:0px; font-weight:700;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">scegli il tipo del tuo nuovo media</span></p></body></html>", nullptr));
        audiobookButton->setText(QCoreApplication::translate("newMediaTypeDialog", "Audiobook", nullptr));
        musicButton->setText(QCoreApplication::translate("newMediaTypeDialog", "Music", nullptr));
        podcastButton->setText(QCoreApplication::translate("newMediaTypeDialog", "Podcast", nullptr));
        cancelButton->setText(QCoreApplication::translate("newMediaTypeDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newMediaTypeDialog: public Ui_newMediaTypeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWMEDIATYPEDIALOG_H
