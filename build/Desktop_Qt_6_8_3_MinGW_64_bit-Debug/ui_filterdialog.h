/********************************************************************************
** Form generated from reading UI file 'filterdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERDIALOG_H
#define UI_FILTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Filterdialog
{
public:
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_2;

    void setupUi(QWidget *Filterdialog)
    {
        if (Filterdialog->objectName().isEmpty())
            Filterdialog->setObjectName("Filterdialog");
        Filterdialog->resize(97, 89);
        verticalLayout = new QVBoxLayout(Filterdialog);
        verticalLayout->setObjectName("verticalLayout");
        checkBox = new QCheckBox(Filterdialog);
        checkBox->setObjectName("checkBox");

        verticalLayout->addWidget(checkBox);

        checkBox_3 = new QCheckBox(Filterdialog);
        checkBox_3->setObjectName("checkBox_3");

        verticalLayout->addWidget(checkBox_3);

        checkBox_2 = new QCheckBox(Filterdialog);
        checkBox_2->setObjectName("checkBox_2");

        verticalLayout->addWidget(checkBox_2);


        retranslateUi(Filterdialog);

        QMetaObject::connectSlotsByName(Filterdialog);
    } // setupUi

    void retranslateUi(QWidget *Filterdialog)
    {
        Filterdialog->setWindowTitle(QCoreApplication::translate("Filterdialog", "Form", nullptr));
        checkBox->setText(QCoreApplication::translate("Filterdialog", "Audiobook", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Filterdialog", "Music", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Filterdialog", "Podcast", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Filterdialog: public Ui_Filterdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERDIALOG_H
