#include <numerical2.h>
#include <armadillo>
#include <cstdlib>
#include <lattice.h>

using namespace std;
using namespace arma;

void Numerical2(double* X, double* Cv, int T, double beta, int L, bool random){

    // Making matrix with function
    mat R = zeros<mat>(L+2, L+2);
    Lattice lattice;
    lattice.makeLattice(R, random, L);

    // Calculate total energy
    int E = 0;
    int M = 0;
    for(int i = 1; i < L+1; i++){
        for(int j = 1; j < L+1; j++){
            E -= R(i,j)*R(i,j+1) + R(i,j)*R(i-1,j);
            M += R(i,j);
        }
    }

    double E_tot       =   0.0;
    double E_tot_sqrd  =   0.0;
    double M_tot       =   0.0;
    double M_tot_sqrd  =   0.0;
    E_tot           +=  E;
    E_tot_sqrd      +=  E*E;
    M_tot           +=  M;
    M_tot_sqrd      +=  M*M;

    int number_of_discards = 0;
    ofstream outfile;
    double expbetadelta_E;
    outfile.open("../number_of_accept.dat", std::ios::out);

    //Write acerage energy and mean magnetization to file
    ofstream outfile_E_M;
    outfile_E_M.open("../E_M_T=1_0_file.dat");

    for(int t=0; t < T; t++){
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
            E_tot += E;
            E_tot_sqrd += E*E;
            M += 2*R(i+1,j+1);
            M_tot += M;
            M_tot_sqrd += M*M;
        }

        else if(delta_E > 0){
            expbetadelta_E = exp(-beta*delta_E);
            if(1 > expbetadelta_E){
                //draw random number from 0 to 1, check if bigger than exp()
                double r = (double)rand() / (double)RAND_MAX;
                if (r <= expbetadelta_E){
                    E_tot += E;
                    E_tot_sqrd += E*E;
                    M += 2*R(i+1,j+1);
                    M_tot += M;
                    M_tot_sqrd += M*M;
                }
                else{
                    // discard change
                    number_of_discards += 1;
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
                    E_tot += E_prev;
                    E = E_prev;
                    E_tot_sqrd += E*E;
                    M_tot += M;
                    M_tot_sqrd += M*M;
                }
            }

            else if(1 < expbetadelta_E){
                E_tot += E;
                E_tot_sqrd += E*E;
                M += 2*R(i+1,j+1);
                M_tot += M;
                M_tot_sqrd += M*M;
            }

        }
        //Need this for doing measurements in exercise 4c
        //int M = 100;               //Number of uniform distrubuted elements in file
        if(T>100 && t%100==0){
            outfile << t+1 << "  " << (t+1-number_of_discards)/(t+1.0) << endl;
        }

        double E_average        = E_tot/(t + 1.0);
        double M_average        = M_tot/(t+ 1.0);

        if(T>100 && t%100 ==0){
            outfile_E_M << t + 1.0 << " " << E_average << " " << M_average << endl;
        }
    }
    cout << R << endl;
    outfile.close();

    double E_average               = E_tot/(T + 1.0);
    double E_average_sqrd   = E_tot_sqrd/(T+1.0);
    double M_average               = M_tot/(T+ 1.0);
    double M_average_sqrd   = M_tot_sqrd/(T+1.0);

    cout << "E_tot_sqrd: "      << E_tot_sqrd << "J*J" << endl;
    cout << "E_tot: "           << E_tot << "J"     << endl;
    cout << "E_average: "       << E_average        << endl;
    cout << "E_average_sqrd: "  << E_average_sqrd   << endl;
    cout << "M_tot: "           << M_tot            << endl;
    cout << "M_average: "       << M_average        << endl;
    cout << "M_tot_sqrd: "      << M_tot_sqrd       << endl;
    cout << "M_average_sqrd: "  << M_average_sqrd   << endl;

    *Cv  = (E_average_sqrd - E_average*E_average)*beta;
    *X   = (M_average_sqrd - M_average*M_average)*beta;
}
