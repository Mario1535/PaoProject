#ifndef JSONVISITOR_H
#define JSONVISITOR_H

#include "visitor.h"
#include <QJsonArray>
#include <QJsonObject>

class jsonVisitor : public Visitor
{
public:
    jsonVisitor();

    void visit(const Audiobook*) override;
    void visit(const Music*) override;
    void visit(const Podcast*) override;
    void createObj(const Audiobook*, QJsonArray);
    void createObj(const Music*, QJsonArray);
    void createObj(const Podcast*, QJsonArray);

    QJsonArray getJsonArray() const;

private:
    QJsonArray array;

};

#endif // JSONVISITOR_H
