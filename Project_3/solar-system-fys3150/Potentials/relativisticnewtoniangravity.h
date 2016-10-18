#pragma once
#include "particle.h"
#include "potential.h"
#include <string>

class RelativisticNewtonianGravity : public Potential {
private:
    double m_G;

public:
    RelativisticNewtonianGravity(double G);
    void computeForces(Particle& a, Particle& b);
    std::string getName();
};
