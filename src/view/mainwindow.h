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
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "../media/abstractmedia.h"
#include "mediawidget.h"
#include "../container/container.h"


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
    void loadMedia();
    void refreshGridLayout();
    void refreshGridCoordinates();
    void addWidgetInGrid(mediaWidget*, ConcreteVisitor*);

    void editMedia(Container*, std::string);
    void removeMedia(Container*, std::string);

protected:
    //void closeEvent(QCloseEvent *event) override;  // Gestione della chiusura della finestra

private slots:

    void onSearchTextChanged();

    void onNewActionTriggered();
    void onLoadActionTriggered();
    void onExportActionTriggered();
    void onHelpActionTriggered();

    void onMediaClicked(ConcreteVisitor *visitor);

private:
    AbstractMedia* load(const QJsonObject&);
    void handleExport(const QJsonArray&, const QString& = "media.json");

    Ui::MainWindow *ui;

    QVBoxLayout *mainLayout;
    //QGridLayout *gridLayout;
    QLineEdit *searchBar;
    QLabel *statusLabel;
    //QScrollArea *scrollArea;
    Container *container;

    const short unsigned int maxColums = 3;
    short unsigned int colum = 0, row = 0;

    void setupUI();
};

#endif // MAINWINDOW_H
