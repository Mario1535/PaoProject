#ifndef MEDIADETAILWIDGET_H
#define MEDIADETAILWIDGET_H

#include <QDialog>
#include "../media/abstractmedia.h"
#include "../visitor/concretevisitor.h"
#include "textdetailwidget.h"

namespace Ui {
    class mediaDetailWidget;
}

class mediaDetailWidget : public QDialog
{
    Q_OBJECT

public:
    explicit mediaDetailWidget(QWidget *parent = nullptr);
    ~mediaDetailWidget();

    void loadMediaDetails(const AbstractMedia*);  // Carica i dettagli di un media

private slots:
    void onEditButtonClicked();
    void onRemoveButtonClicked();
    void onCloseButtonClicked();

    void onSummaryButtonClicked(const AbstractMedia*);
    void onLyricsButtonClicked(const AbstractMedia*);

private:
    Ui::mediaDetailWidget *ui;
    ConcreteVisitor* visitor;
    textDetailWidget* text;
};

#endif // MEDIADETAILWIDGET_H
