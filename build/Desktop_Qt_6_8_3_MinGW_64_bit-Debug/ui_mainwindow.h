/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionNew;
    QAction *actionEdit;
    QAction *actionRemove;
    QAction *actionHelp;
    QAction *actionNew_2;
    QAction *actionLoad_2;
    QAction *actionHelp_2;
    QAction *actionNew_3;
    QAction *actionLoad_3;
    QAction *actionHelp_3;
    QAction *actionNew_4;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Mariofy;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QCheckBox *Audiobook_checkBox;
    QCheckBox *Music_checkBox;
    QCheckBox *Podcast_checkBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_4;
    QWidget *gridContainer;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setWindowModality(Qt::WindowModality::NonModal);
        MainWindow->resize(800, 600);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName("actionLoad");
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        actionEdit = new QAction(MainWindow);
        actionEdit->setObjectName("actionEdit");
        actionRemove = new QAction(MainWindow);
        actionRemove->setObjectName("actionRemove");
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName("actionHelp");
        actionNew_2 = new QAction(MainWindow);
        actionNew_2->setObjectName("actionNew_2");
        actionLoad_2 = new QAction(MainWindow);
        actionLoad_2->setObjectName("actionLoad_2");
        actionHelp_2 = new QAction(MainWindow);
        actionHelp_2->setObjectName("actionHelp_2");
        actionNew_3 = new QAction(MainWindow);
        actionNew_3->setObjectName("actionNew_3");
        actionLoad_3 = new QAction(MainWindow);
        actionLoad_3->setObjectName("actionLoad_3");
        actionHelp_3 = new QAction(MainWindow);
        actionHelp_3->setObjectName("actionHelp_3");
        actionNew_4 = new QAction(MainWindow);
        actionNew_4->setObjectName("actionNew_4");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        Mariofy = new QLabel(centralwidget);
        Mariofy->setObjectName("Mariofy");
        Mariofy->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sans Serif Collection")});
        Mariofy->setFont(font);
        Mariofy->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(Mariofy);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        Audiobook_checkBox = new QCheckBox(centralwidget);
        Audiobook_checkBox->setObjectName("Audiobook_checkBox");

        horizontalLayout_2->addWidget(Audiobook_checkBox);

        Music_checkBox = new QCheckBox(centralwidget);
        Music_checkBox->setObjectName("Music_checkBox");

        horizontalLayout_2->addWidget(Music_checkBox);

        Podcast_checkBox = new QCheckBox(centralwidget);
        Podcast_checkBox->setObjectName("Podcast_checkBox");

        horizontalLayout_2->addWidget(Podcast_checkBox);


        gridLayout_3->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 784, 498));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_4->setObjectName("gridLayout_4");
        gridContainer = new QWidget(scrollAreaWidgetContents);
        gridContainer->setObjectName("gridContainer");
        verticalLayout_2 = new QVBoxLayout(gridContainer);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");

        verticalLayout_2->addLayout(gridLayout);


        gridLayout_4->addWidget(gridContainer, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_3->addWidget(scrollArea, 1, 0, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMinimumSize(QSize(500, 30));
        lineEdit->setMaximumSize(QSize(16777215, 16777215));
        lineEdit->setSizeIncrement(QSize(150, 0));
        lineEdit->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lineEdit, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Media library", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actionEdit->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        actionRemove->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        actionHelp->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        actionNew_2->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actionLoad_2->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        actionHelp_2->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        actionNew_3->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actionLoad_3->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        actionHelp_3->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        actionNew_4->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        Mariofy->setText(QCoreApplication::translate("MainWindow", "Mariofy", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Cerca con i filtri: ", nullptr));
        Audiobook_checkBox->setText(QCoreApplication::translate("MainWindow", "Audiobook", nullptr));
        Music_checkBox->setText(QCoreApplication::translate("MainWindow", "Music", nullptr));
        Podcast_checkBox->setText(QCoreApplication::translate("MainWindow", "Podcast", nullptr));
        lineEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
