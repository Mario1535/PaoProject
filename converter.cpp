#include "converter.h"

#include <QPixmap>
#include <QTemporaryFile>
#include <string>

Converter::Converter() {};

std::string Converter::convertPixmapToPath(const QPixmap& pixmap) {
    if (pixmap.isNull()) return "";  // Se l'immagine è vuota

    // Crea un file temporaneo
    QTemporaryFile tempFile;
    if (tempFile.open()) {
        QString path = tempFile.fileName() + ".png";  // Aggiungi estensione
        if (pixmap.save(path, "PNG")) {  // Salva come PNG
            return path.toStdString();
        }
    }
    return "";  // Fallback se qualcosa va male
}
