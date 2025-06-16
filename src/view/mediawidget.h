#ifndef MEDIAWIDGET_H
#define MEDIAWIDGET_H

#include <QWidget>
#include "../media/abstractmedia.h"
#include "../visitor/concretevisitor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mediaWidget; }
QT_END_NAMESPACE

class mediaWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mediaWidget(ConcreteVisitor *visitor, QWidget *parent = nullptr);
    ~mediaWidget();

signals:
    void mediaClicked(ConcreteVisitor* visitor);

protected:
    void mousePressEvent(QMouseEvent *event) override;
private:
    Ui::mediaWidget *ui;
    ConcreteVisitor *visitor;
};

#endif // MEDIAWIDGET_H
