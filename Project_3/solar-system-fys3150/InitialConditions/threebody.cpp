#include "threebody.h"
#include "../vec3.h"
#include "../system.h"
#include <cmath>


void ThreeBody::setupParticles(System &system) {
    /*
     *      Particle* p = new Particle(vec3(1,2,3), vec3(4,5,6), 7.0);
     *                                  ^            ^            ^
     *                               Position     Velocity      Mass
     */

    // initial positions for oct 12
    Particle* Sun = new Particle(vec3(0, 0, 0), vec3(0,0,0), 1.0);

    //Earth initial velocity[AU/yr] and mass in masses of sun
    Particle* Earth= new Particle(vec3(1,0,0), vec3(0, 2*M_PI, 0), pow(10,-6));

    //Jupiter
    Particle* Jupiter = new Particle(vec3(0, 5.2, 0), vec3(2.755, 0, 0), pow(10,-3));

    system.addParticle(Sun);
    system.addParticle(Earth);
    system.addParticle(Jupiter);
}

std::string ThreeBody::getName() {
    return "Three-body";
}
