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
    QVBoxLayout *verticalLayout_2;
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
        newMediaTypeDialog->resize(365, 251);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(newMediaTypeDialog->sizePolicy().hasHeightForWidth());
        newMediaTypeDialog->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(newMediaTypeDialog);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        textBrowser = new QTextBrowser(newMediaTypeDialog);
        textBrowser->setObjectName("textBrowser");

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        audiobookButton = new QPushButton(newMediaTypeDialog);
        audiobookButton->setObjectName("audiobookButton");

        horizontalLayout->addWidget(audiobookButton);

        musicButton = new QPushButton(newMediaTypeDialog);
        musicButton->setObjectName("musicButton");

        horizontalLayout->addWidget(musicButton);

        podcastButton = new QPushButton(newMediaTypeDialog);
        podcastButton->setObjectName("podcastButton");

        horizontalLayout->addWidget(podcastButton);

        cancelButton = new QPushButton(newMediaTypeDialog);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(newMediaTypeDialog);

        QMetaObject::connectSlotsByName(newMediaTypeDialog);
    } // setupUi

    void retranslateUi(QWidget *newMediaTypeDialog)
    {
        newMediaTypeDialog->setWindowTitle(QCoreApplication::translate("newMediaTypeDialog", "Media type", nullptr));
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
