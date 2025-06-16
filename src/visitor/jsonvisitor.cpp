#include "jsonvisitor.h"
#include "../media/audiobook.h"
#include "../media/music.h"
#include "../media/podcast.h"

jsonVisitor::jsonVisitor() {}

void jsonVisitor::visit(const Audiobook* media) {
    createObj(media, array);
}

void jsonVisitor::visit(const Music* media) {
    createObj(media, array);
}

void jsonVisitor::visit(const Podcast* media) {
    createObj(media, array);
}

void jsonVisitor::createObj(const Audiobook* media, QJsonArray array) {
    QJsonObject obj;
    obj["type"] = "audiobook";

    obj["title"] = QString::fromStdString(media->getTitle());
    obj["author"] = QString::fromStdString(media->getAuthor());
    obj["imagepath"] = QString::fromStdString(media->getImagePath());
    obj["year"] = static_cast<int>(media->getYear());
    obj["duration"] = media->getDuration();
    obj["reader"] = QString::fromStdString(media->getReader());
    obj["summary"] = QString::fromStdString(media->getSummary());

    array.append(obj);
}
void jsonVisitor::createObj(const Music* media, QJsonArray array) {
    QJsonObject obj;
    obj["type"] = "music";

    obj["title"] = QString::fromStdString(media->getTitle());
    obj["author"] = QString::fromStdString(media->getAuthor());
    obj["imagepath"] = QString::fromStdString(media->getImagePath());
    obj["year"] = static_cast<int>(media->getYear());
    obj["duration"] = media->getDuration();
    obj["album"] = QString::fromStdString(media->getAlbum());
    obj["lyric"] = QString::fromStdString(media->getLyrics());

    array.append(obj);
}
void jsonVisitor::createObj(const Podcast* media, QJsonArray array) {
    QJsonObject obj;
    obj["type"] = "podcast";

    obj["title"] = QString::fromStdString(media->getTitle());
    obj["author"] = QString::fromStdString(media->getAuthor());
    obj["imagepath"] = QString::fromStdString(media->getImagePath());
    obj["year"] = static_cast<int>(media->getYear());
    obj["duration"] = media->getDuration();
    obj["episode"] = QString::fromStdString(media->getEpisode());
    obj["season"] = QString::fromStdString(media->getSeason());

    array.append(obj);
}

QJsonArray jsonVisitor::getJsonArray() const {
    return array;
}
