#include "lattice.h"
#include <armadillo>

using namespace std;
using namespace arma;

Lattice::Lattice()
{

}

void Lattice::makeLattice(mat &R, bool random, int L){
    /* The LxL lattice is set up as a L+2xL+2 matrix
     * where we use Periodic Boundary Conditions */

    srand(time(NULL));
    if(random==true){
        for(int i=1; i < L+1; i++){
            for(int j=1; j < L+1; j++){
                //Fill matrix randomly
                int x = rand()%2; //trekker tall mellom 0 og 1
                if(x==1){
                    R(i,j) = 1;
                }
                else{
                    R(i,j) = -1;
                }
            }
        }
    }
    else{
        for(int i=1; i < L+1; i++){
            for(int j=1; j < L+1; j++){
                //Fill ordered matrix
                R(i,j) = 1;
            }
        }
    }
    //Give Periodic Boundary Conditions
    for(int i=0; i < L; i++){
        for(int j=0; j < L; j++){
            R(0,j+1) = R(L, j+1);
            R(i+1,0) = R(i+1, L);
            R(L+1,j+1) = R(1, j+1);
            R(i+1,L+1) = R(i+1,1);
        }
    }
}
