#include "twobody.h"
#include "../vec3.h"
#include "../system.h"
#include <cmath>


void TwoBody::setupParticles(System &system) {
    /*
     *      Particle* p = new Particle(vec3(1,2,3), vec3(4,5,6), 7.0);
     *                                  ^            ^            ^
     *                               Position     Velocity      Mass
     */

    // initial positions for oct 12
    Particle* largeBody = new Particle(vec3(0, 0, 0), vec3(0, 0, 0), 1.0);
    //Earth initial velocity[AU/yr] and mass
    Particle* smallBody = new Particle(vec3(1,0,0), vec3(0, 2*M_PI, 0), 0.000001);
    system.addParticle(largeBody);
    system.addParticle(smallBody);
}

std::string TwoBody::getName() {
    return "Two-body";
}
