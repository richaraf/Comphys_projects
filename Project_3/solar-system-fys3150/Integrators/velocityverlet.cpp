#include "velocityverlet.h"
#include "../system.h"

VelocityVerlet::VelocityVerlet(System* system)
    : Integrator(system) {
}

std::string VelocityVerlet::getName() {
    return "Velocity Verlet";
}

void VelocityVerlet::integrateOneStep(std::vector<Particle*> particles) {
    /*
     * This is where you should implement the Velocity Verlet algorithm.
     *
     * You should start by impelmenting the Euler-Cromer scheme in the
     * Integrator::EulerCromer class, and then implement the more complicated
     * Velocity Verlet algorithm only after you have a working implementation
     * of Euler-Cromer.
     */
    m_system->computeForces();
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
