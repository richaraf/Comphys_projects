#pragma once
#include <armadillo>
#include <mpi.h>
using namespace arma;
using namespace std;
void Numerical2(long int T, double beta, int L, bool random, int my_rank, mat &local_expectation_values);
