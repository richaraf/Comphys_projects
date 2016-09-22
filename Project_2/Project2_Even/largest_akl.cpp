#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

void largest_akl(mat A,int *kmax, int *lmax){
    int N = A.n_rows;           //Finding size N of A
    double max = 0;             //Counter
    for(int k = 0; k < N-1; k++){
        for(int l = 0; l < N-1; l++){
            if(A(k,l) >= max){
                *lmax = k;
                *kmax = l;
            }
        }
    }
}


int main()
{
    int *kmax; int *lmax;
    //Calling the function that creates A
    mat A = zeros<mat>(2,2);
    A(0,0)=1;A(0,1)=2;A(1,0)=3;A(1,1)=4;
    largest_akl(A, *kmax, *lmax);
    /* Now we should have the indexes of the largest
     * non-diagonal element Akl stored as kmax and
     * lmax */
    return 0;
}

