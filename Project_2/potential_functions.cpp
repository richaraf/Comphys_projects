#include <potential_functions.h>

double potential_one_e(double rho)
{
    return pow(rho, 2);
}

double potential_two_e_interact(double rho, double omega)
{
    return pow(omega,2)*pow(rho,2) + 1.0/rho;
}

double potential_two_e_noninteract(double rho, double omega)
{
    return pow(omega,2)*pow(rho,2);
}
