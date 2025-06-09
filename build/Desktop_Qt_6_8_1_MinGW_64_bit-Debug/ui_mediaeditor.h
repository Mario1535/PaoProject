/********************************************************************************
** Form generated from reading UI file 'mediaeditor.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIAEDITOR_H
#define UI_MEDIAEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mediaEditor
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *photoLabel;
    QPushButton *photoButton;
    QHBoxLayout *horizontalLayout_5;
    QLabel *titleLabel;
    QLineEdit *titleLine;
    QHBoxLayout *horizontalLayout_4;
    QLabel *authorLabel;
    QLineEdit *authorLine;
    QHBoxLayout *horizontalLayout_3;
    QLabel *yearLabel;
    QSpinBox *yearLine;
    QHBoxLayout *horizontalLayout;
    QLabel *durationLabel;
    QSpinBox *durationLine;
    QStackedWidget *stackedWidget;
    QWidget *audiobook;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_11;
    QLabel *readerLabel;
    QLineEdit *readerLine;
    QHBoxLayout *horizontalLayout_10;
    QLabel *summaryLabel;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTextEdit *summaryText;
    QWidget *music;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *albumLabel;
    QLineEdit *albumLine;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lyricsLabel;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QTextEdit *lyricsText;
    QWidget *podcast;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *episodeLabel;
    QLineEdit *episodeLine;
    QHBoxLayout *horizontalLayout_8;
    QLabel *seasonLabel;
    QLineEdit *seasonLine;
    QPushButton *saveButton;
    QPushButton *closeButton;

    void setupUi(QWidget *mediaEditor)
    {
        if (mediaEditor->objectName().isEmpty())
            mediaEditor->setObjectName("mediaEditor");
        mediaEditor->resize(487, 647);
        verticalLayoutWidget = new QWidget(mediaEditor);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 481, 641));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        photoLabel = new QLabel(verticalLayoutWidget);
        photoLabel->setObjectName("photoLabel");

        horizontalLayout_2->addWidget(photoLabel);

        photoButton = new QPushButton(verticalLayoutWidget);
        photoButton->setObjectName("photoButton");

        horizontalLayout_2->addWidget(photoButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        titleLabel = new QLabel(verticalLayoutWidget);
        titleLabel->setObjectName("titleLabel");

        horizontalLayout_5->addWidget(titleLabel);

        titleLine = new QLineEdit(verticalLayoutWidget);
        titleLine->setObjectName("titleLine");

        horizontalLayout_5->addWidget(titleLine);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        authorLabel = new QLabel(verticalLayoutWidget);
        authorLabel->setObjectName("authorLabel");

        horizontalLayout_4->addWidget(authorLabel);

        authorLine = new QLineEdit(verticalLayoutWidget);
        authorLine->setObjectName("authorLine");

        horizontalLayout_4->addWidget(authorLine);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        yearLabel = new QLabel(verticalLayoutWidget);
        yearLabel->setObjectName("yearLabel");

        horizontalLayout_3->addWidget(yearLabel);

        yearLine = new QSpinBox(verticalLayoutWidget);
        yearLine->setObjectName("yearLine");

        horizontalLayout_3->addWidget(yearLine);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        durationLabel = new QLabel(verticalLayoutWidget);
        durationLabel->setObjectName("durationLabel");

        horizontalLayout->addWidget(durationLabel);

        durationLine = new QSpinBox(verticalLayoutWidget);
        durationLine->setObjectName("durationLine");

        horizontalLayout->addWidget(durationLine);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget = new QStackedWidget(verticalLayoutWidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setMaximumSize(QSize(16777215, 16777215));
        audiobook = new QWidget();
        audiobook->setObjectName("audiobook");
        verticalLayoutWidget_4 = new QWidget(audiobook);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(0, 0, 481, 251));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        readerLabel = new QLabel(verticalLayoutWidget_4);
        readerLabel->setObjectName("readerLabel");

        horizontalLayout_11->addWidget(readerLabel);

        readerLine = new QLineEdit(verticalLayoutWidget_4);
        readerLine->setObjectName("readerLine");

        horizontalLayout_11->addWidget(readerLine);


        verticalLayout_4->addLayout(horizontalLayout_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        summaryLabel = new QLabel(verticalLayoutWidget_4);
        summaryLabel->setObjectName("summaryLabel");

        horizontalLayout_10->addWidget(summaryLabel);

        scrollArea = new QScrollArea(verticalLayoutWidget_4);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 434, 217));
        summaryText = new QTextEdit(scrollAreaWidgetContents);
        summaryText->setObjectName("summaryText");
        summaryText->setGeometry(QRect(3, 3, 431, 211));
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_10->addWidget(scrollArea);


        verticalLayout_4->addLayout(horizontalLayout_10);

        stackedWidget->addWidget(audiobook);
        music = new QWidget();
        music->setObjectName("music");
        verticalLayoutWidget_2 = new QWidget(music);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 481, 251));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        albumLabel = new QLabel(verticalLayoutWidget_2);
        albumLabel->setObjectName("albumLabel");

        horizontalLayout_7->addWidget(albumLabel);

        albumLine = new QLineEdit(verticalLayoutWidget_2);
        albumLine->setObjectName("albumLine");

        horizontalLayout_7->addWidget(albumLine);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        lyricsLabel = new QLabel(verticalLayoutWidget_2);
        lyricsLabel->setObjectName("lyricsLabel");

        horizontalLayout_6->addWidget(lyricsLabel);

        scrollArea_2 = new QScrollArea(verticalLayoutWidget_2);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 455, 217));
        lyricsText = new QTextEdit(scrollAreaWidgetContents_2);
        lyricsText->setObjectName("lyricsText");
        lyricsText->setGeometry(QRect(3, 0, 451, 221));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_6->addWidget(scrollArea_2);


        verticalLayout_2->addLayout(horizontalLayout_6);

        stackedWidget->addWidget(music);
        podcast = new QWidget();
        podcast->setObjectName("podcast");
        verticalLayoutWidget_3 = new QWidget(podcast);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(0, 0, 481, 251));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        episodeLabel = new QLabel(verticalLayoutWidget_3);
        episodeLabel->setObjectName("episodeLabel");

        horizontalLayout_9->addWidget(episodeLabel);

        episodeLine = new QLineEdit(verticalLayoutWidget_3);
        episodeLine->setObjectName("episodeLine");

        horizontalLayout_9->addWidget(episodeLine);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        seasonLabel = new QLabel(verticalLayoutWidget_3);
        seasonLabel->setObjectName("seasonLabel");

        horizontalLayout_8->addWidget(seasonLabel);

        seasonLine = new QLineEdit(verticalLayoutWidget_3);
        seasonLine->setObjectName("seasonLine");

        horizontalLayout_8->addWidget(seasonLine);


        verticalLayout_3->addLayout(horizontalLayout_8);

        stackedWidget->addWidget(podcast);

        verticalLayout->addWidget(stackedWidget);

        saveButton = new QPushButton(verticalLayoutWidget);
        saveButton->setObjectName("saveButton");

        verticalLayout->addWidget(saveButton);

        closeButton = new QPushButton(verticalLayoutWidget);
        closeButton->setObjectName("closeButton");

        verticalLayout->addWidget(closeButton);


        retranslateUi(mediaEditor);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mediaEditor);
    } // setupUi

    void retranslateUi(QWidget *mediaEditor)
    {
        mediaEditor->setWindowTitle(QCoreApplication::translate("mediaEditor", "Form", nullptr));
        photoLabel->setText(QCoreApplication::translate("mediaEditor", "image", nullptr));
        photoButton->setText(QCoreApplication::translate("mediaEditor", "Edit image", nullptr));
        titleLabel->setText(QCoreApplication::translate("mediaEditor", "title", nullptr));
        authorLabel->setText(QCoreApplication::translate("mediaEditor", "autor", nullptr));
        yearLabel->setText(QCoreApplication::translate("mediaEditor", "year", nullptr));
        durationLabel->setText(QCoreApplication::translate("mediaEditor", "duration", nullptr));
        readerLabel->setText(QCoreApplication::translate("mediaEditor", "reader", nullptr));
        summaryLabel->setText(QCoreApplication::translate("mediaEditor", "summary", nullptr));
        albumLabel->setText(QCoreApplication::translate("mediaEditor", "album", nullptr));
        lyricsLabel->setText(QCoreApplication::translate("mediaEditor", "lyric", nullptr));
        episodeLabel->setText(QCoreApplication::translate("mediaEditor", "episode", nullptr));
        seasonLabel->setText(QCoreApplication::translate("mediaEditor", "season", nullptr));
        saveButton->setText(QCoreApplication::translate("mediaEditor", "Save", nullptr));
        closeButton->setText(QCoreApplication::translate("mediaEditor", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mediaEditor: public Ui_mediaEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAEDITOR_H
