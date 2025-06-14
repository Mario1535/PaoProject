#ifndef MEDIAWIDGET_H
#define MEDIAWIDGET_H

#include <QWidget>
#include "..\media\abstractMedia.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mediaWidget; }
QT_END_NAMESPACE

class mediaWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mediaWidget(const AbstractMedia *media, QWidget *parent = nullptr);
    ~mediaWidget();

signals:
    void mediaClicked(const AbstractMedia *media);

protected:
    void mousePressEvent(QMouseEvent *event) override;
private:
    Ui::mediaWidget *ui;
    const AbstractMedia *media;
};

#endif // MEDIAWIDGET_H
