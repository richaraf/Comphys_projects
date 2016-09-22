TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -larmadillo -llapack -lblas

SOURCES += main.cpp \
    jacobian_rotation.cpp \
        largest_akl.cpp

DISTFILES +=

HEADERS += \
    jacobian_rotation.h \
    largest_akl.h
