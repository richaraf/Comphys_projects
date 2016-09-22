TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -larmadillo -llapack - lblas

SOURCES += \
    largest_akl.cpp

