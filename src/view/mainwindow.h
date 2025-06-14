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

    void clearGridLayout();
    void loadMedia();  // Carica i media nella griglia
    void refreshGridLayout();
    void addWidgetInGrid(mediaWidget*, const AbstractMedia*);

    void editMedia(Container*, std::string);
    void removeMedia(Container*, std::string);

protected:
    //void closeEvent(QCloseEvent *event) override;  // Gestione della chiusura della finestra

private slots:
    // Slot per la barra di ricerca
    void onSearchTextChanged();

    // Slot per i menu
    void onLoadActionTriggered();  // Carica i media
    void onNewActionTriggered();   // Aggiungi un nuovo media
    void onEditActionTriggered();  // Cerca media da modificare
    void onRemoveActionTriggered(); // Cerca media da rimuovere
    void onHelpActionTriggered();  // Mostra le scorciatoie

    // Slot per la visualizzazione dei dettagli di un media
    void onMediaClicked(const AbstractMedia *media);

private:
    Ui::MainWindow *ui;


    void loadMediaFromFile(const QString &filePath);  // Carica i media da un file DA IMPLEMENTARE


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
