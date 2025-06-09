#include "converter.h"
#include "..\media\abstractmedia.h"

#include <QPixmap>
#include <QDir>
#include <QStandardPaths>
#include <QUuid>
#include <string>

Converter::Converter() {}

std::string Converter::convertPixmapToPath(const QPixmap& pixmap) {
    if (pixmap.isNull()) return "";  // Se l'immagine è vuota

    // Ottieni percorso alla directory temporanea
    QString tempDir = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
    QString uniqueFileName = tempDir + "/" + QUuid::createUuid().toString(QUuid::WithoutBraces) + ".png";

    if (pixmap.save(uniqueFileName, "PNG")) {
        return uniqueFileName.toStdString();
    }

    return "";  // Fallimento
}
