#ifndef NEWMEDIATYPEDIALOG_H
#define NEWMEDIATYPEDIALOG_H

#include <QWidget>
#include "mediaeditor.h"
#include "abstractmedia.h"

namespace Ui {
class newMediaTypeDialog;
}

class newMediaTypeDialog : public QWidget
{
    Q_OBJECT

public:
    explicit newMediaTypeDialog(QWidget *parent = nullptr);
    ~newMediaTypeDialog();

private slots:
    void onAudiobookButtonClicked();
    void onMusicButtonClicked();
    void onPodcastButtonClicked();
    void onCancelButtonClicked();

private:
    Ui::newMediaTypeDialog *ui;

signals:
    void mediaTypeChosen(AbstractMedia::mediaType type);

};

#endif // NEWMEDIATYPEDIALOG_H
