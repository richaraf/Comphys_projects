TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    vec3.cpp \
    system.cpp \
    particle.cpp \
    Integrators/integrator.cpp \
    Integrators/eulercromer.cpp \
    Potentials/potential.cpp \
    Potentials/newtoniangravity.cpp \
    examples.cpp \
    Integrators/velocityverlet.cpp \
    Potentials/nopotential.cpp \
    InitialConditions/initialcondition.cpp \
    InitialConditions/twobody.cpp \
    InitialConditions/threebody.cpp \
    InitialConditions/solarsystem.cpp \
    Tests/velocity_test.cpp \
    Tests/test.cpp \
    InitialConditions/twobody_escape_vel.cpp

HEADERS += \
    vec3.h \
    system.h \
    particle.h \
    Integrators/integrator.h \
    Integrators/eulercromer.h \
    Potentials/potential.h \
    Potentials/newtoniangravity.h \
    examples.h \
    Integrators/velocityverlet.h \
    Potentials/nopotential.h \
    InitialConditions/initialcondition.h \
    InitialConditions/twobody.h \
    InitialConditions/threebody.h \
    InitialConditions/solarsystem.h \
    Tests/velocity_test.h \
    Tests/test.h \
    InitialConditions/twobody_escape_vel.h
