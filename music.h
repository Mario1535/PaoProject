#ifndef MUSIC_H
#define MUSIC_H

#include <string>
#include "abstractMedia.h"

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

    virtual mediaType getMediaType() const override {return mediaType::Music;}

    //Sets
    void setAlbum(const std::string &);
    void setLyrics(const std::string &);
};

#endif //MUSIC_H
