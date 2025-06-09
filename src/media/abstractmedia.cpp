#include "abstractMedia.h"
#include <string>

AbstractMedia::AbstractMedia(
    const std::string &t,
    const std::string &a,
    const std::string &ip,
    const unsigned int &y,
    const double &d
    ) : title(t), autor(a), imagePath(ip), year(y), duration(d) {}

AbstractMedia::~AbstractMedia(){};

//Gets
std::string AbstractMedia::getTitle() const {
    return title;
}
std::string AbstractMedia::getAuthor() const{
    return autor;
}
std::string AbstractMedia::getImagePath() const{
    return imagePath;
}
unsigned int AbstractMedia::getYear() const{
    return year;
}
double AbstractMedia::getDuration() const{
    return duration;
}

//Sets
void AbstractMedia::setTitle(const std::string &t){
    this->title = t;
}
void AbstractMedia::setAuthor(const std::string &a){
    this->autor = a;
}
void AbstractMedia::setImagePath(const std::string &ip){
    this->imagePath = ip;
}
void AbstractMedia::setYear(const unsigned int &y){
    this->year = y;
}
void AbstractMedia::setDuration(const double &d){
    this->duration = d;
}
