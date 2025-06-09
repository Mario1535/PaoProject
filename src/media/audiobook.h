#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include <string>
#include "abstractMedia.h"
#include "../visitor/visitor.h"

class Audiobook : public AbstractMedia {
private:
    std::string reader;
    std::string summary;

public:
    Audiobook(
        const std::string & = "",
        const std::string & = "",
        const std::string & = "",
        const unsigned int & = 0,
        const double & = 0,
        const std::string & = "",
        const std::string & = ""
        );
    ~Audiobook() override;

    //Gets
    std::string getReader() const;
    std::string getSummary() const;

    //Sets
    void setReader(const std::string &);
    void setSummary(const std::string &);

    virtual void accept(Visitor *) const override;

};

#endif //AUDIOBOOK_H
