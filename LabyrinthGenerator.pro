TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    maze.cpp

HEADERS += \
    maze.h

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += opencv
