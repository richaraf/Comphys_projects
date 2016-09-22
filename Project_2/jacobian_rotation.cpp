using namespace arma;
using namespace std;
// Jacobi rotation function which takes matrix A, eigenvector matrix R, row k, coloumn l, number of iterations N.
void Jacobi_rotation(mat A, mat R, int k, int l, int N)
{
    double s, c; // s = sin theta, c = cos theta
    double t, tau; // t = tan theta, tau = cos (2*theta)
    // find the "angles"
    if ( A(k,l) != 0)
    {
        tau = (A(l,l) - A(k,k))/(2*A(k,l));
        if (tau >= 0)
        {
            t = 1.0/(tau + sqrt(1.0 + pow(tau,2.0)));
        }
        else
        {
            t = -1.0/(-tau + sqrt(1 + pow(tau,2.0)));
        }
        c = 1.0/sqrt(1 + pow(t,2.0));
        s = c*t;
    }
    else
    {
        c = 1.0;
        s = 0.0;
    }
    // Perform the rotation
    A(k,k) = A(k,k)*c*c - 2*A(k,l)*c*s + A(l,l)*s*s;
}
