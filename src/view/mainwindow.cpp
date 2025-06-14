#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mediawidget.h"
#include "mediaeditor.h"
#include "mediadetailwidget.h"
#include "searchoneditaction.h"
#include "..\container\container.h"
#include "..\manager\mediamanager.h"
#include "..\media\abstractmedia.h"

class mediaEditor;
class mediaWidget;
class mediaDetailWidget;

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


//slots
void MainWindow::onNewActionTriggered() {

    mediaEditor *editor = new mediaEditor(this);
    AbstractMedia* media = nullptr;
    mediaWidget *mediawidget;

    editor->choice();
    editor->show();
    connect(editor, &mediaEditor::newMediaCreated, this, [this, &mediawidget, &media](AbstractMedia* newMedia) {

        media = newMedia;

        mediaManager *manager = new mediaManager();
        if(manager->mediaCreated(newMedia, container)){
            statusBar()->showMessage("Media salvato!", 3000);
            mediawidget = new mediaWidget(newMedia, this);
        }
        else {
            statusBar()->showMessage("Media NON salvato", 3000);
        }
        delete manager;
    });

    editor->exec();
    delete editor;

    mediawidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    addWidgetInGrid(mediawidget, media);
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
            connect(mediawidget, &mediaWidget::mediaClicked, this, [this, mediaTitle]() {
                //emit onEditMediaClicked(mediaTitle);
                close();
            });
        }
    }
}

void MainWindow::onEditActionTriggered() {
    searchOnEditAction *search = new searchOnEditAction(this);

    search->show();
    search->searchMediaToEdit(container);
    search->exec();

    delete search;
}

void MainWindow::editMedia(Container* container, std::string title){
    qDebug() << "edit media method";

    mediaEditor *editor = new mediaEditor();
    ConcreteVisitor *visitor = new ConcreteVisitor();
    mediaManager *manager = new mediaManager();

    if (manager->mediaEdited(container, title, visitor)) {
        qDebug() << "editing media";
        editor->loadMedia(visitor);
        editor->show();
        editor->exec();
        //statusBar()->showMessage("Media modificato!", 3000);
        refreshGridLayout();
    } else {
        //statusBar()->showMessage("Media NON modificato!", 3000);
    }

    delete editor;
    delete visitor;
    delete manager;
}

void MainWindow::onRemoveActionTriggered() {
    searchOnEditAction *search = new searchOnEditAction(this);

    search->show();
    search->setFocus();
    search->searchMediaToEdit(container);

    delete search;
}

void MainWindow::removeMedia(Container* container, std::string title){
    qDebug() << "remove media method";

    mediaManager *manager = new mediaManager();

    if (manager->mediaDeleted(container, title)) {
        //statusBar()->showMessage("Media eliminato!", 3000);
        //refreshGrid();
    } else {
        //statusBar()->showMessage("Media NON eliminato!", 3000);
    }

    delete manager;

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

void MainWindow::onMediaClicked(const AbstractMedia *media) {
    mediaDetailWidget *detail = new mediaDetailWidget(this, container, media->getTitle());
    detail->loadMediaDetails(media);
    detail->show();
}


//metodi
void MainWindow::clearGridLayout() {
    qDebug() << "clear grid layot";
    QLayoutItem *item;
    while ((item = ui->gridLayout->takeAt(0))) {
        delete item->widget();
        delete item;
    }
    qDebug() << "grid clear";
}

void MainWindow::loadMedia() {
    qDebug() << "loading media";
    const AbstractMedia* media;
    for (auto it = container->begin(); it != container->end();) {
        mediaWidget* widget = new mediaWidget(*it, this);
        media = *it;
        qDebug() << "carico media: " << media->getTitle();
        addWidgetInGrid(widget, media);

        it++;
    }
    qDebug() << "media loaded";
}

void MainWindow::refreshGridLayout() {
    qDebug() << "refresh " << colum << " " << row;
    colum = 0;
    row = 0;
    qDebug() << "reset colum row " << colum  << " " << row;
    clearGridLayout();
    loadMedia();
}

void MainWindow::addWidgetInGrid(mediaWidget* widget, const AbstractMedia* media) {
    if(colum >= maxColums){
        colum = 0;
        row++;
    }
    ui->gridLayout->addWidget(widget, row, colum);
    //connect(widget, &mediaWidget::mediaClicked, this, &MainWindow::onMediaClicked);
    connect(widget, &mediaWidget::mediaClicked, this, [=]() {
        onMediaClicked(media);
    });
    qDebug() << "media aggiunto alla griglia";
    colum++;
    ui->gridLayout->update();
}





//void MainWindow::loadMediaFromFile(const QString &filePath) {} //da implementare
