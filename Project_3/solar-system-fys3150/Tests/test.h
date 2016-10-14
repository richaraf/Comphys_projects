#pragma once
#include <vector>
#include <string>
#include "../particle.h"
#include <cmath>

class Test {
protected:
    double          m_velAnalytical        = 2*M_PI;
    class System*   m_system    = nullptr;

public:
    Test(class System* system);
    double get_analytical() { return m_velAnalytical; }
    virtual std::string getName();
    virtual void velocitytest(std::vector<Particle*> particles) = 0;
};
