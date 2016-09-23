#include <armadillo>
#include <jacobian_rotation.h>
#include <iomanip>

using namespace arma;
using namespace std;
// Jacobi rotation function which takes matrix A, eigenvector matrix R, row k, column l, number of iterations N.
void Jacobi_rotate(mat &A, mat &R, int k, int l, int N)
{
    double s, c; // s = sin theta, c = cos theta
    double t, tau; // t = tan theta, tau = cos (2*theta)
    // find the "angles"
    if ( A(k,l) != 0)
    {
        tau = (A(l,l) - A(k,k))/(2*A(k,l));
        if (tau >= 0)
        {
            t = 1.0/(tau + sqrt(1.0 + tau*tau));
        }
        else
        {
            t = -1.0/(-tau + sqrt(1 + tau*tau));
        }
        c = 1.0/sqrt(1 + t*t);
        s = c*t;
    }
    else
    {
        c = 1.0;
        s = 0.0;
    }

    // Perform the rotation
    double akk = A(k,k);
    A(k,k) = A(k,k)*c*c - 2*A(k,l)*c*s + A(l,l)*s*s;
    A(l,l) = A(l,l)*c*c + 2*A(k,l)*c*s + akk*s*s;
    A(k,l) = A(l,k) = 0; // Set the previously biggest elements to 0
    for (int i = 0; i < N-1; i++){
        if (i != k && i != l) {
            double aik = A(i,k);
            A(i,k) = A(i,k)*c - A(i,l)*s;
            A(i,l) = A(i,l)*c + aik*s;

            A(k,i) = A(i,k);
            A(l,i) = A(i,l);
        }
        // Change of the column i row k and l for the eigenvector matrix
        double r_il = R(i,l);
        double r_ik = R(i,k);
        R(i,l) = c*r_il + s*r_ik;
        R(i,k) = -s*r_il + c*r_ik;
    }
/*
    mat S = zeros<mat>(N-1,N-1);
    for( int i=0; i<N-1; i++){
        S(i,i)=1.0;
    }
    S(k,l) = -s; S(l,k) = s;
    S(k,k) = c; S(l,l) = c;

//    vec w = zeros<vec>(N-1);
//    for( i = 0; i < N-1; i++){
//        for( j = 0; j < N-1; j++){
//            w[i]=
//        }
//    }
*/
}
