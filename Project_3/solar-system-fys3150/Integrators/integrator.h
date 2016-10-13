#pragma once
#include <vector>
#include <string>
#include "../particle.h"
#include <cmath>

class Integrator {
protected:
    double          m_dt        = 1e-3;
    double          m_dt2       = pow(m_dt,2);
    class System*   m_system    = nullptr;

public:
    Integrator(class System* system);
    void setDt(double dt);
    double getDt() { return m_dt; }
    virtual std::string getName();
    virtual void integrateOneStep(std::vector<Particle*> particles) = 0;
};
