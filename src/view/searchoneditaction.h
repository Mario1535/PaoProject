#ifndef SEARCHONEDITACTION_H
#define SEARCHONEDITACTION_H

#include <QDialog>
#include <string>
#include "mediawidget.h"
#include "../container/container.h"

class MainWindow;

namespace Ui {
class searchOnEditAction;
}

class searchOnEditAction : public QDialog
{
    Q_OBJECT

public:
    explicit searchOnEditAction(MainWindow* mainWindow, QWidget *parent = nullptr);
    ~searchOnEditAction();

public slots:
    void searchMediaToEdit(Container*);

private:
    void clearGridLayout();
    void loadMedia();
    void refreshGridLayout();
    void addWidgetInGrid(mediaWidget*, const AbstractMedia*);

    MainWindow* mainWindow;
    Ui::searchOnEditAction *ui;
    Container* container;

    short unsigned int maxColums = 2;
    short unsigned int colum, row;

signals:
    void onEditMediaClicked(std::string);

};

#endif // SEARCHONEDITACTION_H
