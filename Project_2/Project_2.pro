TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -larmadillo -llapack -lblas

SOURCES += main.cpp \
    jacobian_rotation.cpp \
        largest_akl.cpp \
    orthogonality_check.cpp \
    potential_functions.cpp \
    largest_akl_test.cpp

DISTFILES +=

HEADERS += \
    jacobian_rotation.h \
    largest_akl.h \
    orthogonality_check.h \
    potential_functions.h \
    largest_akl_test.h
