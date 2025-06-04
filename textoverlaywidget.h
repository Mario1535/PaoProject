#ifndef TEXTOVERLAYWIDGET_H
#define TEXTOVERLAYWIDGET_H

#include <QDialog>
#include "abstractMedia.h"
#include "music.h"
#include "podcast.h"
#include "audiobook.h"

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
