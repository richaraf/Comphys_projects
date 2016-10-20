#include "nopotential.h"

std::string NoPotential::getName() {
    return "No potential";
}

void NoPotential::computeForces(Particle&, Particle&) {
}
