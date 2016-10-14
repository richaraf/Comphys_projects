#include "examples.h"
#include "system.h"
#include "particle.h"
#include "Integrators/eulercromer.h"
#include "Integrators/velocityverlet.h"
#include "Potentials/newtoniangravity.h"
#include "Potentials/nopotential.h"
#include "InitialConditions/twobody.h"
#include "InitialConditions/threebody.h"
#include "InitialConditions/solarsystem.h"
#include <iostream>
#include <cmath>

void Examples::twoBodyProblem() {
    double G            = 4*pow(M_PI,2);
    double velAnalytic  = 2*M_PI;
    double tolerance    = 1e-2;

    System* twoBodySystem = new System();
    twoBodySystem->setIntegrator        (new EulerCromer(twoBodySystem));
    twoBodySystem->setPotential         (new NewtonianGravity(G));
    twoBodySystem->setInitialCondition  (new TwoBody());
    twoBodySystem->setFileWriting       (true);
    twoBodySystem->testVelocity         (true, velAnalytic, tolerance);
    twoBodySystem->removeLinearMomentum ();
    twoBodySystem->integrate            (5000);
}

void Examples::threeBodyProblem() {
    double G = 4*pow(M_PI,2);

    System* threeBodySystem = new System();
    threeBodySystem->setIntegrator          (new VelocityVerlet(threeBodySystem));
    threeBodySystem->setPotential           (new NewtonianGravity(G));
    threeBodySystem->setInitialCondition    (new ThreeBody());
    threeBodySystem->setFileWriting         (true);
    threeBodySystem->removeLinearMomentum   ();
    threeBodySystem->integrate              (50000);
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
}
