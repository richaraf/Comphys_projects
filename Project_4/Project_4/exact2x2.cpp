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
    double E = 8*m_J * (exp(-eightJB) + exp(eightJB))/
            (6 + exp(eightJB) + exp(-eightJB));
    return E;
}
