#include <iostream>
#include "lattice.h"
#include "exact2x2.h"
#include <numerical2.h>
#include <time.h>
#include <iomanip>

using namespace std;

int main()
{
    int L = 20;

    if(L==2){
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
    }
    double X = 0;
    double Cv = 0;

    // Start timer
    clock_t start, finish;
    start = clock();

    //Numerical2(susceptibility, heat capacity, number of sweeps,
    //           beta, size of system, spin ordered randomly)

    Numerical2(&X, &Cv, 1e8, 1.0, L, true);

    // End timer
    finish = clock();
    ((finish-start)/CLOCKS_PER_SEC);
    double timeused = (double) (finish - start)/(CLOCKS_PER_SEC );

    cout << "X: " << X << endl;
    cout << "Cv: " << Cv << endl;

    cout << setiosflags(ios::showpoint | ios::uppercase);
    cout << setprecision(10) << setw(20) << "Time used = " << timeused  << endl;

}
