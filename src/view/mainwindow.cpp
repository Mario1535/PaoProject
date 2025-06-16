#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmenubar.h"
#include "mediawidget.h"
#include "mediaeditor.h"
#include "mediadetailwidget.h"
#include "../container/container.h"
#include "../manager/mediamanager.h"
#include "../media/abstractmedia.h"
#include "../media/audiobook.h"
#include "../media/music.h"
#include "../media/podcast.h"
#include "../visitor/jsonvisitor.h"

class mediaEditor;
class mediaWidget;
class mediaDetailWidget;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("../../assets/window_icons/mainwindow_icon.png"));
    setupUI();

    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::onSearchTextChanged);

    setMinimumSize(600, 400);
    statusBar()->setSizeGripEnabled(true);

    //ui->label->setText("Mariofy");
    //ui->label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    //ui->label->setAlignment(Qt::AlignCenter);
    ui->lineEdit->setPlaceholderText("Cerca...");
    ui->lineEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    //ui->gridLayout->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //ui->gridContainer->setLayout(ui->gridLayout);
    ui->scrollArea->setWidgetResizable(true);
    //ui->scrollArea->setWidget(ui->gridContainer);

    container = new Container();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete container;
}

void MainWindow::setupUI()
{
    QMenuBar* menubar = new QMenuBar(this);
    setMenuBar(menubar);

    QMenu* mediaMenu = menubar->addMenu("Media");

    QAction* actionNew = new QAction("New", this);
    QAction* actionLoad = new QAction("Load", this);
    QAction* actionExport = new QAction("Export", this);
    mediaMenu->addAction(actionNew);
    mediaMenu->addAction(actionLoad);
    mediaMenu->addAction(actionExport);
    connect(actionNew, &QAction::triggered, this, &MainWindow::onNewActionTriggered);
    connect(actionLoad, &QAction::triggered, this, &MainWindow::onLoadActionTriggered);
    connect(actionExport, &QAction::triggered, this, &MainWindow::onExportActionTriggered);

    QMenu* helpMenu = menubar->addMenu("Help");

    QAction* actionHelp = new QAction("Help", this);
    helpMenu->addAction(actionHelp);
    connect(actionHelp, &QAction::triggered, this, &MainWindow::onHelpActionTriggered);


    ui->scrollArea->setWidgetResizable(true);

    QVBoxLayout* layout = new QVBoxLayout(ui->gridContainer);
    layout->addLayout(ui->gridLayout);  // oppure .addWidget(gridLayoutWidget), se usi un wrapper
    layout->addStretch(); // per evitare schiacciamento

    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);

}


//slots
void MainWindow::onNewActionTriggered() {

    mediaEditor *editor = new mediaEditor(this);
    mediaWidget *mediawidget;
    ConcreteVisitor* visitor = new ConcreteVisitor;

    if(editor->choice() != -1){
        bool aborted = true;
        editor->show();

        connect(editor, &mediaEditor::newMediaCreated, this, [this, &mediawidget, &visitor, &aborted](AbstractMedia* newMedia) {

            newMedia->accept(visitor);

            mediaManager *manager = new mediaManager();
            if(manager->mediaCreated(newMedia, container)){
                statusBar()->showMessage("Media salvato!", 3000);
                mediawidget = new mediaWidget(visitor, this);
            }
            else {
                statusBar()->showMessage("Media NON salvato", 3000);
            }
            delete manager;
            aborted = false;
        });
        connect(editor, &mediaEditor::abortMediaCreation, this, [&aborted](){
            aborted = true;
        });
        editor->exec();

        if(!aborted){
            mediawidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            //mediawidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

            addWidgetInGrid(mediawidget, visitor);
        }
    }

    delete editor;
}

void MainWindow::onSearchTextChanged() {
    qDebug() << "segnale ricerca ricevuto";
    clearGridLayout();
    refreshGridCoordinates();

    std::string title = (ui->lineEdit->text()).toStdString();
    ConcreteVisitor* visitor = new ConcreteVisitor;

    if (title.empty()) {
        for (auto it = container->begin(); it != container->end(); ++it) {
            (*it)->accept(visitor);
            mediaWidget *mediawidget = new mediaWidget(visitor, this);
            //mediawidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            mediawidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
            addWidgetInGrid(mediawidget, visitor);
        }
        delete visitor;
        return;
    }

    for (auto it = container->begin(); it != container->end(); ++it) {
        if ((QString::fromStdString((*it)->getTitle())).contains(QString::fromStdString(title), Qt::CaseInsensitive)) {
            (*it)->accept(visitor);
            mediaWidget *mediawidget = new mediaWidget(visitor, this);
            mediawidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

            addWidgetInGrid(mediawidget, visitor);
        }
    }
    delete visitor;
}

void MainWindow::editMedia(Container* container, std::string title){
    qDebug() << "edit media method";

    mediaEditor *editor = new mediaEditor();
    ConcreteVisitor *visitor = new ConcreteVisitor();
    mediaManager *manager = new mediaManager();
    mediaWidget *mediawidget;

    if (manager->mediaEdited(container, title, visitor)) {
        qDebug() << "editing media";
        editor->loadMedia(visitor);
        editor->show();
        connect(editor, &mediaEditor::newMediaCreated, this, [this, &mediawidget, &visitor, &container](AbstractMedia* newMedia) {

            newMedia->accept(visitor);

            mediaManager *manager = new mediaManager();
            if(manager->mediaCreated(newMedia, container)){
                statusBar()->showMessage("Media salvato!", 3000);
                mediawidget = new mediaWidget(visitor, this);
            }
            else {
                statusBar()->showMessage("Media NON salvato", 3000);
            }
            delete manager;
        });
        editor->exec();
        for (auto it = container->begin(); it != container->end(); ++it) {
            qDebug() << "media: " << (*it)->getTitle();
        }
        statusBar()->showMessage("Media modificato!", 3000);


        refreshGridLayout();
    } else {
        statusBar()->showMessage("Media NON modificato!", 3000);
    }

    delete editor;
    delete visitor;
    delete manager;
}

void MainWindow::removeMedia(Container* container, std::string title){
    qDebug() << "remove media method";

    mediaManager *manager = new mediaManager();

    if (manager->mediaDeleted(container, title)) {
        statusBar()->showMessage("Media eliminato!", 3000);
        refreshGridLayout();
    } else {
        statusBar()->showMessage("Media NON eliminato!", 3000);
    }

    delete manager;

}

void MainWindow::onLoadActionTriggered() {
    QString path = QFileDialog::getOpenFileName(this, "Apri file JSON", "", "JSON (*.json)");
    if (path.isEmpty()) return;

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Impossibile aprire il file.");
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);
    if (parseError.error != QJsonParseError::NoError || !doc.isArray()) {
        qWarning("Errore nel parsing del JSON.");
        return;
    }

    QJsonArray array = doc.array();
    mediaManager* manager = new mediaManager();
    for (QJsonArray::const_iterator it = array.constBegin(); it != array.constEnd(); ++it) {
        if (!it->isObject())
            continue;

        const QJsonObject obj = it->toObject();
        const AbstractMedia* media = load(obj);

        if (manager->mediaCreated(media, container)) {
            qDebug() << "il media: " << media->getTitle();
            statusBar()->showMessage("Media aggiunto!", 3000);
        } else {
            statusBar()->showMessage("Media NON aggiunto", 3000);
        }
    }

    delete manager;
    qDebug() << "TUTTI I MEDIA AGGIUNTI";
    refreshGridLayout();
}

AbstractMedia* MainWindow::load(const QJsonObject& obj) {
    QString type = obj["type"].toString();

    if (type == "audiobook") {
        return new Audiobook(obj["title"].toString().toStdString(),
                             obj["author"].toString().toStdString(),
                             obj["imagepath"].toString().toStdString(),
                             static_cast<unsigned int>(obj["year"].toInt()),
                             obj["duration"].toDouble(),
                             obj["reader"].toString().toStdString(),
                             obj["summary"].toString().toStdString());
    } else if (type == "music") {
        return new Music(obj["title"].toString().toStdString(),
                         obj["author"].toString().toStdString(),
                         obj["imagepath"].toString().toStdString(),
                         static_cast<unsigned int>(obj["year"].toInt()),
                         obj["duration"].toDouble(),
                         obj["album"].toString().toStdString(),
                         obj["lyric"].toString().toStdString());
    } else if (type == "podcast") {
        return new Podcast(obj["title"].toString().toStdString(),
                           obj["author"].toString().toStdString(),
                           obj["imagepath"].toString().toStdString(),
                           static_cast<unsigned int>(obj["year"].toInt()),
                           obj["duration"].toDouble(),
                           obj["episode"].toString().toStdString(),
                           obj["season"].toString().toStdString());
    }

    return nullptr;
}

void MainWindow::onExportActionTriggered() {
    jsonVisitor* visitor = new jsonVisitor();
    for (auto it = container->begin(); it != container->end(); ++it) {
        (*it)->accept(visitor);
    }

    QString path = QFileDialog::getSaveFileName(this, "Salva file JSON", "", "JSON (*.json)");
    if (!path.isEmpty()) {
        handleExport(visitor->getJsonArray(), path);
    }
}

void MainWindow::handleExport(const QJsonArray& array, const QString& filePath) {
    QJsonDocument doc(array);
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
    } else {
        qWarning("Impossibile aprire il file per la scrittura.");
    }
}

void MainWindow::onHelpActionTriggered() {
    QMessageBox::information(this, "Aiuto", "Scorciatoie:\n"
                                            "Ctrl+N: New media\n"
                                            "Ctrl+L: Load data\n"
                                            "Ctrl+E: Export data");
}

void MainWindow::onMediaClicked(ConcreteVisitor* visitor) {

    mediaDetailWidget *detail = new mediaDetailWidget(this, container, visitor->getAttributes().title);
    detail->loadMediaDetails(visitor);
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
    ConcreteVisitor* visitor = new ConcreteVisitor();
    for (auto it = container->begin(); it != container->end();) {
        (*it)->accept(visitor);
        mediaWidget* widget = new mediaWidget(visitor, this);

        widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

        media = *it;
        qDebug() << "carico media: " << media->getTitle();
        addWidgetInGrid(widget, visitor);

        it++;
    }
    //qDebug() << "media loaded";

}

void MainWindow::refreshGridLayout() {
    refreshGridCoordinates();
    clearGridLayout();
    loadMedia();
}

void MainWindow::refreshGridCoordinates() {
    colum  = 0;
    row = 0;
}

void MainWindow::addWidgetInGrid(mediaWidget* widget, ConcreteVisitor* visitor) {
    if(colum >= maxColums){
        colum = 0;
        row++;
    }
    ui->gridLayout->addWidget(widget, row, colum);
     connect(widget, &mediaWidget::mediaClicked, this, [=]() {
         onMediaClicked(visitor);
    });
    qDebug() << "media aggiunto alla griglia";
    colum++;
    ui->gridLayout->update();
}
