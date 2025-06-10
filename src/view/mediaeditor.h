#ifndef MEDIAEDITOR_H
#define MEDIAEDITOR_H

#include <QDialog>
#include "..\media\abstractMedia.h"
#include "..\media\music.h"
#include "..\media\podcast.h"
#include "..\media\audiobook.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mediaEditor; }
QT_END_NAMESPACE

class mediaEditor : public QDialog
{
    Q_OBJECT

public:
    explicit mediaEditor(QWidget *parent = nullptr);
    ~mediaEditor();

    void loadMedia(Visitor*);  // Carica i dati di un media esistente
    AbstractMedia* getMedia();  // Restituisce il media modificato/creato

private slots:
    void onSaveButtonClicked();  // Slot per salvare le modifiche
    void onCancelButtonClicked();  // Slot per annullare
    void onChangePhotoButtonClicked();  // Slot per cambiare la foto

private:
    Ui::mediaEditor *ui;
    AbstractMedia *currentMedia;  // Puntatore al media corrente
    QString photoPath;  // Percorso della foto
signals:
    void newMediaCreated(const AbstractMedia*);

    //void setupUI();
};

#endif // MEDIAEDITOR_H
