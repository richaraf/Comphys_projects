#include "velocityverlet.h"
#include "../system.h"

VelocityVerlet::VelocityVerlet(System* system)
    : Integrator(system) {
}

std::string VelocityVerlet::getName() {
    return "Velocity Verlet";
}

void VelocityVerlet::integrateOneStep(std::vector<Particle*> particles) {
    if (m_firstStep) {
        m_system->computeForces();
        m_firstStep = false;
    }

    for (int i=0; i<particles.size(); i++) {
        Particle* p = particles.at(i);
        p->getVelocity() += p->getForce()*m_dt/2.0/p->getMass();
        p->getPosition() += p->getVelocity()*m_dt;
    }

    m_system->computeForces();
    for (int i=0; i<particles.size(); i++) {
        Particle* p = particles.at(i);
        p->getVelocity() += p->getForce()*m_dt/2.0/p->getMass();
    }
}
