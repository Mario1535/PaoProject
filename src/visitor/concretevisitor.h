#ifndef CONCRETEVISITOR_H
#define CONCRETEVISITOR_H

#include "visitor.h"

class ConcreteVisitor : public Visitor
{
public:
    ConcreteVisitor();
    virtual ~ConcreteVisitor();

    virtual void visitAudiobook(const Audiobook*) const override;
    virtual void visitMusic(const Music*) const override;
    virtual void visitPodcast(const Podcast*) const override;

};

#endif // CONCRETEVISITOR_H
