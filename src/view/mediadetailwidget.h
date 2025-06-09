#ifndef MEDIADETAILWIDGET_H
#define MEDIADETAILWIDGET_H

#include <QDialog>
#include "..\media\abstractMedia.h"
#include "..\media\music.h"
#include "..\media\podcast.h"
#include "..\media\audiobook.h"

namespace Ui {
    class mediaDetailWidget;
}

class mediaDetailWidget : public QDialog
{
    Q_OBJECT

public:
    explicit mediaDetailWidget(QWidget *parent = nullptr);
    ~mediaDetailWidget();

    void loadMediaDetails(AbstractMedia *media);  // Carica i dettagli di un media

private slots:
    void onEditButtonClicked();
    void onRemoveButtonClicked();
    void onCloseButtonClicked();

    void onLyricsButtonClicked();
    void onSummaryButtonClicked();

private:
    Ui::mediaDetailWidget *ui;
};

#endif // MEDIADETAILWIDGET_H
