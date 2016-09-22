#include <iostream>
#include <armadillo>
#include <largest_akl.h>

using namespace std;
using namespace arma;

void largest_akl_func(mat A,int* kmax, int* lmax){
    int N = A.n_rows;           //Finding size N of A
    double max = 0;             //Counter
    for(int k = 0; k < N; k++){
        for(int l = 0; l < N; l++){
            if(k != l){
                if(A(k,l) >= max){
                    *kmax = k;
                    *lmax = l;
                    max = A(k,l);
                }
            }
        }
    }
}
