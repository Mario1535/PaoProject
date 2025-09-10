#ifndef MEDIAEDITOR_H
#define MEDIAEDITOR_H

#include <QDialog>
#include "../media/abstractmedia.h"
#include "../visitor/concretevisitor.h"
#include "newmediatypedialog.h"
#include "../container/container.h"

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
    bool checkName(QString, QString = "");
    void setContainer(Container*);
    void setCurrentMedia(const AbstractMedia* media);

private slots:
    void onSaveButtonClicked();
    void onCancelButtonClicked();
    void onChangePhotoButtonClicked();

private:
    Ui::mediaEditor *ui;
    const AbstractMedia* currentMedia;
    newMediaTypeDialog *dialog;
    QString photoPath;
    Container* container = nullptr;
signals:
    void newMediaCreated(AbstractMedia*);
    void abortMediaCreation();

    //void setupUI();
};

#endif // MEDIAEDITOR_H
