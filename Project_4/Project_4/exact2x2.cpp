#include "exact2x2.h"
#include <cmath>

Exact2x2::Exact2x2()
{

}

double Exact2x2::PartitionFunction(double T)
{
    double eightJB = m_eightJk/T;
    double Z = 2*(6 + exp(eightJB) + exp(-eightJB));
    return Z;
}

double Exact2x2::Energy(double T)
{
    double eightJB = m_eightJk/T;
    double E = 8*m_J * (exp(-eightJB) - exp(eightJB))/
            (6 + exp(eightJB) + exp(-eightJB));
    return E;
}

double Exact2x2::EnergySquared(double T)
{
    double eightJB = m_eightJk/T;
    double J = 1.0;
    double E_squared = ((8*J)*(8*J))*(exp(-eightJB) + exp(eightJB))/
            (6 + exp(eightJB) + exp(-eightJB));
    return E_squared;
}

double Exact2x2::MagneticMomentSquared(double T)
{
    double eightJB = m_eightJk/T;
    double M_squared = 16*(exp(eightJB) + 1)/(6 + exp(eightJB) + exp(-eightJB));
    return M_squared;
}

double Exact2x2::HeatCapacity(double E_squared, double E, double T)
{
    double Cv = (E_squared - E*E)/(T*T);
    return Cv;
}

double Exact2x2::Susceptibility(double M_squared, double M, double T)
{
    double X = (M_squared - M*M)/T;
    return X;
}
