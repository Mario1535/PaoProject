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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mediaDetailWidget
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *pixmapLabel;
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
    QPushButton *summaryButton;
    QWidget *podcast;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *episodeLabel;
    QLabel *seasonLabel;
    QWidget *music;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *albumLabel;
    QPushButton *lyricsButton;
    QPushButton *editButton;
    QPushButton *removeButton;
    QPushButton *closeButton;

    void setupUi(QWidget *mediaDetailWidget)
    {
        if (mediaDetailWidget->objectName().isEmpty())
            mediaDetailWidget->setObjectName("mediaDetailWidget");
        mediaDetailWidget->resize(496, 463);
        horizontalLayoutWidget = new QWidget(mediaDetailWidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(-1, -1, 491, 451));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pixmapLabel = new QLabel(horizontalLayoutWidget);
        pixmapLabel->setObjectName("pixmapLabel");
        pixmapLabel->setMinimumSize(QSize(250, 0));

        horizontalLayout->addWidget(pixmapLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(horizontalLayoutWidget);
        titleLabel->setObjectName("titleLabel");

        verticalLayout->addWidget(titleLabel);

        authorLabel = new QLabel(horizontalLayoutWidget);
        authorLabel->setObjectName("authorLabel");

        verticalLayout->addWidget(authorLabel);

        yearLabel = new QLabel(horizontalLayoutWidget);
        yearLabel->setObjectName("yearLabel");

        verticalLayout->addWidget(yearLabel);

        durationLabel = new QLabel(horizontalLayoutWidget);
        durationLabel->setObjectName("durationLabel");

        verticalLayout->addWidget(durationLabel);

        stackedWidget = new QStackedWidget(horizontalLayoutWidget);
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

        summaryButton = new QPushButton(verticalLayoutWidget);
        summaryButton->setObjectName("summaryButton");

        verticalLayout_2->addWidget(summaryButton);

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

        lyricsButton = new QPushButton(verticalLayoutWidget_2);
        lyricsButton->setObjectName("lyricsButton");

        verticalLayout_3->addWidget(lyricsButton);

        stackedWidget->addWidget(music);

        verticalLayout->addWidget(stackedWidget);

        editButton = new QPushButton(horizontalLayoutWidget);
        editButton->setObjectName("editButton");

        verticalLayout->addWidget(editButton);

        removeButton = new QPushButton(horizontalLayoutWidget);
        removeButton->setObjectName("removeButton");

        verticalLayout->addWidget(removeButton);

        closeButton = new QPushButton(horizontalLayoutWidget);
        closeButton->setObjectName("closeButton");

        verticalLayout->addWidget(closeButton);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(mediaDetailWidget);

        QMetaObject::connectSlotsByName(mediaDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *mediaDetailWidget)
    {
        mediaDetailWidget->setWindowTitle(QCoreApplication::translate("mediaDetailWidget", "Form", nullptr));
        pixmapLabel->setText(QCoreApplication::translate("mediaDetailWidget", "pixmap", nullptr));
        titleLabel->setText(QCoreApplication::translate("mediaDetailWidget", "title", nullptr));
        authorLabel->setText(QCoreApplication::translate("mediaDetailWidget", "author", nullptr));
        yearLabel->setText(QCoreApplication::translate("mediaDetailWidget", "year", nullptr));
        durationLabel->setText(QCoreApplication::translate("mediaDetailWidget", "duration", nullptr));
        readerLabel->setText(QCoreApplication::translate("mediaDetailWidget", "reader", nullptr));
        summaryButton->setText(QCoreApplication::translate("mediaDetailWidget", "read summary", nullptr));
        episodeLabel->setText(QCoreApplication::translate("mediaDetailWidget", "episode", nullptr));
        seasonLabel->setText(QCoreApplication::translate("mediaDetailWidget", "season", nullptr));
        albumLabel->setText(QCoreApplication::translate("mediaDetailWidget", "album", nullptr));
        lyricsButton->setText(QCoreApplication::translate("mediaDetailWidget", "read lyrics", nullptr));
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
