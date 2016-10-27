#include "threebody.h"
#include "../vec3.h"
#include "../system.h"
#include <cmath>


void ThreeBody::setupParticles(System &system) {
    /*
     * This is where you should implement the initialization of a three-body
     * system.
     *
     * You should start by impelmenting the two-body scheme in the
     * InitialiCondition::TwoBody class, and then implement the more
     * complicated three-body initialization only after you have a working
     * implementation of the two-body case.
     */

    //Particle* Sun = new Particle(vec3(0,0,0), vec3(0,0,0), 1.0);
    // initial positions for oct 12
    Particle* Sun = new Particle(vec3(0, 0, 0), vec3(0,0,0), 1.0);

    //Earth initial velocity[AU/yr] and mass in masses of sun
    Particle* Earth= new Particle(vec3(1,0,0), vec3(0, 2*M_PI, 0), pow(10,-6));

    //Jupiter
    Particle* Jupiter = new Particle(vec3(0, 5.2, 0), vec3(2.755, 0, 0), pow(10,0));

    system.addParticle(Sun);
    system.addParticle(Earth);
    system.addParticle(Jupiter);
}

std::string ThreeBody::getName() {
    return "Three-body";
}
