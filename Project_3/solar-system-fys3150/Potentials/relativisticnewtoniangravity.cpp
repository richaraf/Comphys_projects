#include "relativisticnewtoniangravity.h"
#include <iostream>
#include <cmath>

RelativisticNewtonianGravity::RelativisticNewtonianGravity(double G) : m_G(G) {
}

void RelativisticNewtonianGravity::computeForces(Particle& a, Particle& b) {
    vec3 dr = a.getPosition()-b.getPosition();
    double c = 63239.7263;
    double drlength = dr.length();
    double drlength2 = dr.lengthSquared();
    double dFx = m_G*(a.getMass()*b.getMass())/(drlength*drlength2)*dr(0)*(1+ (3*(dr.cross(b.getVelocity())).lengthSquared())/(drlength2*pow(c,2)));
    double dFy = m_G*(a.getMass()*b.getMass())/(drlength*drlength2)*dr(1)*(1+ (3*(dr.cross(b.getVelocity())).lengthSquared())/(drlength2*pow(c,2)));
    double dFz = 0.0;
    double V = -m_G*(a.getMass()*b.getMass())/drlength;
    m_potentialEnergy += V;
    a.addForce(-dFx, -dFy, -dFz);
    b.addForce(dFx,dFy,dFz);
    //std::cout << -m_G*(a.getMass()*b.getMass())/(drlength*drlength2)*b.getPosition()(0)*((3*(dr.cross(b.getVelocity())).lengthSquared())/(drlength2*pow(c,2))) << std::endl;
}

std::string RelativisticNewtonianGravity::getName() {
    return "Relativistic Newtonian gravity";
}
