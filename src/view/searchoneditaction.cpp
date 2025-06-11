#include "searchoneditaction.h"
#include "ui_searchoneditaction.h"

#include <string>
#include "..\container\container.h"
#include "..\media\abstractmedia.h"
#include "mediawidget.h"

searchOnEditAction::searchOnEditAction(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::searchOnEditAction)
{
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
            ui->gridLayout->addWidget(mediawidget);

            std::string mediaTitle = (*it)->getTitle();

            connect(mediawidget, &mediaWidget::clicked, this, [this, mediaTitle]() {
                emit onEditMediaClicked(mediaTitle);
                close();
            });
        }
    }
}
