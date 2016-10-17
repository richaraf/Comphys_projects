#pragma once
#include "../InitialConditions/initialcondition.h"
#include "../particle.h"
#include <vector>
#include <string>


class TwoBody_escape_vel : public InitialCondition {
public:
    TwoBody_escape_vel() {}
    void setupParticles(class System& system);
    std::string getName();
};
