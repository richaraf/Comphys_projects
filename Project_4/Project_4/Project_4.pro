TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    lattice.cpp \
    exact2x2.cpp \
    numerical2.cpp

HEADERS += \
    lattice.h \
    exact2x2.h \
    numerical2.h
