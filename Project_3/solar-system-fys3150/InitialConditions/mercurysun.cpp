#include "mercurysun.h"
#include "../vec3.h"
#include "../system.h"
#include <cmath>


void MercurySun::setupParticles(System &system) {


    // initial positions for oct 12
    Particle* largeBody = new Particle(vec3(0,0,0), vec3(0,0,0), 1.0);
    //Earth initial velocity[AU/yr] and mass
    Particle* smallBody = new Particle(vec3(0.3075,0,0), vec3(0, 12.44, 0), 1.660511409E-07);
    system.addParticle(largeBody);
    system.addParticle(smallBody);
}

std::string MercurySun::getName() {
    return "Mercury-Sun";
}

