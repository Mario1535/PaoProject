/********************************************************************************
** Form generated from reading UI file 'mediawidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIAWIDGET_H
#define UI_MEDIAWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mediaWidget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *photoLabel;
    QLabel *titleLabel;

    void setupUi(QWidget *mediaWidget)
    {
        if (mediaWidget->objectName().isEmpty())
            mediaWidget->setObjectName("mediaWidget");
        mediaWidget->resize(241, 300);
        verticalLayoutWidget = new QWidget(mediaWidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 241, 301));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        photoLabel = new QLabel(verticalLayoutWidget);
        photoLabel->setObjectName("photoLabel");

        verticalLayout->addWidget(photoLabel);

        titleLabel = new QLabel(verticalLayoutWidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(titleLabel);


        retranslateUi(mediaWidget);

        QMetaObject::connectSlotsByName(mediaWidget);
    } // setupUi

    void retranslateUi(QWidget *mediaWidget)
    {
        mediaWidget->setWindowTitle(QCoreApplication::translate("mediaWidget", "Form", nullptr));
        photoLabel->setText(QCoreApplication::translate("mediaWidget", "photo", nullptr));
        titleLabel->setText(QCoreApplication::translate("mediaWidget", "title", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mediaWidget: public Ui_mediaWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAWIDGET_H
