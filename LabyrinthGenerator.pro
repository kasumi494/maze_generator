TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    maze.cpp \
    mazerecursion.cpp \
    mazewave.cpp

HEADERS += \
    maze.hpp \
    mazerecursion.hpp \
    mazewave.hpp

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += opencv
