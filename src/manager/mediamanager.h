#ifndef MEDIAMANAGER_H
#define MEDIAMANAGER_H

#include "../media/abstractmedia.h"
#include "../container/container.h"

class mediaManager
{
public:
    mediaManager();
    ~mediaManager();

    bool mediaCreated(const AbstractMedia*, Container*);
    bool mediaEdited(Container*, std::string, Visitor*);
    bool mediaDeleted(Container*, const std::string);
};

#endif // MEDIAMANAGER_H
