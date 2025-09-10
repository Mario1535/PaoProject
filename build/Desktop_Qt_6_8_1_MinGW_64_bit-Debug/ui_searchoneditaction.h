/********************************************************************************
** Form generated from reading UI file 'searchoneditaction.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHONEDITACTION_H
#define UI_SEARCHONEDITACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_searchOnEditAction
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *searchLine;
    QGridLayout *gridLayout;

    void setupUi(QWidget *searchOnEditAction)
    {
        if (searchOnEditAction->objectName().isEmpty())
            searchOnEditAction->setObjectName("searchOnEditAction");
        searchOnEditAction->resize(354, 462);
        verticalLayoutWidget = new QWidget(searchOnEditAction);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, -10, 691, 711));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        searchLine = new QLineEdit(verticalLayoutWidget);
        searchLine->setObjectName("searchLine");

        verticalLayout->addWidget(searchLine);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");

        verticalLayout->addLayout(gridLayout);


        retranslateUi(searchOnEditAction);

        QMetaObject::connectSlotsByName(searchOnEditAction);
    } // setupUi

    void retranslateUi(QWidget *searchOnEditAction)
    {
        searchOnEditAction->setWindowTitle(QCoreApplication::translate("searchOnEditAction", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class searchOnEditAction: public Ui_searchOnEditAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHONEDITACTION_H
