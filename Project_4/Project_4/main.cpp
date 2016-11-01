#include <iostream>
#include "lattice.h"
#include "exact2x2.h"
#include<numerical2.h>

using namespace std;

int main()
{
    Exact2x2 exact; // bruker foreløpig J = k = T = 1.0
    double E = exact.Energy(1.0);
    double E_squared = exact.EnergySquared(1.0);
    double M = exact.MagneticMoment();
    double M_squared = exact.MagneticMomentSquared(1.0);
    double Cv_exact = exact.HeatCapacity(E_squared, E, 1.0);
    double X_exact = exact.Susceptibility(M_squared, M, 1.0);
    cout << "Exact energy for 2x2, E = " << E << endl;
    cout << "Exact energy  squared for 2x2, E*E = " << E_squared << endl;
    cout << "Exact magnetic moment for 2x2, M = " << M << endl;
    cout << "Exact magnetic moment squared for 2x2, M*M = " << M_squared << endl;
    cout << "Exact heat capacity for 2x2 Cv = " << Cv_exact << endl;
    cout << "Exact susceptibility for 2x2 X = " << X_exact << endl;

    double X = 0;
    double Cv = 0;
    Numerical2(&X, &Cv);
    cout << "X: " << X << endl;
    cout << "Cv: " << Cv << endl;


}
