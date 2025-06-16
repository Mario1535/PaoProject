/********************************************************************************
** Form generated from reading UI file 'mediadetailwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIADETAILWIDGET_H
#define UI_MEDIADETAILWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mediaDetailWidget
{
public:
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *photoLabel;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *authorLabel;
    QLabel *yearLabel;
    QLabel *durationLabel;
    QStackedWidget *stackedWidget;
    QWidget *audiobook;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *readerLabel;
    QWidget *widget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *summaryLabel;
    QWidget *podcast;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *episodeLabel;
    QLabel *seasonLabel;
    QWidget *music;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *albumLabel;
    QWidget *widget_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *lyricLabel;
    QPushButton *editButton;
    QPushButton *removeButton;
    QPushButton *closeButton;

    void setupUi(QWidget *mediaDetailWidget)
    {
        if (mediaDetailWidget->objectName().isEmpty())
            mediaDetailWidget->setObjectName("mediaDetailWidget");
        mediaDetailWidget->resize(496, 463);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mediaDetailWidget->sizePolicy().hasHeightForWidth());
        mediaDetailWidget->setSizePolicy(sizePolicy);
        verticalLayout_5 = new QVBoxLayout(mediaDetailWidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        photoLabel = new QLabel(mediaDetailWidget);
        photoLabel->setObjectName("photoLabel");
        photoLabel->setMinimumSize(QSize(250, 0));

        horizontalLayout->addWidget(photoLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(mediaDetailWidget);
        titleLabel->setObjectName("titleLabel");

        verticalLayout->addWidget(titleLabel);

        authorLabel = new QLabel(mediaDetailWidget);
        authorLabel->setObjectName("authorLabel");

        verticalLayout->addWidget(authorLabel);

        yearLabel = new QLabel(mediaDetailWidget);
        yearLabel->setObjectName("yearLabel");

        verticalLayout->addWidget(yearLabel);

        durationLabel = new QLabel(mediaDetailWidget);
        durationLabel->setObjectName("durationLabel");

        verticalLayout->addWidget(durationLabel);

        stackedWidget = new QStackedWidget(mediaDetailWidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setMaximumSize(QSize(16777215, 16777215));
        stackedWidget->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        audiobook = new QWidget();
        audiobook->setObjectName("audiobook");
        verticalLayoutWidget = new QWidget(audiobook);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 231, 231));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        readerLabel = new QLabel(verticalLayoutWidget);
        readerLabel->setObjectName("readerLabel");

        verticalLayout_2->addWidget(readerLabel);

        widget = new QWidget(verticalLayoutWidget);
        widget->setObjectName("widget");
        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 0, 231, 111));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 229, 109));
        summaryLabel = new QLabel(scrollAreaWidgetContents);
        summaryLabel->setObjectName("summaryLabel");
        summaryLabel->setGeometry(QRect(0, 0, 231, 111));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(widget);

        stackedWidget->addWidget(audiobook);
        podcast = new QWidget();
        podcast->setObjectName("podcast");
        verticalLayoutWidget_3 = new QWidget(podcast);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(0, 0, 231, 231));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        episodeLabel = new QLabel(verticalLayoutWidget_3);
        episodeLabel->setObjectName("episodeLabel");

        verticalLayout_4->addWidget(episodeLabel);

        seasonLabel = new QLabel(verticalLayoutWidget_3);
        seasonLabel->setObjectName("seasonLabel");

        verticalLayout_4->addWidget(seasonLabel);

        stackedWidget->addWidget(podcast);
        music = new QWidget();
        music->setObjectName("music");
        verticalLayoutWidget_2 = new QWidget(music);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 231, 231));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        albumLabel = new QLabel(verticalLayoutWidget_2);
        albumLabel->setObjectName("albumLabel");

        verticalLayout_3->addWidget(albumLabel);

        widget_2 = new QWidget(verticalLayoutWidget_2);
        widget_2->setObjectName("widget_2");
        scrollArea_2 = new QScrollArea(widget_2);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setGeometry(QRect(0, 0, 231, 111));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(-131, 0, 229, 109));
        lyricLabel = new QLabel(scrollAreaWidgetContents_2);
        lyricLabel->setObjectName("lyricLabel");
        lyricLabel->setGeometry(QRect(0, 0, 231, 111));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_3->addWidget(widget_2);

        stackedWidget->addWidget(music);

        verticalLayout->addWidget(stackedWidget);

        editButton = new QPushButton(mediaDetailWidget);
        editButton->setObjectName("editButton");

        verticalLayout->addWidget(editButton);

        removeButton = new QPushButton(mediaDetailWidget);
        removeButton->setObjectName("removeButton");

        verticalLayout->addWidget(removeButton);

        closeButton = new QPushButton(mediaDetailWidget);
        closeButton->setObjectName("closeButton");

        verticalLayout->addWidget(closeButton);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_5->addLayout(horizontalLayout);


        retranslateUi(mediaDetailWidget);

        QMetaObject::connectSlotsByName(mediaDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *mediaDetailWidget)
    {
        mediaDetailWidget->setWindowTitle(QCoreApplication::translate("mediaDetailWidget", "Media", nullptr));
        photoLabel->setText(QCoreApplication::translate("mediaDetailWidget", "pixmap", nullptr));
        titleLabel->setText(QCoreApplication::translate("mediaDetailWidget", "title", nullptr));
        authorLabel->setText(QCoreApplication::translate("mediaDetailWidget", "author", nullptr));
        yearLabel->setText(QCoreApplication::translate("mediaDetailWidget", "year", nullptr));
        durationLabel->setText(QCoreApplication::translate("mediaDetailWidget", "duration", nullptr));
        readerLabel->setText(QCoreApplication::translate("mediaDetailWidget", "reader", nullptr));
        summaryLabel->setText(QCoreApplication::translate("mediaDetailWidget", "summary", nullptr));
        episodeLabel->setText(QCoreApplication::translate("mediaDetailWidget", "episode", nullptr));
        seasonLabel->setText(QCoreApplication::translate("mediaDetailWidget", "season", nullptr));
        albumLabel->setText(QCoreApplication::translate("mediaDetailWidget", "album", nullptr));
        lyricLabel->setText(QCoreApplication::translate("mediaDetailWidget", "lyric", nullptr));
        editButton->setText(QCoreApplication::translate("mediaDetailWidget", "edit", nullptr));
        removeButton->setText(QCoreApplication::translate("mediaDetailWidget", "remove", nullptr));
        closeButton->setText(QCoreApplication::translate("mediaDetailWidget", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mediaDetailWidget: public Ui_mediaDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIADETAILWIDGET_H
