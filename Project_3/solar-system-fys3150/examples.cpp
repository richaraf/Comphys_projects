#include "examples.h"
#include "system.h"
#include "particle.h"
#include "Integrators/eulercromer.h"
#include "Integrators/velocityverlet.h"
#include "Potentials/relativisticnewtoniangravity.h"
#include "Potentials/newtoniangravity.h"
#include "Potentials/nopotential.h"
#include "InitialConditions/twobody.h"
#include "InitialConditions/threebody.h"
#include "InitialConditions/solarsystem.h"
#include "InitialConditions/mercurysun.h"
#include"InitialConditions/twobody_escape_vel.h"
#include <iostream>
#include <cmath>
#include <time.h>


void Examples::twoBodyProblem() {
    double G            = 4*pow(M_PI,2);
    clock_t start, finish;

    System* twoBodySystem = new System();
    twoBodySystem->setIntegrator        (new VelocityVerlet(twoBodySystem));
    twoBodySystem->setDt                (1e-3);
    twoBodySystem->setPotential         (new NewtonianGravity(G));
    twoBodySystem->setInitialCondition  (new TwoBody());
    twoBodySystem->setFileWriting       (false);
    twoBodySystem->setTestVelocity      (false);
    twoBodySystem->removeLinearMomentum ();
    start = clock();
    twoBodySystem->integrate            (100000);
    finish = clock();
    double t = (double) (finish - start)/CLOCKS_PER_SEC;
    std::cout << t << std::endl;
}

void Examples::threeBodyProblem() {
    double G = 4*pow(M_PI,2);

    System* threeBodySystem = new System();
    threeBodySystem->setIntegrator          (new VelocityVerlet(threeBodySystem));
    threeBodySystem->setPotential           (new NewtonianGravity(G));
    threeBodySystem->setInitialCondition    (new ThreeBody());
    threeBodySystem->setFileWriting         (true);
    threeBodySystem->removeLinearMomentum   ();
    threeBodySystem->integrate              (5000);
}

void Examples::solarSystemProblem()
{
    double G = 4*pow(M_PI,2);

    System* solarSystem = new System();
    solarSystem->setIntegrator          (new VelocityVerlet(solarSystem));
    solarSystem->setDt                  (1e-3);
    solarSystem->setPotential           (new NewtonianGravity(G));
    solarSystem->setInitialCondition    (new SolarSystem());
    solarSystem->setFileWriting         (true);
    solarSystem->removeLinearMomentum   ();
    solarSystem->integrate              (50000);
    solarSystem->computeAngularMomentum ();
}

void Examples::twoBody_escape_velProblem() {
    double G            = 4*pow(M_PI,2);

    System* twoBodySystem = new System();
    twoBodySystem->printEscape          (true);
    twoBodySystem->setIntegrator        (new VelocityVerlet(twoBodySystem));
    twoBodySystem->setPotential         (new NewtonianGravity(G));
    twoBodySystem->setInitialCondition  (new TwoBody_escape_vel());
    twoBodySystem->setFileWriting       (false);
    twoBodySystem->removeLinearMomentum ();
    twoBodySystem->integrate            (5000);
}

void Examples::mercurySunProblem() {
    double G            = 4*pow(M_PI,2);
    System* mercurySunSystem = new System();
    mercurySunSystem->setIntegrator        (new VelocityVerlet(mercurySunSystem));
    mercurySunSystem->setPotential         (new RelativisticNewtonianGravity(G));
    mercurySunSystem->setInitialCondition  (new MercurySun());
    mercurySunSystem->setDt                (1e-3);
    mercurySunSystem->setFileWriting       (true);
    mercurySunSystem->setFileWritingMercury(true);
    mercurySunSystem->removeLinearMomentum ();
    mercurySunSystem->integrate            (100000);
}
