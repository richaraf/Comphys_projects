#include <potential_functions.h>

double potential_one_e(double rho)
{
    return pow(rho, 2);
}

double potential_two_e_interact(double rho, double omega)
{
    return pow(omega,2)*pow(rho,2) + 1.0/rho;
}

<<<<<<< HEAD
double potential_two_e_non_interact(double rho, double omega)
=======
double potential_two_e_noninteract(double rho, double omega)
>>>>>>> 8d0630bd6dc461712c6b0161af166b500a8f7f06
{
    return pow(omega,2)*pow(rho,2);
}
