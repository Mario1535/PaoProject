#include "searchoneditaction.h"
#include "ui_searchoneditaction.h"

#include <string>
#include "..\container\container.h"
#include "mediawidget.h"
#include "mainwindow.h"

searchOnEditAction::searchOnEditAction(MainWindow* mainWindow, QWidget *parent)
    : QDialog(parent), mainWindow(mainWindow)
    , ui(new Ui::searchOnEditAction)
{
    colum = 0;
    row = 0;
    ui->setupUi(this);
}

searchOnEditAction::~searchOnEditAction()
{
    delete ui;
}

void searchOnEditAction::searchMediaToEdit(Container* container){

    std::string title = (ui->searchLine->text()).toStdString();

    for (auto it = container->begin(); it != container->end(); ++it) {
        if ((QString::fromStdString((*it)->getTitle())).contains(QString::fromStdString(title), Qt::CaseInsensitive)) {
            mediaWidget *mediawidget = new mediaWidget(*it, this);
            addWidgetInGrid(mediawidget, *it);

            std::string mediaTitle = (*it)->getTitle();

            connect(mediawidget, &mediaWidget::mediaClicked, this, [this, mediaTitle]() {
                emit onEditMediaClicked(mediaTitle);
                close();
            });
        }
    }
}



//metodi
void searchOnEditAction::clearGridLayout() {
    QLayoutItem *item;
    while ((item = ui->gridLayout->takeAt(0))) {
        delete item->widget();
        delete item;
    }
}

void searchOnEditAction::loadMedia() {
    const AbstractMedia* media;
    for (auto it = container->begin(); it != container->end(); ++it) {
        mediaWidget* widget = new mediaWidget(*it, this);
        media = *it;
        addWidgetInGrid(widget, media);
    }
}

void searchOnEditAction::refreshGridLayout() {
    colum = 0;
    row = 0;
    clearGridLayout();
    loadMedia();
}

void searchOnEditAction::addWidgetInGrid(mediaWidget* widget, const AbstractMedia* media) {
    if(colum >= maxColums){
        colum = 0;
        row++;
    }
    ui->gridLayout->addWidget(widget, row, colum);
    connect(widget, &mediaWidget::mediaClicked, this, [=]() {
        mainWindow->editMedia(container, media->getTitle());
    });
    qDebug() << "media aggiunto alla griglia";
    colum++;
    ui->gridLayout->update();
}
