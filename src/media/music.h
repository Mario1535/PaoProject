#ifndef MUSIC_H
#define MUSIC_H

#include <string>
#include "abstractmedia.h"
#include "../visitor/visitor.h"

class Music : public AbstractMedia {
private:
    std::string album;
    std::string lyrics;

public:
    Music(
        const std::string & = "",
        const std::string & = "",
        const std::string & = "",
        const unsigned int & = 0,
        const double & = 0,
        const std::string & = "",
        const std::string & = ""
        );
    ~Music() override;

    //Gets
    std::string getAlbum() const;
    std::string getLyrics() const;

    //Sets
    void setAlbum(const std::string &);
    void setLyrics(const std::string &);

    virtual void accept(Visitor *) const override;

};

#endif //MUSIC_H
