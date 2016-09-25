#include <largest_akl.h>
#include <armadillo>
#include <iostream>

using namespace std;
using namespace arma;

void test_largest_akl(int k, int l){
    int N;
    if(k == l){
        throw  invalid_argument("Value Error: k and l cannot have the same value");
    }
    else if(k >= l){
        N = k;
    }
    else{
        N = l;
    }
    mat A = zeros<mat>(N+1,N+1);

    //Place the largest element at index (k,l)
    A(k,l) = 1;

    //Store the previous k and l
    int k_prev = k;
    int l_prev = l;

    largest_akl_func(A, &k, &l);

    /* Test if largest_akl_func found the
     * largest element at index (k_prev, l_prev) */
    if(k != k_prev && l != l_prev){
        throw invalid_argument("Error: largest_akl_func failed");
    }
}

