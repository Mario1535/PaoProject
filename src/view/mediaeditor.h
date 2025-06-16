#ifndef MEDIAEDITOR_H
#define MEDIAEDITOR_H

#include <QDialog>
#include "../media/abstractmedia.h"
#include "../visitor/concretevisitor.h"
#include "newmediatypedialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mediaEditor; }
QT_END_NAMESPACE

class mediaEditor : public QDialog
{
    Q_OBJECT

public:
    explicit mediaEditor(QWidget *parent = nullptr);
    ~mediaEditor();

    void loadMedia(ConcreteVisitor*);
    short int choice();
    void setIndex();

private slots:
    void onSaveButtonClicked();
    void onCancelButtonClicked();
    void onChangePhotoButtonClicked();

private:
    Ui::mediaEditor *ui;
    AbstractMedia *currentMedia;
    newMediaTypeDialog *dialog;
    QString photoPath;
signals:
    void newMediaCreated(AbstractMedia*);
    void abortMediaCreation();

    //void setupUI();
};

#endif // MEDIAEDITOR_H
