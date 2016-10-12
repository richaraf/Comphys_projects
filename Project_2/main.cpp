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

    int N = 350;
    clock_t start1, finish1, start2, finish2;


    double* rho = new double[N+1];
    rho[0] = 0.0;
<<<<<<< HEAD
    rho[N] = 50.0; //Approx infinity
    double omega = 0.01;
=======
    rho[N] = 15.0; //Approx infinity
    double omega = 0.25;
>>>>>>> 8d0630bd6dc461712c6b0161af166b500a8f7f06

    double h = (rho[N] - rho[0])/N;

    //Makes rho
    for(int i = 1; i < N; i++)
    {
        rho[i] = rho[0] + i*h;
    }

    //Setting up A, potential matrix
    mat A = zeros<mat>(N-1, N-1);

    for(int i=0; i<N-1; i++)
    {
        A(i,i) = 2.0/pow(h,2) + potential_two_e_interact(rho[i+1], omega); //Change this to solve for two electrons

        if(i < (N-2))
        {
            A(i,i+1) = -1/pow(h,2);
            A(i+1,i) = -1/pow(h,2);
        }

    }

    //Setting up R, eigenvector matrix
    mat R = zeros<mat>(N-1, N-1);
    for(int i=0; i<N-1; i++)
    {
        R(i,i) = 1.0;
    }

    //Eigvec/-vals from Armadillo
    start2 = clock();
    vec eigval;
    mat eigvec;

    eig_sym(eigval, eigvec, A);
    finish2 = clock();

    int kmax; int lmax;
    double eps = pow(10,-8);
    int max_iteration = 1000000;
    int iteration = 0;

    start1 = clock();
    //Finding largest non-diagonal element
    largest_akl_func(A, &kmax, &lmax);

    while ( abs(A(kmax, lmax)) > eps && iteration < max_iteration)
    {
        iteration += 1;
        Jacobi_rotate(A, R, kmax, lmax, N);
        largest_akl_func(A, &kmax, &lmax);
    }
    finish1 = clock();

<<<<<<< HEAD
    //Henter ut egenverdiene
=======
    cout << iteration << endl;

    //Saves the eigenvalues
>>>>>>> 8d0630bd6dc461712c6b0161af166b500a8f7f06
    vec lambda = diagvec(A);

    cout << "Run time program: " << (finish1-start1)/float(CLOCKS_PER_SEC) << "s" << endl;
    cout << "Run time armadillo: " << (finish2-start2)/float(CLOCKS_PER_SEC) << "s" << endl;

    // Check orthogonality
    orthogonality_check_func(R, eps);

    //Test largest_akl_func
    test_largest_akl(3,4);

    //Fix the boundary conditions, u0 = uN = 0
    mat U = zeros<mat>(N+1, N-1);

    for(int i = 0; i < N-1; i++)
    {
        for(int j=0; j < N-1; j++)
        {
            U(i+1,j) = R(i,j);
        }
    }

    //Indentify the tree lowest eigenstates
    int k_min = 0;
    int k_2_min = 0;
    int k_3_min = 0;

    double lambda_min = 1000.0;
    double lambda_2_min = 1000.0;
    double lambda_3_min = 1000.0;

    for(int k=0; k < N-1; k++)
    {
        if(lambda[k] < lambda_min)
        {
            lambda_3_min = lambda_2_min;
            lambda_2_min = lambda_min;
            lambda_min = lambda[k];
            k_3_min = k_2_min;
            k_2_min = k_min;
            k_min = k;
        }
        if(lambda[k] < lambda_2_min && lambda[k] > lambda_min)
        {
            lambda_3_min = lambda_2_min;
            lambda_2_min = lambda[k];
            k_3_min = k_2_min;
            k_2_min = k;
        }
        if(lambda[k] < lambda_3_min && lambda[k] > lambda_2_min)
        {
            lambda_3_min = lambda[k];
            k_3_min = k;
        }

    }

<<<<<<< HEAD
    //cout << k_min << "  " << k_2_min << "  " << k_3_min << endl;
    cout << lambda[k_min] << "  " << lambda[k_2_min] << "  " << lambda[k_3_min] << endl;

=======
>>>>>>> 8d0630bd6dc461712c6b0161af166b500a8f7f06
    ofstream myfile_1;
    myfile_1.open("../lambda_file.txt");
    for(int i= 0; i < lambda.n_rows; i++)
    {
        myfile_1 << lambda[i] << "  ";
    }
    myfile_1.close();

    //Extract the lowest states
    vec eigvec_1 = U.col(k_min);
    vec eigvec_2 = U.col(k_2_min);
    vec eigvec_3 = U.col(k_3_min);

<<<<<<< HEAD
//Write to file when plotting three lowest wavefunc
//    ofstream myfile_2;
//    myfile_2.open("../u_file_.txt");
=======
//Write to file when plotting the three lowest wavefunc
//    ofstream myfile_2;
//    myfile_2.open("../u_file.txt");
>>>>>>> 8d0630bd6dc461712c6b0161af166b500a8f7f06
//    for(int i=0; i < N+1; i++)
//    {
//        myfile_2 << eigvec_1[i] << " " << eigvec_2[i] << " " << eigvec_3[i] << endl;
//    }

//    myfile_2.close();
<<<<<<< HEAD

//    return 0;
=======

    ofstream myfile_variables;
    myfile_variables.open("../variable_file.txt");
    myfile_variables << rho[N] << endl;
    myfile_variables << omega << endl;
    myfile_variables.close();

    //When only plotting the groundstate
    ofstream myfile_groundstate;
    myfile_groundstate.open("../u_interact.txt"); //Change to u_noninteract.txt when non-interacting case
    for(int i=0; i < N+1; i++)
    {
        myfile_groundstate << eigvec_1[i] << endl;

    }
    myfile_groundstate.close();
>>>>>>> 8d0630bd6dc461712c6b0161af166b500a8f7f06

    //Write to file the value of rho_max and omega, and the ground state of the system
    ofstream myfile_variables;
    myfile_variables.open("../variable_file.txt");
    myfile_variables << rho[N] << endl;
    myfile_variables << omega << endl;
    myfile_variables.close();

    ofstream myfile_groundstate;
    myfile_groundstate.open("../u_interact.txt");
    for(int i=0; i < N+1; i++)
    {
        myfile_groundstate << eigvec_1[i] << endl;
    }
    myfile_groundstate.close();
}
