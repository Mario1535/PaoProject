/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QScrollArea>
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
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *gridContainer;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
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
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 776, 489));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        gridContainer = new QWidget(scrollAreaWidgetContents);
        gridContainer->setObjectName("gridContainer");
        gridContainer->setGeometry(QRect(9, 9, 781, 471));
        sizePolicy1.setHeightForWidth(gridContainer->sizePolicy().hasHeightForWidth());
        gridContainer->setSizePolicy(sizePolicy1);
        gridLayoutWidget = new QWidget(gridContainer);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 10, 761, 451));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(label, 0, Qt::AlignmentFlag::AlignHCenter);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        lineEdit->setMinimumSize(QSize(500, 30));
        lineEdit->setMaximumSize(QSize(16777215, 16777215));
        lineEdit->setSizeIncrement(QSize(150, 0));
        lineEdit->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(lineEdit, 0, Qt::AlignmentFlag::AlignHCenter);


        verticalLayout_2->addLayout(verticalLayout);

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
        label->setText(QCoreApplication::translate("MainWindow", "title", nullptr));
        lineEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
