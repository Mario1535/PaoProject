QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/manager/mediamanager.cpp \
    src/view/searchoneditaction.cpp \
    src/visitor/concretevisitor.cpp \
    src/visitor/visitor.cpp \
    src/media/abstractmedia.cpp \
    src\media\audiobook.cpp \
    src\container\container.cpp \
    src\converter\converter.cpp \
    src\main.cpp \
    src\view\mainwindow.cpp \
    src\view\mediadetailwidget.cpp \
    src\view\mediaeditor.cpp \
    src\view\mediawidget.cpp \
    src\media\music.cpp \
    src\view\newmediatypedialog.cpp \
    src\media\podcast.cpp \

HEADERS += \
    src/manager/mediamanager.h \
    src/view/searchoneditaction.h \
    src/visitor/concretevisitor.h \
    src/visitor/visitor.h \
    src\media\abstractmedia.h \
    src\media\audiobook.h \
    src\container\container.h \
    src\converter\converter.h \
    src\view\mainwindow.h \
    src\view\mediadetailwidget.h \
    src\view\mediaeditor.h \
    src\view\mediawidget.h \
    src\media\music.h \
    src\view\newmediatypedialog.h \
    src\media\podcast.h \

FORMS += \
    src/view/searchoneditaction.ui \
    src\view\mainwindow.ui \
    src\view\mediadetailwidget.ui \
    src\view\mediaeditor.ui \
    src\view\mediawidget.ui \
    src\view\newmediatypedialog.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    TODO
