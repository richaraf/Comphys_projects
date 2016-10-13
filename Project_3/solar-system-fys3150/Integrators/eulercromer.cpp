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
        //std::cout << p->getVelocity() << std::endl; // check to see what prints
        //std::cout << p->getPosition();// << std::endl;
        double x = p->getPosition()(0);
        double y = p->getPosition()(1);
        double vx = p->getVelocity()(0);
        double vy = p->getVelocity()(1);
        vx += -m_dt*p->getForce()(0);
        x += vx*m_dt;

        vy += -m_dt*p->getForce()(1);
        y += vy*m_dt;

        //std::cout << x << ' ';
        //std::cout << vx << std::endl;
        p->getPosition() = vec3(x,y,0);
        p->getVelocity() = vec3(vx,vy,0);
        //std::cout << 'posistion: ' << p->getPosition() << std::endl;
        //std::cout << 'velocity: ' << p->getVelocity() << std::endl;
        /*
         * This is where you need to update the positions and the velocities
         * and the velocities of each particle according to the Euler-Cromer
         * scheme.
         *
         * You can access the position of particle number i by
         *
         *      p->getPosition()
         *
         * Remember that the positions and velocities of all the particles are
         * vec3 vectors, which you can use the +=, -=, etc. operators on.
         */
    }
}

std::string EulerCromer::getName() {
    return "Euler-Cromer";
}
