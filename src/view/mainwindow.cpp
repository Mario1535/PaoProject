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

    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::onSearchTextChanged);

    connect(ui->actionLoad, &QAction::triggered, this, &MainWindow::onLoadActionTriggered);
    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::onNewActionTriggered);
    connect(ui->actionEdit, &QAction::triggered, this, &MainWindow::onEditActionTriggered);
    connect(ui->actionRemove, &QAction::triggered, this, &MainWindow::onRemoveActionTriggered);
    connect(ui->actionHelp, &QAction::triggered, this, &MainWindow::onHelpActionTriggered);

    setMinimumSize(600, 400);
    statusBar()->setSizeGripEnabled(true);

    ui->label->setText("Mariofy");
    ui->label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    ui->label->setAlignment(Qt::AlignCenter);
    ui->lineEdit->setPlaceholderText("Cerca...");
    ui->lineEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    ui->gridContainer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);\
    //ui->gridContainer->setLayout(ui->gridLayout);
    ui->scrollArea->setWidgetResizable(true);
    //ui->scrollArea->setWidget(ui->gridContainer);

    container = new Container();

    //setupUI();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete container;
}

void MainWindow::setupUI()
{

}


//new search edit remove load actions
void MainWindow::onNewActionTriggered() {
    newMediaTypeDialog *dialog = new newMediaTypeDialog(this);
    mediaWidget *mediawidget;

    dialog->setFocus();
    dialog->exec();

    mediaEditor *editor = new mediaEditor(this);
    editor->show();
    connect(editor, &mediaEditor::newMediaCreated, this, [this, &mediawidget](AbstractMedia* media) {

        /*
        if (!media) {
            qDebug() << "Errore: media è nullptr!";
            return;
        }
        */

        mediaManager *manager = new mediaManager();
        if(manager->mediaCreated(media, container)){
            statusBar()->showMessage("Media salvato!", 3000);
            mediawidget = new mediaWidget(media, this);
        }
        else {
            statusBar()->showMessage("Media NON salvato", 3000);
        }
        delete manager;
    });

    editor->exec();
    delete editor;
    delete dialog;

    mediawidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    addWidgetInGrid(mediawidget);
}

void MainWindow::onSearchTextChanged() {
    qDebug() << "segnale ricerca ricevuto";
    clearGridLayout();

    std::string title = (ui->lineEdit->text()).toStdString();

    for (auto it = container->begin(); it != container->end(); ++it) {
        if ((QString::fromStdString((*it)->getTitle())).contains(QString::fromStdString(title), Qt::CaseInsensitive)) {
            mediaWidget *mediawidget = new mediaWidget(*it, this);
            ui->gridLayout->addWidget(mediawidget);

            std::string mediaTitle = (*it)->getTitle();

            //connettere a mediawidget
            connect(mediawidget, &mediaWidget::clicked, this, [this, mediaTitle]() {
                //emit onEditMediaClicked(mediaTitle);
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


void MainWindow::loadMedia() {
    for (auto it = container->begin(); it != container->end(); ++it) {
        mediaWidget* media = new mediaWidget(*it, this);
        addWidgetInGrid(media);
    }
}

void MainWindow::clearGridLayout() {
    QLayoutItem *item;
    while ((item = ui->gridLayout->takeAt(0))) {
        delete item->widget();
        delete item;
    }
}

void MainWindow::refreshGridLayout() {
    colum = 0;
    row = 0;
    clearGridLayout();
    loadMedia();
}

void MainWindow::addWidgetInGrid(mediaWidget* widget) {
    if(colum >= maxColums){
        colum = 0;
        row++;
    }
    ui->gridLayout->addWidget(widget, row, colum);
    qDebug() << "media aggiunto alla griglia";
    colum++;
    ui->gridLayout->update();
}



//show media detail and clear grid layout
void MainWindow::onMediaClicked(AbstractMedia *media) {
    mediaDetailWidget *detailWidget = new mediaDetailWidget(this);
    detailWidget->loadMediaDetails(media);
    detailWidget->show();
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
