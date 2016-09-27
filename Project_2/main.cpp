#include <armadillo>
#include <iostream>
#include <jacobian_rotation.h>
#include <largest_akl.h>
#include <orthogonality_check.h>
#include <potential_functions.h>
#include <largest_akl_test.h>
#include <ctime>

using namespace arma;
using namespace std;


int main(){

    int N = 10;
    clock_t start1, finish1, start2, finish2;
    start1 = clock();

    //Lager rho-arrayen
    double* rho = new double[N+1];
    rho[0] = 0.0;
    rho[N] = 10.0; //Approx infinity

    double h = (rho[N] - rho[0])/N;

    //Lager rho
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
        A(i,i) = 2.0/pow(h,2) + potential_one_e(rho[i+1]); //Change this to solve for two electrons

        if(i < (N-2))
        {
            A(i,i+1) = -1/pow(h,2);
            A(i+1,i) = -1/pow(h,2);
        }

    }

    //Setter opp egenvektor-matrisen R, denne starter som I
    mat R = zeros<mat>(N-1, N-1);
    for(int i=0; i<N-1; i++)
    {
        R(i,i) = 1.0;
    }

    finish1 = clock();

    start2 = clock();
    cx_vec eigval;
    cx_mat eigvec;

    eig_gen(eigval, eigvec, A);
    finish2 = clock();

    cout << eigvec << endl;

    int kmax; int lmax;
    double eps = pow(10,-13); //toleranse
    int max_iteration = 100000;
    int iteration = 0;

    //Calling the function which finds the largest off-diag element a_kl
    largest_akl_func(A, &kmax, &lmax);

    while ( abs(A(kmax, lmax)) > eps && iteration < max_iteration)
    {
        iteration += 1;
        Jacobi_rotate(A, R, kmax, lmax, N);
        largest_akl_func(A, &kmax, &lmax);
    }

    //Henter ut egenverdiene
    vec lambda = diagvec(A);


    cout << "Run time program: " << (finish1-start1)/float(CLOCKS_PER_SEC) << "s" << endl;
    cout << "Run time armadillo: " << (finish2-start2)/float(CLOCKS_PER_SEC) << "s" << endl;

    // Check orthogonality
    orthogonality_check_func(R, eps);

    //Test largest_akl_func
    test_largest_akl(3,4);


    //Fix the boundary cond, u0 = uN = 0
    mat U = zeros<mat>(N+1, N-1);

    for(int i = 0; i < N-1; i++)
    {
        for(int j=0; j < N-1; j++)
        {
            U(i+1,j) = R(i,j);
        }
    }

    cout << U << endl;

    ofstream myfile_1;
    myfile_1.open("../lambda_file.txt");
    for(int i= 0; i < lambda.n_rows; i++)
    {
        myfile_1 << lambda[i] << "  ";
    }
    myfile_1.close();

    ofstream myfile_2;
    myfile_2.open("../u_file.txt");
    for(int i=0; i < U.n_rows; i++)
    {
        myfile_2 << U.row(i);
    }

    myfile_2.close();

return 0;

}
