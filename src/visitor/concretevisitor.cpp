#include "concretevisitor.h"
#include "../media/audiobook.h"
#include "../media/music.h"
#include "../media/podcast.h"

ConcreteVisitor::ConcreteVisitor() {}

ConcreteVisitor::~ConcreteVisitor() {}

void ConcreteVisitor::visit(const Audiobook* media){
    setAttributes(media);
}
void ConcreteVisitor::visit(const Music* media){
    setAttributes(media);
}
void ConcreteVisitor::visit(const Podcast* media){
    setAttributes(media);
}

void ConcreteVisitor::setAttributes(const Audiobook* media){
    attributes.title = media->getTitle();
    attributes.author = media->getAuthor();
    attributes.imagePath = media->getImagePath();
    attributes.year = media->getYear(); //year
    attributes.duration = media->getDuration(); //duration

    attributes.details["reader"] = media->getReader();
    attributes.details["summary"] = media->getSummary();
}

void ConcreteVisitor::setAttributes(const Music* media){
    attributes.title = media->getTitle();
    attributes.author = media->getAuthor();
    attributes.imagePath = media->getImagePath();
    attributes.year = media->getYear(); //year
    attributes.duration = media->getDuration(); //duration

    attributes.details["album"] = media->getAlbum();
    attributes.details["lyrics"] = media->getLyrics();
}

void ConcreteVisitor::setAttributes(const Podcast* media){
    attributes.title = media->getTitle();
    attributes.author = media->getAuthor();
    attributes.imagePath = media->getImagePath();
    attributes.year = media->getYear(); //year
    attributes.duration = media->getDuration(); //duration

    attributes.details["episode"] = media->getEpisode();
    attributes.details["season"] = media->getSeason();
}
