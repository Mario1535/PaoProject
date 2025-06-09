#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMessageBox>
#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMainWindow>
#include <QList>
#include <QCloseEvent>
#include <QDebug>

#include "..\media\abstractmedia.h"  // Includi le tue classi media
#include "..\media\music.h"
#include "..\media\podcast.h"
#include "..\media\audiobook.h"

#include "mediawidget.h"    // Widget per visualizzare i media
#include "mediaeditor.h"      // Finestra di modifica/creazione media
#include "mediadetailwidget.h"  // Finestra dei dettagli del media

#include "..\container\container.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void loadMedia();  // Carica i media nella griglia

protected:
    void closeEvent(QCloseEvent *event) override;  // Gestione della chiusura della finestra

private slots:
    // Slot per la barra di ricerca
    void onSearchTextChanged(const QString &text);

    // Slot per i menu
    void onLoadActionTriggered();  // Carica i media
    void onNewActionTriggered();   // Aggiungi un nuovo media
    void onEditActionTriggered();  // Modifica un media esistente
    void onRemoveActionTriggered(); // Rimuovi un media esistente
    void onHelpActionTriggered();  // Mostra le scorciatoie

    // Slot per la visualizzazione dei dettagli di un media
    void onMediaClicked(AbstractMedia *media);

private:
    Ui::MainWindow *ui;

    // Lista dei media
    QList<AbstractMedia*> mediaList;

    // Metodi privati
    void clearGridLayout();  // Svuota la griglia
    void loadMediaFromFile(const QString &filePath);  // Carica i media da un file DA IMPLEMENTARE
    AbstractMedia* getSelectedMedia() const;  // Restituisce il media selezionato  DA IMPLEMENTARES
    bool hasUnsavedChanges() const;  // Verifica se ci sono modifiche non salvate
    void saveChanges();  // Salva le modifiche

    QVBoxLayout *mainLayout;
    QGridLayout *gridLayout;
    QLineEdit *searchBar;
    QLabel *statusLabel;

    void setupUI();  // Helper function to organize UI setup

    Container container;
};

#endif // MAINWINDOW_H
