#pragma once
#include "vec3.h"


class WaveFunction
{
private:
    int                         m_trialversion = 0;
public:
    WaveFunction() {}
    int setTrialWF              (int trialversion);
    double Psi_value(vec3 r_1, vec3 r_2, double alpha, double omega, double beta);
    double E_L(vec3 r_1, vec3 r_2, double alpha, double omega, double beta);

};
