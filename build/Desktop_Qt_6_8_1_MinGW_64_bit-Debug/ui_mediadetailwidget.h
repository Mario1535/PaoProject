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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mediaDetailWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *authorLabel;
    QPushButton *editButton;
    QLabel *durationLabel;
    QStackedWidget *stackedWidget;
    QWidget *audiobook;
    QVBoxLayout *verticalLayout;
    QLabel *readerLabel;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *summaryLabel;
    QWidget *podcast;
    QVBoxLayout *verticalLayout_5;
    QLabel *episodeLabel;
    QLabel *seasonLabel;
    QSpacerItem *verticalSpacer;
    QWidget *music;
    QVBoxLayout *verticalLayout_6;
    QLabel *albumLabel;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QTextBrowser *lyricLabel;
    QLabel *titleLabel;
    QLabel *yearLabel;
    QPushButton *removeButton;
    QPushButton *closeButton;
    QLabel *photoLabel;

    void setupUi(QWidget *mediaDetailWidget)
    {
        if (mediaDetailWidget->objectName().isEmpty())
            mediaDetailWidget->setObjectName("mediaDetailWidget");
        mediaDetailWidget->resize(587, 522);
        gridLayout = new QGridLayout(mediaDetailWidget);
        gridLayout->setObjectName("gridLayout");
        authorLabel = new QLabel(mediaDetailWidget);
        authorLabel->setObjectName("authorLabel");
        authorLabel->setFrameShape(QFrame::Shape::Box);

        gridLayout->addWidget(authorLabel, 1, 1, 1, 1);

        editButton = new QPushButton(mediaDetailWidget);
        editButton->setObjectName("editButton");

        gridLayout->addWidget(editButton, 5, 1, 1, 1);

        durationLabel = new QLabel(mediaDetailWidget);
        durationLabel->setObjectName("durationLabel");
        durationLabel->setFrameShape(QFrame::Shape::Box);

        gridLayout->addWidget(durationLabel, 3, 1, 1, 1);

        stackedWidget = new QStackedWidget(mediaDetailWidget);
        stackedWidget->setObjectName("stackedWidget");
        audiobook = new QWidget();
        audiobook->setObjectName("audiobook");
        verticalLayout = new QVBoxLayout(audiobook);
        verticalLayout->setObjectName("verticalLayout");
        readerLabel = new QLabel(audiobook);
        readerLabel->setObjectName("readerLabel");
        readerLabel->setFrameShape(QFrame::Shape::Box);

        verticalLayout->addWidget(readerLabel);

        widget = new QWidget(audiobook);
        widget->setObjectName("widget");
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        summaryLabel = new QTextBrowser(widget);
        summaryLabel->setObjectName("summaryLabel");

        verticalLayout_2->addWidget(summaryLabel);


        verticalLayout->addWidget(widget);

        stackedWidget->addWidget(audiobook);
        podcast = new QWidget();
        podcast->setObjectName("podcast");
        verticalLayout_5 = new QVBoxLayout(podcast);
        verticalLayout_5->setObjectName("verticalLayout_5");
        episodeLabel = new QLabel(podcast);
        episodeLabel->setObjectName("episodeLabel");
        episodeLabel->setFrameShape(QFrame::Shape::Box);

        verticalLayout_5->addWidget(episodeLabel);

        seasonLabel = new QLabel(podcast);
        seasonLabel->setObjectName("seasonLabel");
        seasonLabel->setFrameShape(QFrame::Shape::Box);

        verticalLayout_5->addWidget(seasonLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        stackedWidget->addWidget(podcast);
        music = new QWidget();
        music->setObjectName("music");
        verticalLayout_6 = new QVBoxLayout(music);
        verticalLayout_6->setObjectName("verticalLayout_6");
        albumLabel = new QLabel(music);
        albumLabel->setObjectName("albumLabel");
        albumLabel->setFrameShape(QFrame::Shape::Box);

        verticalLayout_6->addWidget(albumLabel);

        widget_2 = new QWidget(music);
        widget_2->setObjectName("widget_2");
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        lyricLabel = new QTextBrowser(widget_2);
        lyricLabel->setObjectName("lyricLabel");

        verticalLayout_3->addWidget(lyricLabel);


        verticalLayout_6->addWidget(widget_2);

        stackedWidget->addWidget(music);

        gridLayout->addWidget(stackedWidget, 4, 1, 1, 1);

        titleLabel = new QLabel(mediaDetailWidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setFrameShape(QFrame::Shape::Box);

        gridLayout->addWidget(titleLabel, 0, 1, 1, 1);

        yearLabel = new QLabel(mediaDetailWidget);
        yearLabel->setObjectName("yearLabel");
        yearLabel->setFrameShape(QFrame::Shape::Box);

        gridLayout->addWidget(yearLabel, 2, 1, 1, 1);

        removeButton = new QPushButton(mediaDetailWidget);
        removeButton->setObjectName("removeButton");

        gridLayout->addWidget(removeButton, 6, 1, 1, 1);

        closeButton = new QPushButton(mediaDetailWidget);
        closeButton->setObjectName("closeButton");

        gridLayout->addWidget(closeButton, 7, 1, 1, 1);

        photoLabel = new QLabel(mediaDetailWidget);
        photoLabel->setObjectName("photoLabel");
        photoLabel->setMinimumSize(QSize(300, 0));

        gridLayout->addWidget(photoLabel, 0, 0, 8, 1);


        retranslateUi(mediaDetailWidget);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(mediaDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *mediaDetailWidget)
    {
        mediaDetailWidget->setWindowTitle(QCoreApplication::translate("mediaDetailWidget", "Form", nullptr));
        authorLabel->setText(QString());
        editButton->setText(QCoreApplication::translate("mediaDetailWidget", "Edit", nullptr));
        durationLabel->setText(QString());
        readerLabel->setText(QString());
        episodeLabel->setText(QString());
        seasonLabel->setText(QString());
        albumLabel->setText(QString());
        titleLabel->setText(QString());
        yearLabel->setText(QString());
        removeButton->setText(QCoreApplication::translate("mediaDetailWidget", "Remove", nullptr));
        closeButton->setText(QCoreApplication::translate("mediaDetailWidget", "Close", nullptr));
        photoLabel->setText(QCoreApplication::translate("mediaDetailWidget", "photo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mediaDetailWidget: public Ui_mediaDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIADETAILWIDGET_H
