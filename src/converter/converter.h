#ifndef CONVERTER_H
#define CONVERTER_H

#include "..\media\abstractmedia.h"
#include <string>
#include <QPixmap>

class Converter{
public:
    Converter();
    static std::string convertPixmapToPath(const QPixmap&);
};

#endif // CONVERTER_H
