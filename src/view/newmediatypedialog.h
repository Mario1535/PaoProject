#ifndef NEWMEDIATYPEDIALOG_H
#define NEWMEDIATYPEDIALOG_H

#include <QWidget>

namespace Ui {
class newMediaTypeDialog;
}

class newMediaTypeDialog : public QWidget
{
    Q_OBJECT

public:
    explicit newMediaTypeDialog(QWidget *parent = nullptr);
    ~newMediaTypeDialog();

public slots:
    void onAudiobookButtonClicked();
    void onMusicButtonClicked();
    void onPodcastButtonClicked();
    void onCancelButtonClicked();

private:
    Ui::newMediaTypeDialog *ui;

signals:
    void mediaTypeChosen(unsigned short int);

};

#endif // NEWMEDIATYPEDIALOG_H
