#pragma once
#include "../InitialConditions/initialcondition.h"
#include "../particle.h"
#include <vector>
#include <string>


class MercurySun : public InitialCondition {
public:
    MercurySun() {}
    void setupParticles(class System& system);
    std::string getName();
};

