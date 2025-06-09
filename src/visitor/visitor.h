#ifndef VISITOR_H
#define VISITOR_H

class Audiobook;
class Music;
class Podcast;

class Visitor
{
public:
    Visitor();
    virtual ~Visitor();

    virtual void visitAudiobook(const Audiobook*) const = 0;
    virtual void visitMusic(const Music*) const = 0;
    virtual void visitPodcast(const Podcast*) const = 0;
};

#endif // VISITOR_H
