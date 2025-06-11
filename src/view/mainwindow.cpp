#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "..\media\abstractmedia.h"  // Includi le tue classi media

#include "mediawidget.h"    // Widget per visualizzare i media
#include "newmediatypedialog.h"
#include "mediaeditor.h"      // Finestra di modifica/creazione media
#include "mediadetailwidget.h"
#include "searchoneditaction.h"
#include "..\container\container.h"
#include "..\manager\mediamanager.h"
#include "..\visitor\concretevisitor.h"

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

    container = new Container();

    setupUI();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete container;
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


//new search edit remove load actions
void MainWindow::onNewActionTriggered() {
    mediaEditor *editor = new mediaEditor(this);
    newMediaTypeDialog *dialog = new newMediaTypeDialog(this);
    dialog->setFocus(); //faccio scegliere il tipo
    if (dialog->close() == QDialog::Accepted) { //se il tipo e' stato scelto faccio vedere l'editor
        editor->setFocus();
    }

    // Connessione del segnale di salvataggio al container
    AbstractMedia* media;
    connect(editor, &mediaEditor::newMediaCreated, [&media](AbstractMedia* m) {
        media = m;
    });

    mediaManager *manager = new mediaManager();
    if(manager->mediaCreated(media)){

    }
    else {

    }

    delete editor;
    delete dialog;
    delete manager;
}

void MainWindow::onSearchTextChanged() {
    clearGridLayout();

    std::string title = (ui->lineEdit->text()).toStdString();

    for (auto it = container->begin(); it != container->end(); ++it) {
        if ((QString::fromStdString((*it)->getTitle())).contains(QString::fromStdString(title), Qt::CaseInsensitive)) {
            mediaWidget *mediawidget = new mediaWidget(*it, this);
            ui->gridLayout->addWidget(mediawidget);

            std::string mediaTitle = (*it)->getTitle();

            //connettere a mediawidget
            connect(mediawidget, &mediaWidget::clicked, this, [this, mediaTitle]() {
                emit onEditMediaClicked(mediaTitle);
                close();
            });
        }
    }
}

void MainWindow::onEditActionTriggered() {
    mediaEditor *editor = new mediaEditor();
    ConcreteVisitor *visitor = new ConcreteVisitor();
    mediaManager *manager = new mediaManager();
    searchOnEditAction *search = new searchOnEditAction();

    search->setFocus();
    search->searchMediaToEdit(container);

    std::string title;
    connect(search, &searchOnEditAction::onEditMediaClicked, [&title](std::string t) {
        title = t;
    });

    if (manager->mediaEdited(container, title, visitor)) {
        editor->loadMedia(visitor);
        editor->setFocus();

        //refreshGrid();
    } else {

    }

    delete editor;
    delete visitor;
    delete manager;
    delete search;
}

void MainWindow::onRemoveActionTriggered() {
    searchOnEditAction *search = new searchOnEditAction();
    mediaManager *manager = new mediaManager();

    search->setFocus();
    search->searchMediaToEdit(container);

    std::string title;
    connect(search, &searchOnEditAction::onEditMediaClicked, [&title](std::string t) {
        title = t;
    });

    if (manager->mediaDeleted(container, title)) {

        //refreshGrid();
    } else {

    }

    delete manager;
    delete search;
}

void MainWindow::onLoadActionTriggered() {
    QString filePath = QFileDialog::getOpenFileName(this, "Carica media", "", "File di media (*.json)");
    if (!filePath.isEmpty()) {
        // Carica i media dal file
        //loadMediaFromFile(filePath);
    }
}

void MainWindow::onHelpActionTriggered() {
    QMessageBox::information(this, "Aiuto", "Scorciatoie:\n"
                                            "Ctrl+N: Nuovo media\n"
                                            "Ctrl+E: Modifica media\n"
                                            "Ctrl+D: Rimuovi media\n"
                                            "Ctrl+S: Salva modifiche");
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

bool MainWindow::hasUnsavedChanges() const {
    // Implementa la logica per verificare se ci sono modifiche non salvate
    return false;
}

void MainWindow::saveChanges() {
    // Implementa la logica per salvare le modifiche
}




//DA IMPLEMENTARE
/*
void MainWindow::loadMediaFromFile(const QString &filePath) {}
AbstractMedia* MainWindow::getSelectedMedia() const { return nullptr; }
*/
