#pragma once
#include <armadillo>

using namespace arma;

double potential_one_e(double rho);
double potential_two_e_interact(double rho, double omega);
double potential_two_e_non_interact(double rho, double omega);
