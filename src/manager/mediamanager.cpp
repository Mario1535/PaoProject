#include "mediamanager.h"
#include "../container/container.h"

mediaManager::mediaManager() {}

mediaManager::~mediaManager() {}

bool mediaManager::mediaCreated(const AbstractMedia* media,Container* container){
    for (auto it = container->begin(); it != container->end(); ++it) {
        if (media->getTitle() == (*it)->getTitle()) {
            return false;
        }
    }
    container->add(media);
    return true;
}
bool mediaManager::mediaEdited(Container* container, std::string title, Visitor* visitor){
    for (auto it = container->begin(); it != container->end(); ++it) {
        if ((*it)->getTitle() == title) {
            (*it)->accept(visitor);
            container->remove(*it);
            return true;
        }
    }
    return false;
}
bool mediaManager::mediaDeleted(Container* container, const std::string title){
    for (auto it = container->begin(); it != container->end(); ++it) {
        if ((*it)->getTitle() == title) {
            container->remove(*it);
            return true;
        }
    }
    return false;
}
