#pragma once
#include "../InitialConditions/initialcondition.h"
#include <string>

class SolarSystem : public InitialCondition {
public:
    SolarSystem() {}
    void setupParticles(class System& system);
    std::string getName();
};
