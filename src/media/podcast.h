#ifndef PODCAST_H
#define PODCAST_H

#include <string>
#include "abstractmedia.h"
#include "../visitor/visitor.h"

class Podcast : public AbstractMedia {
private:
    std::string episode;
    std::string season;

public:
    Podcast(
        const std::string & = "",
        const std::string & = "",
        const std::string & = "",
        const unsigned int & = 0,
        const double & = 0,
        const std::string & = 0,
        const std::string & = 0
        );
    ~Podcast() override;

    //Gets
    std::string getEpisode() const;
    std::string getSeason() const;

    //Sets
    void setEpisode(const std::string &);
    void setSeason(const std::string &);

    virtual void accept(Visitor *) const override;

};

#endif //PODCAST_H
