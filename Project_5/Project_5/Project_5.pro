TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    variationalcalculation.cpp \
    vec3.cpp \
    wavefunction.cpp

HEADERS += \
    variationalcalculation.h \
    vec3.h \
    wavefunction.h
