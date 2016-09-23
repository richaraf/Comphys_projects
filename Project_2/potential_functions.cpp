#include <potential_functions.h>

//Functions that calculate the potential for one/two electrons
double potential_one_e(double rho)
{
    return pow(rho, 2);
}

double potential_two_e(double rho, double omega)
{
    return pow(omega,2)*rho + 1.0/pow(rho,2);
}
