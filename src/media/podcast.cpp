#include <string>
#include "podcast.h"

Podcast::Podcast(
    const std::string &t,
    const std::string &a,
    const std::string &ip,
    const unsigned int &y,
    const double &d,
    const std::string &e,
    const std::string &s
    ) : AbstractMedia(t,a,ip,y,d), episode(e), season(s) {}
Podcast::~Podcast(){}

//Gets
std::string Podcast::getEpisode() const{
    return episode;
}
std::string Podcast::getSeason() const{
    return season;
}

//Sets
void Podcast::setEpisode(const std::string &e){
    this->episode = e;
}
void Podcast::setSeason(const std::string &s){
    this->season = s;
}
