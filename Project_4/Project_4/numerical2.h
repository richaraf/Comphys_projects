#pragma once
#include <armadillo>
using namespace arma;
using namespace std;
void Numerical2(double *X, double *Cv, int T, double beta, int L, bool random, int my_rank, vec local_expectation_values);
