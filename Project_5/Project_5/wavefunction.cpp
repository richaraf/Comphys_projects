#include "wavefunction.h"
#include <cmath>
#include <iostream>

using namespace std;


int WaveFunction::setTrialWF(int trialversion)
{
    m_trialversion = trialversion;
}

double WaveFunction::Psi_value(vec3 r_1, vec3 r_2, double alpha, double omega, double beta)
{
    double r12 = (r_1-r_2).length();
    double psi = exp(-alpha*omega*(r_1.lengthSquared() + r_2.lengthSquared())/2.0);
    if(m_trialversion==1){
        return psi;
    }
    if (m_trialversion==2){
        return psi*exp(r12/(2*(1+beta*r12)));
    }

}

double WaveFunction::E_L(vec3 r_1, vec3 r_2, double alpha, double omega, double beta)
{
    double E = 0.5*omega*omega*(r_1.lengthSquared() + r_2.lengthSquared())*(1.0-alpha*alpha) + 3*alpha*omega;
    if (m_trialversion==1){
        return E;
    }/*
    if (m_trialversion==2){
        return
    }*/
}
