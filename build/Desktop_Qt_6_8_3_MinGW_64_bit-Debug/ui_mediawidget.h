/********************************************************************************
** Form generated from reading UI file 'mediawidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
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
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *photoLabel;
    QLabel *titleLabel;

    void setupUi(QWidget *mediaWidget)
    {
        if (mediaWidget->objectName().isEmpty())
            mediaWidget->setObjectName("mediaWidget");
        mediaWidget->resize(215, 265);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mediaWidget->sizePolicy().hasHeightForWidth());
        mediaWidget->setSizePolicy(sizePolicy);
        widget = new QWidget(mediaWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 211, 261));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        photoLabel = new QLabel(widget);
        photoLabel->setObjectName("photoLabel");
        photoLabel->setMaximumSize(QSize(200, 200));
        photoLabel->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        verticalLayout->addWidget(photoLabel);

        titleLabel = new QLabel(widget);
        titleLabel->setObjectName("titleLabel");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(20);
        sizePolicy1.setHeightForWidth(titleLabel->sizePolicy().hasHeightForWidth());
        titleLabel->setSizePolicy(sizePolicy1);
        titleLabel->setMinimumSize(QSize(50, 20));
        titleLabel->setMaximumSize(QSize(16777215, 20));
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        titleLabel->setWordWrap(true);

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
