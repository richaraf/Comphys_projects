#include "twobody_escape_vel.h"
#include "../vec3.h"
#include "../system.h"
#include <cmath>


void TwoBody_escape_vel::setupParticles(System &system) {
    /*
    *Class for testing escape velocities
     */

    // initial positions for oct 12
    Particle* largeBody = new Particle(vec3(3.571526865010806E-03, 3.389038138932890E-03, 0), vec3(-1.970078468466432E-06, 6.846218005095042E-06, 0)*365.25, 1.0);
    //Earth initial velocity[AU/yr] and mass
    Particle* smallBody = new Particle(vec3(1,0,0), vec3(0, 8.89, 0), 0.000001);
    system.addParticle(largeBody);
    system.addParticle(smallBody);
}

std::string TwoBody_escape_vel::getName() {
    return "Two-body_escape_vel";
}
