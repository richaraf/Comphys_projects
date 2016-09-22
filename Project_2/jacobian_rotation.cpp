#include <armadillo>
using namespace arma;
using namespace std;
// Jacobi rotation function which takes matrix A, eigenvector matrix R, row k, coloumn l, number of iterations N.
void Jacobi_rotate(mat A, mat R, int k, int l, int N)
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
    A(k,k) = A(k,k)*c*c - 2*A(k,l)*c*s + A(l,l)*s*s;
    A(l,l) = A(l,l)*c*c + 2*A(k,l)*c*s + A(k,k)*s*s;
    A(k,l) = A(l,k) = 0; // Set the previously biggest elements to 0
    for (int i = 0; i < N-1; i++){
        if (i != k && i != l) {
            A(i,k) = A(i,k)*c - A(i,l)*s;
            A(i,l) = A(i,l)*c + A(i,k)*s;
            A(k,i) = A(i,k);
            A(l,i) = A(i,l);
        }
    }
}
