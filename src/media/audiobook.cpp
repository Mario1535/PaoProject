#include <string>
#include "audiobook.h"

Audiobook::Audiobook(
    const std::string &t,
    const std::string &a,
    const std::string &ip,
    const unsigned int &y,
    const double &d,
    const std::string &r,
    const std::string &s
    ) : AbstractMedia(t,a,ip,y,d), reader(r), summary(s) {}
Audiobook::~Audiobook(){}

//Gets
std::string Audiobook::getReader() const{
    return reader;
}
std::string Audiobook::getSummary() const{
    return summary;
}

//Sets
void Audiobook::setReader(const std::string &r){
    this->reader = r;
}
void Audiobook::setSummary(const std::string &s){
    this->summary = s;
}

void Audiobook::accept(Visitor *visit) const{
    visit->visit(this);
}
