#ifndef SEARCHONEDITACTION_H
#define SEARCHONEDITACTION_H

#include <QWidget>
#include <string>
#include "../container/container.h"
#include "../media/abstractmedia.h"

namespace Ui {
class searchOnEditAction;
}

class searchOnEditAction : public QWidget
{
    Q_OBJECT

public:
    explicit searchOnEditAction(QWidget *parent = nullptr);
    ~searchOnEditAction();

public slots:
    void searchMediaToEdit(Container*);

private:
    Ui::searchOnEditAction *ui;
    Container* container;

signals:
    void onEditMediaClicked(std::string);

};

#endif // SEARCHONEDITACTION_H
