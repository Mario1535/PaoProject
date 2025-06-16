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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mediaEditor
{
public:
    QGridLayout *gridLayout;
    QLabel *yearLabel;
    QLineEdit *durationLine;
    QLabel *photoLabel;
    QLabel *titleLabel;
    QLineEdit *authorLine;
    QPushButton *photoButton;
    QLabel *durationLabel;
    QLineEdit *titleLine;
    QPushButton *closeButton;
    QPushButton *saveButton;
    QLineEdit *yearLine;
    QLabel *authorLabel;
    QStackedWidget *stackedWidget;
    QWidget *audiobook;
    QGridLayout *gridLayout_4;
    QLabel *readerLabel;
    QLineEdit *readerLine;
    QLabel *summaryLabel;
    QWidget *widget;
    QTextEdit *summaryText;
    QWidget *music;
    QGridLayout *gridLayout_2;
    QLabel *albumLabel;
    QLineEdit *albumLine;
    QLabel *lyricsLabel;
    QWidget *widget_2;
    QTextEdit *lyricsText;
    QWidget *podcast;
    QGridLayout *gridLayout_3;
    QLabel *episodeLabel;
    QLineEdit *episodeLine;
    QLabel *sesaonLabel;
    QLineEdit *seasonLine;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *mediaEditor)
    {
        if (mediaEditor->objectName().isEmpty())
            mediaEditor->setObjectName("mediaEditor");
        mediaEditor->resize(420, 570);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mediaEditor->sizePolicy().hasHeightForWidth());
        mediaEditor->setSizePolicy(sizePolicy);
        mediaEditor->setMinimumSize(QSize(420, 570));
        mediaEditor->setMaximumSize(QSize(420, 570));
        gridLayout = new QGridLayout(mediaEditor);
        gridLayout->setObjectName("gridLayout");
        yearLabel = new QLabel(mediaEditor);
        yearLabel->setObjectName("yearLabel");

        gridLayout->addWidget(yearLabel, 3, 0, 1, 1);

        durationLine = new QLineEdit(mediaEditor);
        durationLine->setObjectName("durationLine");

        gridLayout->addWidget(durationLine, 4, 1, 1, 1);

        photoLabel = new QLabel(mediaEditor);
        photoLabel->setObjectName("photoLabel");

        gridLayout->addWidget(photoLabel, 0, 0, 1, 1);

        titleLabel = new QLabel(mediaEditor);
        titleLabel->setObjectName("titleLabel");

        gridLayout->addWidget(titleLabel, 1, 0, 1, 1);

        authorLine = new QLineEdit(mediaEditor);
        authorLine->setObjectName("authorLine");

        gridLayout->addWidget(authorLine, 2, 1, 1, 1);

        photoButton = new QPushButton(mediaEditor);
        photoButton->setObjectName("photoButton");

        gridLayout->addWidget(photoButton, 0, 1, 1, 1);

        durationLabel = new QLabel(mediaEditor);
        durationLabel->setObjectName("durationLabel");

        gridLayout->addWidget(durationLabel, 4, 0, 1, 1);

        titleLine = new QLineEdit(mediaEditor);
        titleLine->setObjectName("titleLine");

        gridLayout->addWidget(titleLine, 1, 1, 1, 1);

        closeButton = new QPushButton(mediaEditor);
        closeButton->setObjectName("closeButton");

        gridLayout->addWidget(closeButton, 6, 0, 1, 1);

        saveButton = new QPushButton(mediaEditor);
        saveButton->setObjectName("saveButton");

        gridLayout->addWidget(saveButton, 6, 1, 1, 1);

        yearLine = new QLineEdit(mediaEditor);
        yearLine->setObjectName("yearLine");

        gridLayout->addWidget(yearLine, 3, 1, 1, 1);

        authorLabel = new QLabel(mediaEditor);
        authorLabel->setObjectName("authorLabel");

        gridLayout->addWidget(authorLabel, 2, 0, 1, 1);

        stackedWidget = new QStackedWidget(mediaEditor);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setMinimumSize(QSize(0, 0));
        audiobook = new QWidget();
        audiobook->setObjectName("audiobook");
        gridLayout_4 = new QGridLayout(audiobook);
        gridLayout_4->setObjectName("gridLayout_4");
        readerLabel = new QLabel(audiobook);
        readerLabel->setObjectName("readerLabel");

        gridLayout_4->addWidget(readerLabel, 0, 0, 1, 1);

        readerLine = new QLineEdit(audiobook);
        readerLine->setObjectName("readerLine");

        gridLayout_4->addWidget(readerLine, 0, 1, 1, 1);

        summaryLabel = new QLabel(audiobook);
        summaryLabel->setObjectName("summaryLabel");

        gridLayout_4->addWidget(summaryLabel, 1, 0, 1, 1);

        widget = new QWidget(audiobook);
        widget->setObjectName("widget");
        summaryText = new QTextEdit(widget);
        summaryText->setObjectName("summaryText");
        summaryText->setGeometry(QRect(0, 0, 311, 261));

        gridLayout_4->addWidget(widget, 1, 1, 1, 1);

        stackedWidget->addWidget(audiobook);
        music = new QWidget();
        music->setObjectName("music");
        gridLayout_2 = new QGridLayout(music);
        gridLayout_2->setObjectName("gridLayout_2");
        albumLabel = new QLabel(music);
        albumLabel->setObjectName("albumLabel");

        gridLayout_2->addWidget(albumLabel, 0, 0, 1, 1);

        albumLine = new QLineEdit(music);
        albumLine->setObjectName("albumLine");

        gridLayout_2->addWidget(albumLine, 0, 1, 1, 1);

        lyricsLabel = new QLabel(music);
        lyricsLabel->setObjectName("lyricsLabel");

        gridLayout_2->addWidget(lyricsLabel, 1, 0, 1, 1);

        widget_2 = new QWidget(music);
        widget_2->setObjectName("widget_2");
        lyricsText = new QTextEdit(widget_2);
        lyricsText->setObjectName("lyricsText");
        lyricsText->setGeometry(QRect(0, 0, 331, 271));

        gridLayout_2->addWidget(widget_2, 1, 1, 1, 1);

        stackedWidget->addWidget(music);
        podcast = new QWidget();
        podcast->setObjectName("podcast");
        gridLayout_3 = new QGridLayout(podcast);
        gridLayout_3->setObjectName("gridLayout_3");
        episodeLabel = new QLabel(podcast);
        episodeLabel->setObjectName("episodeLabel");

        gridLayout_3->addWidget(episodeLabel, 1, 0, 1, 1);

        episodeLine = new QLineEdit(podcast);
        episodeLine->setObjectName("episodeLine");

        gridLayout_3->addWidget(episodeLine, 1, 1, 1, 1);

        sesaonLabel = new QLabel(podcast);
        sesaonLabel->setObjectName("sesaonLabel");

        gridLayout_3->addWidget(sesaonLabel, 0, 0, 1, 1);

        seasonLine = new QLineEdit(podcast);
        seasonLine->setObjectName("seasonLine");

        gridLayout_3->addWidget(seasonLine, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 2, 1, 1, 1);

        stackedWidget->addWidget(podcast);

        gridLayout->addWidget(stackedWidget, 5, 0, 1, 2);


        retranslateUi(mediaEditor);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mediaEditor);
    } // setupUi

    void retranslateUi(QWidget *mediaEditor)
    {
        mediaEditor->setWindowTitle(QCoreApplication::translate("mediaEditor", "Create new media", nullptr));
        yearLabel->setText(QCoreApplication::translate("mediaEditor", "Year", nullptr));
        photoLabel->setText(QCoreApplication::translate("mediaEditor", "Image", nullptr));
        titleLabel->setText(QCoreApplication::translate("mediaEditor", "Title", nullptr));
        photoButton->setText(QCoreApplication::translate("mediaEditor", "Add image", nullptr));
        durationLabel->setText(QCoreApplication::translate("mediaEditor", "Duration", nullptr));
        closeButton->setText(QCoreApplication::translate("mediaEditor", "Close", nullptr));
        saveButton->setText(QCoreApplication::translate("mediaEditor", "Save", nullptr));
        authorLabel->setText(QCoreApplication::translate("mediaEditor", "Author", nullptr));
        readerLabel->setText(QCoreApplication::translate("mediaEditor", "Reader", nullptr));
        summaryLabel->setText(QCoreApplication::translate("mediaEditor", "Summary", nullptr));
        albumLabel->setText(QCoreApplication::translate("mediaEditor", "Album", nullptr));
        lyricsLabel->setText(QCoreApplication::translate("mediaEditor", "Lyrics", nullptr));
        episodeLabel->setText(QCoreApplication::translate("mediaEditor", "Episode", nullptr));
        sesaonLabel->setText(QCoreApplication::translate("mediaEditor", "Season", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mediaEditor: public Ui_mediaEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAEDITOR_H
