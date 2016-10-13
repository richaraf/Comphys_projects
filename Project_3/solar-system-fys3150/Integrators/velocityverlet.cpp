#include "velocityverlet.h"
#include "../system.h"

VelocityVerlet::VelocityVerlet(System* system)
    : Integrator(system) {
}

std::string VelocityVerlet::getName() {
    return "Velocity verlet";
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


    /*for (int i=0; i<particles.size(); i++) {
        Particle *p = particles.at(i);
        double x = p->getPosition()(0);
        double y = p->getPosition()(1);
        //double z = p->getPosition()(2);
        double vx = p->getVelocity()(0);
        double vy = p->getVelocity()(1);
        //double vz = p->getVelocity()(2);
        vec3 force = p->getForce();
        /*x += x + vx*m_dt+0.5*((m_dt2*force(0))/(p->getMass()));
        y += y + vy*m_dt+0.5*((m_dt2*force(1))/(p->getMass()));
        p->getPosition() = vec3(x,y,0);
        vx += vx + 0.5*(force(0) + p->getForce()(0))*m_dt;
        vy += vy + 0.5*(force(1) + p->getForce()(1))*m_dt;

        p->getPosition() = vec3(x,y,0);
        p->getVelocity() = vec3(vx,vy,0);


        p->getPosition() += p->getVelocity()*dt;
        p->getVelocity() += p->getForce()*dt;


        //vec3 vthalf = p->getVelocity() + m_dt/2* p->getForce()/p->getMass();
        p->getVelocity() += m_dt/2* p->getForce()/p->getMass(); // vhalf
        p->getPosition() += m_dt * p->getVelocity();

        p->getVelocity() += m_dt/2*p->getForce()/p->getMass();

    }*/
}
