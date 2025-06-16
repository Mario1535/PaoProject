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

    void loadMedia(ConcreteVisitor*);  // Carica i dati di un media esistente
    short int choice();
    void setIndex();

private slots:
    void onSaveButtonClicked();  // Slot per salvare le modifiche
    void onCancelButtonClicked();  // Slot per annullare
    void onChangePhotoButtonClicked();  // Slot per cambiare la foto

private:
    Ui::mediaEditor *ui;
    AbstractMedia *currentMedia;  // Puntatore al media corrente
    newMediaTypeDialog *dialog;
    QString photoPath;  // Percorso della foto
signals:
    void newMediaCreated(AbstractMedia*);
    void abortMediaCreation();

    //void setupUI();
};

#endif // MEDIAEDITOR_H
