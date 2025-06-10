#include "mediamanager.h"
#include "../container/container.h"

mediaManager::mediaManager() {}

mediaManager::~mediaManager() {}

bool mediaCreated(const AbstractMedia* media,Container* container){
    for (auto it = container->begin(); it != container->end(); ++it) {
        if (media->getTitle() == (*it)->getTitle()) {
            return false;
        }
    }
    container->add(media);
    return true;
}
bool mediaEdited(Container* container, std::string title, Visitor* visitor){

}
bool mediaDeleted(const AbstractMedia* media){

}

