#include "container.h"
#include "../media/abstractmedia.h"

Container::~Container(){
    for (auto mediaItem : media) {
        delete mediaItem;
    }
}



void Container::add(const AbstractMedia* m){
    media.push_back(m);
}

void Container::remove(const AbstractMedia* m) {
    bool found = false;
    for (auto it = media.begin(); it != media.end() && found == false; it++)
    {
        if (m->getTitle() == (*it)->getTitle())
        {
            media.erase(it);
            found=true;
        }
    }
}

const AbstractMedia* Container::getMedia(std::string & t) const{
    for(auto it = media.begin(); it!=media.end(); ++it){
        if(t == (*it)->getTitle())
        {
            return *it;
        }
    }
    return nullptr;
}



bool Container::search(Container* container, std::string title){
    for(auto it = media.begin(); it!=media.end(); ++it){
        if((*it)->getTitle() == title){
            container->add(*it);
            return true;
        }
    }
    return false;
}

std::vector<const AbstractMedia*>::const_iterator Container::begin() const{
    return media.begin();
}

std::vector<const AbstractMedia*>::const_iterator Container::end() const{
    return media.end();
}
