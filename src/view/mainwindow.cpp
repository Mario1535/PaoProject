#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "..\media\abstractmedia.h"  // Includi le tue classi media

#include "mediawidget.h"    // Widget per visualizzare i media
#include "newmediatypedialog.h"
#include "mediaeditor.h"      // Finestra di modifica/creazione media
#include "mediadetailwidget.h"
#include "..\container\container.h"

class mediaEditor;
class mediaWidget;
class mediaDetailWidget;
class mediaTextOverlay;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connessione della barra di ricerca
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::onSearchTextChanged);

    // Connessione dei menu
    connect(ui->actionLoad, &QAction::triggered, this, &MainWindow::onLoadActionTriggered);
    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::onNewActionTriggered);
    connect(ui->actionEdit, &QAction::triggered, this, &MainWindow::onEditActionTriggered);
    connect(ui->actionRemove, &QAction::triggered, this, &MainWindow::onRemoveActionTriggered);
    connect(ui->actionHelp, &QAction::triggered, this, &MainWindow::onHelpActionTriggered);

    // Set minimum window size
    setMinimumSize(600, 400);

    // Enable size grip in status bar
    statusBar()->setSizeGripEnabled(true);

    // Create central widget and main layout
    QWidget *centralWidget = new QWidget(this);
    mainLayout = new QVBoxLayout(centralWidget);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    setupUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUI()
{
    // 1. Create the Grid Layout (will expand)
    gridLayout = new QGridLayout();

    /*
    // Add widgets to grid layout (example)
    gridLayout->addWidget(new QLabel("Item 1"), 0, 0);
    gridLayout->addWidget(new QLabel("Item 2"), 0, 1);
    gridLayout->addWidget(new QLabel("Item 3"), 1, 0);
    gridLayout->addWidget(new QLabel("Item 4"), 1, 1);
    */

    // Carica i media
    loadMedia();

    // Make grid layout expand
    gridLayout->setColumnStretch(0, 1);
    gridLayout->setColumnStretch(1, 1);
    gridLayout->setRowStretch(0, 1);
    gridLayout->setRowStretch(1, 1);

    // 2. Create the Search Bar (fixed height)
    searchBar = new QLineEdit();
    searchBar->setPlaceholderText("Search...");
    searchBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    // 3. Create the Status Label (fixed height)
    statusLabel = new QLabel("Mariofy");
    statusLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    statusLabel->setAlignment(Qt::AlignCenter);

    // 4. Add all components to main layout
    mainLayout->addLayout(gridLayout, 1);  // Takes most space (stretch factor 1)
    mainLayout->addWidget(searchBar);      // Fixed height
    mainLayout->addWidget(statusLabel);    // Fixed height

    // Optional: Configure spacing
    mainLayout->setSpacing(10);
    mainLayout->setContentsMargins(15, 15, 15, 15);
}

//Popolo la main window con i mediawidget tramite funzione load
void MainWindow::loadMedia() {
    clearGridLayout();  // Svuota la griglia prima di ricaricare i media

    for (AbstractMedia *media : mediaList) {
        mediaWidget *mediawidget = new mediaWidget(media, this);
        connect(mediawidget, &mediaWidget::clicked, this, &MainWindow::onMediaClicked);
        ui->gridLayout->addWidget(mediawidget);
    }
}

//Mainwindow Menubar
void MainWindow::onLoadActionTriggered() {
    QString filePath = QFileDialog::getOpenFileName(this, "Carica media", "", "File di media (*.json)");
    if (!filePath.isEmpty()) {
        // Carica i media dal file
        loadMediaFromFile(filePath);
    }
}

void MainWindow::onNewActionTriggered() {
    newMediaTypeDialog *dialog = new newMediaTypeDialog(this);

    // Connessione del segnale
    connect(dialog, &newMediaTypeDialog::mediaTypeChosen, this, [this](AbstractMedia::mediaType type) {
        // Creazione dell'editor con il tipo selezionato
        mediaEditor editor(type, this);

        // Connessione del segnale di salvataggio al container
        connect(&editor, &mediaEditor::newMediaCreated,
                &container, &Container::add);  // Usa il nome esatto 'add' come nella tua classe

        // Mostra l'editor e ricarica i media se necessario
        if (editor.exec() == QDialog::Accepted) {
            loadMedia();
        }
    });

    dialog->show();  // Usa show() per finestra non modale
    // Oppure, se hai convertito newMediaTypeDialog in QDialog:
    // dialog->exec();  // Per finestra modale
    // dialog->deleteLater(); // Se allocato sull'heap
}

void MainWindow::onEditActionTriggered() {
    // Trova il media selezionato (ad esempio, tramite un indice o un puntatore)
    AbstractMedia *selectedMedia = getSelectedMedia();
    if (selectedMedia) {
        AbstractMedia::mediaType type = selectedMedia->getMediaType();
        mediaEditor editor(type, this);
        editor.loadMedia(selectedMedia);
        if (editor.exec() == QDialog::Accepted) {
            loadMedia();  // Ricarica i media
        }
    }
}

void MainWindow::onRemoveActionTriggered() {
    // Trova il media selezionato
    AbstractMedia *selectedMedia = getSelectedMedia();
    if (selectedMedia) {
        mediaList.removeOne(selectedMedia);
        delete selectedMedia;
        loadMedia();  // Ricarica i media
    }
}

void MainWindow::onHelpActionTriggered() {
    QMessageBox::information(this, "Aiuto", "Scorciatoie:\n"
                                            "Ctrl+N: Nuovo media\n"
                                            "Ctrl+E: Modifica media\n"
                                            "Ctrl+D: Rimuovi media\n"
                                            "Ctrl+S: Salva modifiche");
}



//Search bar
void MainWindow::onSearchTextChanged(const QString &text) {
    clearGridLayout();

    for (AbstractMedia *media : mediaList) {
        //modificato, converto in qstring e poi utilizzo contains
        if ((QString::fromStdString(media->getTitle())).contains(text, Qt::CaseInsensitive)) {
            mediaWidget *mediawidget = new mediaWidget(media, this);
            connect(mediawidget, &mediaWidget::clicked, this, &MainWindow::onMediaClicked);
            ui->gridLayout->addWidget(mediawidget);
        }
    }
}



//show media detail and clear grid layout
void MainWindow::onMediaClicked(AbstractMedia *media) {
    mediaDetailWidget *detailWidget = new mediaDetailWidget(this);
    detailWidget->loadMediaDetails(media);
    detailWidget->show();
}

void MainWindow::clearGridLayout() {
    QLayoutItem *item;
    while ((item = ui->gridLayout->takeAt(0))) {
        delete item->widget();
        delete item;
    }
}







//gestione chiusura mediaeditor
void MainWindow::closeEvent(QCloseEvent *event) {
    /*
    if (hasUnsavedChanges()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Modifiche non salvate",
                                      "Ci sono modifiche non salvate. Vuoi salvare prima di uscire?",
                                      QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (reply == QMessageBox::Save) {
            saveChanges();
        } else if (reply == QMessageBox::Cancel) {
            event->ignore();
            return;
        }
    }
    */
    event->accept();
}

/*
#include <QCloseEvent>
#include <QMessageBox>  // Optional - for confirmation dialogs
#include <QDebug>       // For debugging

// ... other existing code ...

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug() << "Attempting to close window";

    // Optional: Add confirmation dialog
    QMessageBox::StandardButton resBtn = QMessageBox::question(
        this, "Confirm Exit",
        tr("Are you sure you want to exit?\n"),
        QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
        QMessageBox::Yes);

    if (resBtn != QMessageBox::Yes) {
        event->ignore();  // Don't close the window
    } else {
        // Add any cleanup operations here
        saveSettings();    // Example: Save app settings
        stopThreads();     // Example: Stop any running threads

        event->accept();   // Accept the event and close
        qDebug() << "Window closed properly";
    }
}
*/

bool MainWindow::hasUnsavedChanges() const {
    // Implementa la logica per verificare se ci sono modifiche non salvate
    return false;
}

void MainWindow::saveChanges() {
    // Implementa la logica per salvare le modifiche
}




//DA IMPLEMENTARE

void MainWindow::loadMediaFromFile(const QString &filePath) {}
AbstractMedia* MainWindow::getSelectedMedia() const { return nullptr; }
