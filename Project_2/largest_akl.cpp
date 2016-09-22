#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

void largest_akl(mat A,int* kmax, int* lmax){
    int N = A.n_rows;           //Finding size N of A
    double max = 0;             //Counter
    for(int k = 0; k < N; k++){
        for(int l = 0; l < N; l++){
            if(A(k,l) >= max){
                cout << "g" << endl;
                *kmax = k;
                *lmax = l;
                cout << "h" << endl;
                max = A(k,l);
            }
        }
    }
}

int main()
{
    int kmax; int lmax;
    //Calling the function that creates A
    largest_akl(A, &kmax, &lmax);   //Sending the adress of lmax
                                    //and kmax to the function
    /* Now we should have the indexes of the largest
     * non-diagonal element Akl stored as kmax and
     * lmax */
    cout << lmax << " " << kmax << endl;
    return 0;
}

