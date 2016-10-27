#include "exact2x2.h"
#include <cmath>

Exact2x2::Exact2x2()
{

}

double Exact2x2::Energy(double T)
{
    double k = 1.0; // temporary value
    double eightJB = 8*m_J/k/T;
    double E = 8*m_J * (exp(-eightJB) + exp(eightJB))/
            (6 + exp(eightJB) + exp(-eightJB));
    return E;
}
