#ifndef CONCRETEVISITOR_H
#define CONCRETEVISITOR_H

#include "visitor.h"
#include "string"
#include <unordered_map>

class ConcreteVisitor : public Visitor
{

public:
    struct Attributes {
        int index;

        std::string title;
        std::string author;
        std::string imagePath;
        unsigned int year;
        double duration;
        std::unordered_map<std::string, std::string> details;
    };

    ConcreteVisitor();
    virtual ~ConcreteVisitor();

    virtual void visit(const Audiobook*) override;
    virtual void visit(const Music*) override;
    virtual void visit(const Podcast*) override;

    void setAttributes(const Audiobook*);
    void setAttributes(const Music*);
    void setAttributes(const Podcast*);

    Attributes getAttributes() const;

private:
    Attributes attributes;

};

#endif // CONCRETEVISITOR_H
