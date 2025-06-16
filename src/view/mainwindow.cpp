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
}


//slots
void MainWindow::onNewActionTriggered() {

    mediaEditor *editor = new mediaEditor(this);
    AbstractMedia* media = nullptr;
    mediaWidget *mediawidget;

    if(editor->choice() != -1){
        bool aborted = false;
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
        connect(editor, &mediaEditor::abortMediaCreation, this, [&aborted](){
            aborted = true;
        });
        editor->exec();

        if(!aborted){
            mediawidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            addWidgetInGrid(mediawidget, media);
        }
    }

    delete editor;
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
        for (auto it = container->begin(); it != container->end();) {
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

    if (type == "Audiobook") {
        return new Audiobook(obj["title"].toString().toStdString(),
                             obj["author"].toString().toStdString(),
                             obj["imagepath"].toString().toStdString(),
                             static_cast<unsigned int>(obj["year"].toInt()),
                             obj["duration"].toDouble(),
                             obj["reader"].toString().toStdString(),
                             obj["summary"].toString().toStdString());
    } else if (type == "Music") {
        return new Music(obj["title"].toString().toStdString(),
                         obj["author"].toString().toStdString(),
                         obj["imagepath"].toString().toStdString(),
                         static_cast<unsigned int>(obj["year"].toInt()),
                         obj["duration"].toDouble(),
                         obj["album"].toString().toStdString(),
                         obj["lyric"].toString().toStdString());
    } else if (type == "Podcast") {
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
    jsonVisitor visitor;
    for (auto it = container->begin(); it != container->end(); ++it) {
        (*it)->accept(&visitor);
    }

    QString path = QFileDialog::getSaveFileName(this, "Salva file JSON", "", "JSON (*.json)");
    if (!path.isEmpty()) {
        handleExport(visitor.getJsonArray(), path);
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
