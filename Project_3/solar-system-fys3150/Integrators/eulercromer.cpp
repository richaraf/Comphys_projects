#include "eulercromer.h"
#include "../system.h"
#include <iostream>

EulerCromer::EulerCromer(System* system)
    : Integrator(system) {
}

void EulerCromer::integrateOneStep(std::vector<Particle*> particles) {
    m_system->computeForces();
    for (int i=0; i<particles.size(); i++) {
        Particle *p = particles.at(i);
        p->getVelocity() += (m_dt*p->getForce())/(p->getMass());
        p->getPosition() += p->getVelocity()*m_dt;
    }
}

std::string EulerCromer::getName() {
    return "Euler-Cromer";
}
