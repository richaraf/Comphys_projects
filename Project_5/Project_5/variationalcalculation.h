#pragma once
#include<vec3.h>

//double Psi_T1(vec3 r_1, vec3 r_2, double alpha, double omega);
//double E_L1(vec3 r_1, vec3 r_2, double alpha, double omega);
void VariationalMethod(double omega, int N, int trialversion, double alpha, double beta, std::string fileName);
