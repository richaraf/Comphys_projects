#include <numerical2.h>
#include <armadillo>
#include <random>
#include<cstdlib>
#include<time.h>

using namespace std;
using namespace arma;
double Numerical2(){
    int N = 5;
    int T = 1;
    double beta = 1.0;
    srand(time(NULL));

    mat R = zeros<mat>(N, N);
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            int x = rand()%2; //trekker tall mellom 0 og 1
            if(x==1){
                R(i,j) = 1;
            }
            else{
                R(i,j) = -1;
            }
        }
    }

    //Calculate energy
//    int E_tot = 0; //Energy of T microstates added together
    //int E = 0; //Energy of one microstate

//    for(int i=0; i<N; i++){
//        for(int j=0; j<N; j++){
//            if(i==0 && j==0){
//                int E_1 = R(0,0)*R(0,1) + R(0,0)*R(1,0) + R(0,0)*R(0,1) + R(0,0)*R(1,0);
//                E += E_1;
//                //cout << E_1 << endl;
//            }
//            if(i==0 && j==1){
//                int E_2 = R(0,1)*R(1,1) + R(0,1)*R(1,1);
//                E += E_2;
//                //cout << E_2 << endl;
//            }
//            if(i==1 && j==1){
//                int E_3 = R(1,1)*R(1,0) + R(1,1)*R(1,0);
//                E += E_3;
//                //cout << E_3 << endl;
//            }
//        }
//    }
//    cout << E << endl;
    //cout << R << endl;

    // Husk at R(i,j) = U(i+1, j+1)
    //E_tot += E;

    mat U = zeros<mat>(N+2, N+2);
    for(int i=0; i<N; i++){
        for(int j=0; j <N; j++){
            U(i+1, j+1) = R(i,j);
            U(0,j+1) = R(N-1, j);
            U(i+1,0) = R(i, N-1);
            U(N+1,j+1) = R(0, j);
            U(i+1,N+1) = R(i,0);
        }
    }

    //---Calculate total energy---
    /* We can calculate the interaction between the element above and on
     * the right hand side of the element S_jk itself. Then we dont risk
     * to calculate an interaction twice, but we will still calculate all
     * interactions. (This is general) */
    int E = 0;
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < N+1; j++){
            E += U(i,j)*U(i,j-1)+U(i,j)*U(i+1,j);
        }
    }
    int E_tot = E;

    cout << "U-matrix:\n" << U << endl;
    cout << "The total energy is " << E_tot << "J" << endl;

    for(int t=0; t < T; t++){
        int i = rand()%N;
        int j = rand()%N;
        int R_late = R(i,j);

        if( R(i,j) == 1){
            R(i,j) =-1;
        }
        else{
            R(i,j) = 1;
        }

        int E_part_late = R_late*U(i+1,j+2) + R_late*U(i,j) + R_late*U(i+2, j+1) + R_late*U(i,j+1);
        int E_part_new = R(i,j)*U(i+1,j+2) + R(i,j)*U(i,j) + R(i,j)*U(i+2, j+1) + R(i,j)*U(i,j+1);
        int delta_E = E_part_new - E_part_late;
        E = E + delta_E;

        if(delta_E < 0){
            E_tot += E;
        }

        else if(delta_E > 0){

            if(1 > exp(-beta*delta_E)){
                //draw random number from 0 to 1, check if bigger than exp()
                double r = (double)rand() / (double)RAND_MAX;
                if (r <= exp(-beta*delta_E)){
                    //cout << r << endl;
                    E_tot += E;
                }
                else{
                    // discard change
                    R(i,j) = R_late;
                }
            }

            else if(1 < exp(-beta*delta_E)){
                E_tot += E;
            }

        }


    }


}
