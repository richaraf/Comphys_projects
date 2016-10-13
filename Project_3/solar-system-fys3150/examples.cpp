#include "examples.h"
#include "system.h"
#include "particle.h"
#include "Integrators/eulercromer.h"
#include "Integrators/velocityverlet.h"
#include "Potentials/newtoniangravity.h"
#include "Potentials/nopotential.h"
#include "InitialConditions/twobody.h"
#include "InitialConditions/threebody.h"
#include <iostream>
#include <cmath>
#include <math.h>


void Examples::twoBodyProblem() {
    double G = 4*pow(M_PI,2);

    System* twoBodySystem = new System();
    twoBodySystem->setIntegrator        (new VelocityVerlet(twoBodySystem));
    twoBodySystem->setPotential         (new NewtonianGravity(G));
    twoBodySystem->setInitialCondition  (new TwoBody());
    twoBodySystem->setFileWriting       (true);
    twoBodySystem->removeLinearMomentum ();
    twoBodySystem->integrate            (5000);
}

void Examples::threeBodyProblem() {
    double G = 4*pow(M_PI,2);

    System* threeBodySystem = new System();
    threeBodySystem->setIntegrator          (new EulerCromer(threeBodySystem));
    threeBodySystem->setPotential           (new NewtonianGravity(G));
    threeBodySystem->setInitialCondition    (new ThreeBody());
    threeBodySystem->setFileWriting         (true);
    threeBodySystem->removeLinearMomentum   ();
    threeBodySystem->integrate              (5000);
}
