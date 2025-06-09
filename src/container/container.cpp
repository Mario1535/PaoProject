#include "container.h"
#include "..\media\abstractMedia.h"


//DELETE
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
//CREATE
void Container::add(const AbstractMedia* m){
    media.push_back(m);

}

//READs by name
const AbstractMedia* Container::getMedia(std::string & n) const{
    for(auto it = media.begin(); it!=media.end(); ++it){
        if(n == (*it)->getTitle())
        {
            return *it;
        }
    }
    return nullptr;
}
Container::~Container(){
    for (auto mediaItem : media) {
        delete mediaItem;
    }
}


std::vector<const AbstractMedia*> Container::getMediaVec() const{
    return media;
}


std::vector<const AbstractMedia*>::const_iterator Container::begin() const{
    return media.begin();
}

std::vector<const AbstractMedia*>::const_iterator Container::end() const{
    return media.end();
}

void Container::search(Container* container, std::string query){

    for(auto it = media.begin(); it!=media.end(); ++it)
    {
        if((*it)->getTitle().find(query) != std::string::npos){
            container->add(*it);
        }
    }
}

bool Container::empty(){
    return media.empty();
}

void Container::clear(){
    media.clear();
}

int Container::size()
{
    return media.size();
}
