#include <numerical2.h>
#include <armadillo>
#include <cstdlib>
#include <lattice.h>

using namespace std;
using namespace arma;

void Numerical2(long int T, double beta, int L, bool random, int my_rank, mat &local_expectation_values){

    // Make matrix using lattice.cpp
    mat R = zeros<mat>(L+2, L+2);
    Lattice lattice;
    lattice.makeLattice(R, random, L, my_rank);

    // Calculate total beginning energy
    int E = 0;
    int M = 0;
    for(int i = 1; i < L+1; i++){
        for(int j = 1; j < L+1; j++){
            E -= R(i,j)*R(i,j+1) + R(i,j)*R(i-1,j);
            M += R(i,j);
        }
    }

    long E_tot       =   0.0;
    long E_tot_sqrd  =   0.0;
    long M_tot       =   0.0;
    long M_tot_sqrd  =   0.0;
    // int64_t
    E_tot           +=  E;
    E_tot_sqrd      +=  E*E;
    M_tot           +=  M;
    M_tot_sqrd      +=  M*M;

    double expbetadelta_E;
    //cout << R << endl;

    // Get to steady state:
    for(int k=0; k<1e8; k++) {
    //Choosing flip index randomly
    int i = rand()%L;
    int j = rand()%L;

    //Store old values if the flip is discarded
    int R_late = R(i+1,j+1);
    int E_part_late = -(R_late*R(i+1,j) + R_late*R(i,j+1) + R_late*R(i+2,j+1) + R_late*R(i+1, j+2));

    //Flip (sweep)
    if( R(i+1,j+1) == 1){
        R(i+1, j+1) = -1;
    }
    else{
        R(i+1, j+1) = 1;
    }

    //Update boundary conditions
    if(i==0){
        R(L+1,j+1) = R(i+1,j+1);
    }
    if(i==(L-1)){
        R(0, j+1) = R(i+1,j+1);
    }
    if(j==0){
        R(i+1,L+1) = R(i+1,j+1);
    }
    if(j==L-1){
        R(i+1,0) = R(i+1,j+1);
    }

    //Calculate delta_E
    int E_part_new = -(R(i+1,j+1)*R(i+1,j) + R(i+1,j+1)*R(i,j+1) + R(i+1,j+1)*R(i+2,j+1) + R(i+1,j+1)*R(i+1, j+2));
    int delta_E = E_part_new - E_part_late;
    int E_prev = E;
    E = E + delta_E;

    if(delta_E <= 0){
        //E_tot += E;
        //E_tot_sqrd += E*E;
        M += 2*R(i+1,j+1);
        //M_tot += M;
        //M_tot_sqrd += M*M;
    }
    else if(delta_E > 0){
        expbetadelta_E = exp(-beta*delta_E);
        if(1 > expbetadelta_E){
            //draw random number from 0 to 1, check if bigger than exp()
            double r = (double)rand() / (double)RAND_MAX;
            if (r <= expbetadelta_E){
                //E_tot += E;
                //E_tot_sqrd += E*E;
                M += 2*R(i+1,j+1);
                //M_tot += M;
                //M_tot_sqrd += M*M;
            }
            else{
                // discard change
                R(i+1,j+1) = R_late;
                if(i==0){
                    R(L+1,j+1) = R(i+1,j+1);
                }
                if(i==(L-1)){
                    R(0, j+1) = R(i+1,j+1);
                }
                if(j==0){
                    R(i+1,L+1) = R(i+1,j+1);
                }
                if(j==L-1){
                    R(i+1,0) = R(i+1,j+1);
                }
                //E_tot += E_prev;
                E = E_prev;
                //E_tot_sqrd += E*E;
                //M_tot += M;
                //M_tot_sqrd += M*M;
            }
        }


        else if(1 < expbetadelta_E){
            //E_tot += E;
            //E_tot_sqrd += E*E;
            M += 2*R(i+1,j+1);
            //M_tot += M;
            //M_tot_sqrd += M*M;
        }
    }
}
//cout << R << endl;
//cout << E << endl;
//    ofstream oppgdT10;
//    oppgdT10.open("../oppgdT10_file.dat");

    // Monte-Carlo cycles
    for(int t=0; t < T; t++){
        for(int k=0; k<L*L; k++) {
        //Choosing flip index randomly
        int i = rand()%L;
        int j = rand()%L;

        //Store old values if the flip is discarded
        int R_late = R(i+1,j+1);
        int E_part_late = -(R_late*R(i+1,j) + R_late*R(i,j+1) + R_late*R(i+2,j+1) + R_late*R(i+1, j+2));

        //Flip (sweep)
        if( R(i+1,j+1) == 1){
            R(i+1, j+1) = -1;
        }
        else{
            R(i+1, j+1) = 1;
        }

        //Update boundary conditions
        if(i==0){
            R(L+1,j+1) = R(i+1,j+1);
        }
        if(i==(L-1)){
            R(0, j+1) = R(i+1,j+1);
        }
        if(j==0){
            R(i+1,L+1) = R(i+1,j+1);
        }
        if(j==L-1){
            R(i+1,0) = R(i+1,j+1);
        }

        //Calculate delta_E
        int E_part_new = -(R(i+1,j+1)*R(i+1,j) + R(i+1,j+1)*R(i,j+1) + R(i+1,j+1)*R(i+2,j+1) + R(i+1,j+1)*R(i+1, j+2));
        int delta_E = E_part_new - E_part_late;
        int E_prev = E;
        E = E + delta_E;

        if(delta_E <= 0){
            //E_tot += E;
            //E_tot_sqrd += E*E;
            M += 2*R(i+1,j+1);
            //M_tot += M;
            //M_tot_sqrd += M*M;
        }
        else if(delta_E > 0){
            expbetadelta_E = exp(-beta*delta_E);
            if(1 > expbetadelta_E){
                //draw random number from 0 to 1, check if bigger than exp()
                double r = (double)rand() / (double)RAND_MAX;
                //cout << r << endl;
                if (r <= expbetadelta_E){
                    //E_tot += E;
                    //E_tot_sqrd += E*E;
                    M += 2*R(i+1,j+1);
                    //M_tot += M;
                    //M_tot_sqrd += M*M;
                }
                else{
                    // discard change
                    R(i+1,j+1) = R_late;
                    if(i==0){
                        R(L+1,j+1) = R(i+1,j+1);
                    }
                    if(i==(L-1)){
                        R(0, j+1) = R(i+1,j+1);
                    }
                    if(j==0){
                        R(i+1,L+1) = R(i+1,j+1);
                    }
                    if(j==L-1){
                        R(i+1,0) = R(i+1,j+1);
                    }
                    //E_tot += E_prev;
                    E = E_prev;
                    //E_tot_sqrd += E*E;
                    //M_tot += M;
                    //M_tot_sqrd += M*M;
                }
            }

            else if(1 < expbetadelta_E){
                //E_tot += E;
                //E_tot_sqrd += E*E;
                M += 2*R(i+1,j+1);
                //M_tot += M;
                //M_tot_sqrd += M*M;
            }
        }
        }
        //cout << M << endl;
        //cout << t << endl;
        //cout << E << endl;
        //oppgdT10 << E << endl;

        E_tot += E;
        E_tot_sqrd += E*E;
        M_tot += M;
        M_tot_sqrd += M*M;
    }
    //oppgdT10.close();
    double E_average               = E_tot/(T + 1.0);
    double E_average_sqrd          = E_tot_sqrd/(T+1.0);
    double M_average               = M_tot/(T+ 1.0);
    double M_average_sqrd          = M_tot_sqrd/(T+1.0);
    double sigma_sqrd              = E_average_sqrd - E_average*E_average;

    double Cv  = (E_average_sqrd - E_average*E_average)*beta*beta;
    double X   = (M_average_sqrd - M_average*M_average)*beta;
    M_average = abs(M_average);
    cout << "E = " << E_average << endl;
    cout << "E*E = " << E_average_sqrd << endl;
    cout << "sigma*sigma = " << E_average_sqrd - E_average*E_average << endl;
    cout << "M = " << M_average << endl;
    cout << "Cv = " << Cv << endl;
    cout << "X = " << X << endl;
    // add expectation values from this process into the local list
    local_expectation_values[0] = E_average;
    local_expectation_values[1] = E_average_sqrd;
    local_expectation_values[2] = M_average; // this is absolute value
    local_expectation_values[3] = M_average_sqrd;
    local_expectation_values[4] = Cv;
    local_expectation_values[5] = X;
}
