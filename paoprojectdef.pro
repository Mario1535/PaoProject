QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractmedia.cpp \
    audiobook.cpp \
    container.cpp \
    converter.cpp \
    main.cpp \
    mainwindow.cpp \
    mediadetailwidget.cpp \
    mediaeditor.cpp \
    mediawidget.cpp \
    music.cpp \
    newmediatypedialog.cpp \
    podcast.cpp \
    textoverlaywidget.cpp

HEADERS += \
    abstractmedia.h \
    audiobook.h \
    container.h \
    converter.h \
    mainwindow.h \
    mediadetailwidget.h \
    mediaeditor.h \
    mediawidget.h \
    music.h \
    newmediatypedialog.h \
    podcast.h \
    textoverlaywidget.h

FORMS += \
    mainwindow.ui \
    mediadetailwidget.ui \
    mediaeditor.ui \
    mediawidget.ui \
    newmediatypedialog.ui \
    textoverlaywidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    TODO
