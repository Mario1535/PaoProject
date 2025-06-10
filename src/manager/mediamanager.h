#ifndef MEDIAMANAGER_H
#define MEDIAMANAGER_H

#include "../media/abstractmedia.h"

class mediaManager
{
public:
    mediaManager();
    ~mediaManager();

    bool mediaCreated(const AbstractMedia*);
    bool mediaEdited(const AbstractMedia*);
    bool mediaDeleted(const AbstractMedia*);
};

#endif // MEDIAMANAGER_H
