#include "twobody_escape_vel.h"
#include "../vec3.h"
#include "../system.h"
#include <cmath>


void TwoBody_escape_vel::setupParticles(System &system) {
    /*
    *Class for testing escape velocities
     */

    // initial positions for oct 12
    Particle* largeBody = new Particle(vec3(0, 0, 0), vec3(0, 0, 0), 1.0);
    //Earth initial velocity[AU/yr] and mass
    Particle* smallBody = new Particle(vec3(1,0,0), vec3(0, 8.887, 0), 0.000001);
    system.addParticle(largeBody);
    system.addParticle(smallBody);
}

std::string TwoBody_escape_vel::getName() {
    return "Two-body_escape_vel";
}
