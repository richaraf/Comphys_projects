#include <iostream>
#include <armadillo>
#include <largest_akl.h>

using namespace std;
using namespace arma;

void largest_akl_func(mat A,int* kmax, int* lmax){
    int N;
    if(A.n_cols != A.n_rows){           //Test if A is quadratic
        throw invalid_argument("Error: Matrix is not quadratic");
    }
    else{
        N = A.n_rows;                   //Finds size N of A
    }
    double max = 0;                     //Largest element
    for(int k = 0; k < N; k++){
        for(int l = 0; l < N; l++){
            if(k != l){
                if(abs(A(k,l)) >= max){
                    *kmax = k;
                    *lmax = l;
                    max = abs(A(k,l));
                }
            }
        }
    }
}
