#include <armadillo>
#include <iostream>
#include <jacobian_rotation.cpp>

using namespace arma;
using namespace std;

int main(){

    int N = 2;

    //Lager rho-arrayen
    double* rho = new double[N+1];
    rho[0] = 0.0;
    rho[N] = 1000.0; //Approx infinity

    double h; h = (rho[N] - rho[0])/(N+1); //N+1 eller N?

    //Lager rho, looper til N-1
    for(int i = 1; i < N; i++)
    {
        rho[i] = rho[0] + i*h;
    }

    //Setter opp A, poensialmatrisen
    //A har dimensjonene (N-1)x(N-1), siden vi ikke skal lose problemet for endepunktene
    mat A = zeros<mat>(N-1, N-1);

    for(int i=0; i<N; i++)
    {
        A(i,i) = 2.0/pow(h,2) + pow(rho[i+1],2);

        if(i < (N-1))
        {
            A(i,i+1) = -1/pow(h,2);
        }

        if (i < (N-1))
        {
            A(i+1,i) = -1/pow(h,2);
        }
    }

    //Setter opp egenvektor-matrisen R, denne starter som I, hei
    mat R = zeros<mat>(N-1, N-1);

    for(int i=0; i<N; i++)
    {
        R(i,i) = 1.0;
    }

    return 0;
}
