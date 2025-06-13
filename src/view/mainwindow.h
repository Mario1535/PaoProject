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
#include <QScrollArea>
#include <QDebug>

#include "..\media\abstractmedia.h"
#include "mediawidget.h"
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
    //void closeEvent(QCloseEvent *event) override;  // Gestione della chiusura della finestra

private slots:
    // Slot per la barra di ricerca
    void onSearchTextChanged();

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

    // Metodi privati
    void refreshGridLayout();
    void clearGridLayout();
    void addWidgetInGrid(mediaWidget*);

    void loadMediaFromFile(const QString &filePath);  // Carica i media da un file DA IMPLEMENTARE
    AbstractMedia* getSelectedMedia() const;  // Restituisce il media selezionato  DA IMPLEMENTARES
    bool hasUnsavedChanges() const;  // Verifica se ci sono modifiche non salvate
    void saveChanges();  // Salva le modifiche

    QVBoxLayout *mainLayout;
    //QGridLayout *gridLayout;
    QLineEdit *searchBar;
    QLabel *statusLabel;
    //QScrollArea *scrollArea;
    Container *container;

    const short unsigned int maxColums = 3;
    short unsigned int colum = 0, row = 0;

    void setupUI();  // Helper function to organize UI setup
};

#endif // MAINWINDOW_H
