#ifndef TEXTDETAILWIDGET_H
#define TEXTDETAILWIDGET_H

#include <QWidget>
#include "../media/abstractmedia.h"

namespace Ui {
class textDetailWidget;
}

class textDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit textDetailWidget(QWidget *parent = nullptr);
    ~textDetailWidget();

public slots:
    void showLyrics(const AbstractMedia*);
    void showSummary(const AbstractMedia*);

private:
    Ui::textDetailWidget *ui;
};

#endif // TEXTDETAILWIDGET_H
