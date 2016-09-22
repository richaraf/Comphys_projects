#include <armadillo>
#include <iostream>
#include <jacobian_rotation.h>
#include <largest_akl.h>

using namespace arma;
using namespace std;

int main(){

    int N = 50;

    //Lager rho-arrayen
    double* rho = new double[N+1];
    rho[0] = 0.0;
    rho[N] = 5.0; //Approx infinity

    double h = (rho[N] - rho[0])/N;

    //Lager rho, looper til N-1
    for(int i = 1; i < N; i++)
    {
        rho[i] = rho[0] + i*h;
    }

    //Setter opp A, poensialmatrisen
    //A har dimensjonene (N-1)x(N-1), siden vi ikke skal lose problemet for endepunktene
    mat A = zeros<mat>(N-1, N-1);

    //Looper til N-2
    for(int i=0; i<N-1; i++)
    {
        A(i,i) = 2.0/pow(h,2) + pow(rho[i+1],2);

        if(i < (N-2))
        {
            A(i,i+1) = -1/pow(h,2);
            A(i+1,i) = -1/pow(h,2);
        }

    }

    //Setter opp egenvektor-matrisen R, denne starter som I, hei
    mat R = zeros<mat>(N-1, N-1);
    for(int i=0; i<N-1; i++)
    {
        R(i,i) = 1.0;
    }

    int kmax; int lmax;
    double eps = pow(10,-13); //toleranse
    int max_iteration = 100000;
    int iteration = 0;
    //Calling the function that finds the largest off-diag element a_kl
    largest_akl_func(A, &kmax, &lmax);

    while ( abs(A(kmax, lmax)) > eps && iteration < max_iteration)
    {
        iteration += 1;
        Jacobi_rotate(A, R, kmax, lmax, N);
        largest_akl_func(A, &kmax, &lmax);
    }
<<<<<<< HEAD
=======


    //Henter ut egenverdiene
    vec lambda = diagvec(A);
    lambda = sort(lambda);
    cout << lambda << endl;
    cout << iteration << endl;

>>>>>>> 80cd664e48741c63475768721deb2eadd8463cad
    return 0;
}
