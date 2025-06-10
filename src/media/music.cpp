#include <string>
#include "music.h"

Music::Music(
    const std::string &t,
    const std::string &a,
    const std::string &ip,
    const unsigned int &y,
    const double &d,
    const std::string &al,
    const std::string &l
    ) : AbstractMedia(t,a,ip,y,d), album(al), lyrics(l) {}
Music::~Music(){}

//Gets
std::string Music::getAlbum() const{
    return album;
}
std::string Music::getLyrics() const{
    return lyrics;
}

//Sets
void Music::setAlbum(const std::string &a){
    this->album = a;
}
void Music::setLyrics(const std::string &l){
    this->lyrics = l;
}

void Music::accept(Visitor *visit) const{
    visit->visit(this);
}

