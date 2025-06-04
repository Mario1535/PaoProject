#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>
#include <QPixmap>

class Converter{
public:
    Converter();
    static std::string convertPixmapToPath(const QPixmap& pixmap);
};

#endif // CONVERTER_H
