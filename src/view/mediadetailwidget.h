#ifndef MEDIADETAILWIDGET_H
#define MEDIADETAILWIDGET_H

#include <string>
#include <QDialog>
#include "../media/abstractmedia.h"
#include "../visitor/concretevisitor.h"
#include "textdetailwidget.h"
#include "../container/container.h"

class MainWindow;

namespace Ui {
    class mediaDetailWidget;
}

class mediaDetailWidget : public QDialog
{
    Q_OBJECT

public:
    explicit mediaDetailWidget(MainWindow*, Container*, std::string, QWidget *parent = nullptr);
    ~mediaDetailWidget();

    void loadMediaDetails(const AbstractMedia*);  // Carica i dettagli di un media

private slots:
    void onEditButtonClicked();
    void onRemoveButtonClicked();
    void onCloseButtonClicked();

    void onSummaryButtonClicked(const AbstractMedia*);
    void onLyricsButtonClicked(const AbstractMedia*);

private:
    std::string title;
    Container* container;
    MainWindow* mainWindow;
    Ui::mediaDetailWidget *ui;
    ConcreteVisitor* visitor;
    textDetailWidget* text;
};

#endif // MEDIADETAILWIDGET_H
