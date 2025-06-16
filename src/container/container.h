#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <string>
#include <QObject>

#include "../media/abstractmedia.h"

class Container : public QObject
{
    Q_OBJECT
private:
    std::vector<const AbstractMedia*> media;

public:
    ~Container();
    void remove(const AbstractMedia*);
    void add(const AbstractMedia*);
    const AbstractMedia* getMedia(std::string &)const;

    bool search(Container*, std::string);
    std::vector<const AbstractMedia*>::const_iterator begin() const;
    std::vector<const AbstractMedia*>::const_iterator end() const;

};

#endif // CONTAINER_H
