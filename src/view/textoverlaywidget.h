#ifndef TEXTOVERLAYWIDGET_H
#define TEXTOVERLAYWIDGET_H

#include <QDialog>
#include "..\media\abstractMedia.h"
#include "..\media\music.h"
#include "..\media\podcast.h"
#include "..\media\audiobook.h"

namespace Ui {
class textOverlayWidget;
}

class textOverlayWidget : public QDialog
{
    Q_OBJECT

public:
    explicit textOverlayWidget(const QString &text, QWidget *parent = nullptr);
    ~textOverlayWidget();

private slots:
    void onCloseButtonTriggered();

private:
    Ui::textOverlayWidget *ui;
};

#endif // TEXTOVERLAYWIDGET_H
