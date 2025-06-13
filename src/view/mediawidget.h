#ifndef MEDIAWIDGET_H
#define MEDIAWIDGET_H

#include <QWidget>
#include "..\media\abstractMedia.h"
#include "..\media\music.h"
#include "..\media\podcast.h"
#include "..\media\audiobook.h"

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
    void clicked(const AbstractMedia *media);  // Segnale emesso quando il widget viene cliccato

protected:
    void mousePressEvent(QMouseEvent *event) override;  // Gestisce il clic del mouse

private:
    Ui::mediaWidget *ui;
    const AbstractMedia *media;  // Puntatore al media associato
};

#endif // MEDIAWIDGET_H
