#ifndef ABSTRACTMEDIA_H
#define ABSTRACTMEDIA_H

#include <string>
#include "../visitor/visitor.h"

class AbstractMedia {
private:
    std::string title;
    std::string autor;
    std::string imagePath;
    unsigned int year;
    double duration;

public:

    AbstractMedia(
        const std::string & = "",
        const std::string & = "",
        const std::string & = "",
        const unsigned int & = 0,
        const double & = 0
        );
    virtual ~AbstractMedia() = 0;

    //Gets
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getImagePath() const;
    unsigned int getYear() const;
    double getDuration() const;

    //Sets
    void setTitle(const std::string &);
    void setAuthor(const std::string &);
    void setImagePath(const std::string &);
    void setYear(const unsigned int &);
    void setDuration(const double &);

    virtual void accept(Visitor *) const = 0;

};

#endif //MEDIA_H
