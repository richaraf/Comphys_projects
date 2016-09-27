#include <largest_akl.h>
#include <armadillo>
#include <iostream>

using namespace std;
using namespace arma;

void test_largest_akl(int k, int l){
    int N;
    //Check if the element is located on the diagonal
    if(k == l){
        throw  invalid_argument("Value Error: k and l cannot have the same value");
    }
    //Making a matrix big enough to include element (k,l)
    else if(k >= l){
        N = k;
    }
    else{
        N = l;
    }
    mat A = zeros<mat>(N+1,N+1);

    //Place the largest element at index (k,l)
    A(k,l) = 1;

    //Store the old k and l
    int k_old = k;
    int l_old = l;

    largest_akl_func(A, &k, &l);

    /* Test if largest_akl_func found the
     * largest element at index (k_old, l_old) */
    if(k != k_old && l != l_old){
        throw invalid_argument("Error: largest_akl_func failed");
    }
}

