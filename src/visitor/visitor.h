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

    virtual void visit(const Audiobook*) = 0;
    virtual void visit(const Music*) = 0;
    virtual void visit(const Podcast*) = 0;
};

#endif // VISITOR_H
