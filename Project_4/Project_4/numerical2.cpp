#include <numerical2.h>
#include <armadillo>
#include <cstdlib>
#include <lattice.h>

using namespace std;
using namespace arma;

void Numerical2(double* X, double* Cv, int T, double beta, int L, bool random){

    // Make matrix using lattice.cpp
    mat R = zeros<mat>(L+2, L+2);
    Lattice lattice;
    lattice.makeLattice(R, random, L);

    // Calculate total beginning energy
    int E = 0;
    int M = 0;
    for(int i = 1; i < L+1; i++){
        for(int j = 1; j < L+1; j++){
            E -= R(i,j)*R(i,j+1) + R(i,j)*R(i-1,j);
            M += R(i,j);
        }
    }

    int E_tot       =   0;
    int E_tot_sqrd  =   0;
    int M_tot       =   0;
    int M_tot_sqrd  =   0;
    E_tot           +=  E;
    E_tot_sqrd      +=  E*E;
    M_tot           +=  M;
    M_tot_sqrd      +=  M*M;

    int number_of_discards = 0;
    ofstream outfile;
    outfile.open("../number_of_accept.dat", std::ios::out);

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

            if(1 > exp(-beta*delta_E)){
                //draw random number from 0 to 1, check if bigger than exp()
                double r = (double)rand() / (double)RAND_MAX;
                if (r <= exp(-beta*delta_E)){
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

            else if(1 < exp(-beta*delta_E)){
                E_tot += E;
                E_tot_sqrd += E*E;
                M += 2*R(i+1,j+1);
                M_tot += M;
                M_tot_sqrd += M*M;
            }

        }
        //Write file with time and number of acceptations
//        int S = 1000;               //Number of uniform distrubuted elements in file
//        if(t%(T/S)==0){
//            outfile << t+1 << "  " << t+1-number_of_discards << endl;
//        }
//        if(M==0){
//            cout << 'Equilibrium reached when t= ' << t << endl;
//        }
        //cout << M << endl;
        cout << E << endl;
        //cout << R << endl;
    }
    outfile.close();

    double E_average        = E_tot/(T + 1.0);
    double E_average_sqrd   = E_tot_sqrd/(T+1.0);
    double M_average        = M_tot/(T+ 1.0);
    double M_average_sqrd   = M_tot_sqrd/(T+1.0);

    cout << "E_tot: "           << E_tot << "J"     << endl;
    cout << "E_average: "       << E_average        << endl;
    cout << "E_average_sqrd: "  << E_average_sqrd   << endl;
    cout << "M_tot: "           << M_tot            << endl;
    cout << "M_average: "       << M_average        << endl;
    cout << "M_tot_sqrd: "      << M_tot_sqrd       << endl;
    cout << "M_average_sqrd: "  << M_average_sqrd   << endl;

    *Cv  = (E_average_sqrd - E_average*E_average)*beta;
    *X   = (M_average_sqrd - M_average*M_average)*beta;

    //Make matrix without using function
//    srand(time(NULL));
//    mat R = zeros<mat>(L, L);
//    for(int i=0; i < L; i++){
//        for(int j=0; j < L; j++){
//            //Fill matrix randomly
//            int x = rand()%2; //trekker tall mellom 0 og 1
//            if(x==1){
//                R(i,j) = 1;
//            }
//            else{
//                R(i,j) = -1;
//            }

//            //Fill matrix manually
//            //R(i,j)=1;
//        }
//    }

    //Calculate energy, spesicif 2x2
//    int E_tot = 0; //Energy of T microstates added together
//    int E = 0; //Energy of one microstate

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

//    mat R = zeros<mat>(N,N);
//    R(0,0) = R(1,1) = -1;
//    R(0,1) = R(1,0) = 1;



//    mat U = zeros<mat>(L+2, L+2);
//    for(int i=0; i<L; i++){
//        for(int j=0; j <L; j++){
//            U(i+1, j+1) = R(i,j);
//            U(0,j+1) = R(L-1, j);
//            U(i+1,0) = R(i, L-1);
//            U(L+1,j+1) = R(0, j);
//            U(i+1,L+1) = R(i,0);
//        }
//    }

//    //---Calculate total energy---
//    int E = 0;
//    int M = 0;
//    for(int i = 1; i < L+1; i++){
//        for(int j = 1; j < L+1; j++){
//            E -= U(i,j)*U(i,j+1) + U(i,j)*U(i-1,j);
//            M += U(i,j);
//        }
//    }
//    //cout << "M_start= " << 200-M << endl;
//    int E_tot = 0;
//    int E_tot_sqrd = 0;
//    int M_tot = 0;
//    int M_tot_sqrd = 0;
//    E_tot += E;
//    E_tot_sqrd += E*E;
//    M_tot += M;
//    M_tot_sqrd += M*M;
//    //cout << "The energy of the first microstate is:" << E << "J" << endl;

//    //cout << "U-matrix:\n" << U << endl;
//    //cout << R << endl;
//    //cout << "The total energy is " << E_tot << "J" << endl;

//    int number_of_discards = 0;
//    ofstream outfile;
//    outfile.open("../number_of_accept.dat", std::ios::out);
//    for(int t=0; t < T; t++){
//        int i = rand()%L;
//        int j = rand()%L;
//        int R_late = R(i,j);
//        //int E_part_late = R_late*U(i+1,j+2) + R_late*U(i,j) + R_late*U(i+2, j+1) + R_late*U(i,j+1);
//        int E_part_late = -(R_late*U(i+1,j) + R_late*U(i,j+1) + R_late*U(i+2,j+1) + R_late*U(i+1, j+2));

//        if( R(i,j) == 1){
//            R(i,j) =-1;
//            U(i+1, j+1) = -1;

//        }
//        else{
//            R(i,j) = 1;
//            U(i+1, j+1) = 1;
//        }

//        if(i==0){
//            U(L+1,j+1) = R(i,j);
//        }
//        if(i==(L-1)){
//            U(0, j+1) = R(i,j);
//        }
//        if(j==0){
//            U(i+1,L+1) = R(i,j);
//        }
//        if(j==L-1){
//            U(i+1,0) = R(i,j);
//        }

//        //int E_part_new = R(i,j)*U(i+1,j+2) + R(i,j)*U(i,j) + R(i,j)*U(i+2, j+1) + R(i,j)*U(i,j+1);
//        int E_part_new = -(R(i,j)*U(i+1,j) + R(i,j)*U(i,j+1) + R(i,j)*U(i+2,j+1) + R(i,j)*U(i+1, j+2));
//        int delta_E = E_part_new - E_part_late;
//        //cout << "delta_E: " << delta_E << endl;
//        int E_prev = E;
//        E = E + delta_E;


//        if(delta_E < 0){
//            E_tot += E;
//            E_tot_sqrd += E*E;
//            M += 2*R(i,j);
//            M_tot += M;
//            M_tot_sqrd += M*M;
//            //cout << "#1 The energy of the sec microstate is:" << E << "J" << endl;
//        }

//        else if(delta_E > 0){

//            if(1 > exp(-beta*delta_E)){
//                //draw random number from 0 to 1, check if bigger than exp()
//                double r = (double)rand() / (double)RAND_MAX;
//                if (r <= exp(-beta*delta_E)){
//                    //cout << r << endl;
//                    E_tot += E;
//                    E_tot_sqrd += E*E;
//                    M += 2*R(i,j);
//                    M_tot += M;
//                    M_tot_sqrd += M*M;
//                    //cout << "#2 The energy of the sec microstate is:" << E << "J" << endl;
//                }
//                else{
//                    // discard change
//                    number_of_discards += 1;
//                    R(i,j) = R_late;
//                    U(i+1,j+1) = R_late;
//                    if(i==0){
//                        U(L+1,j+1) = R(i,j);
//                    }
//                    if(i==(L-1)){
//                        U(0, j+1) = R(i,j);
//                    }
//                    if(j==0){
//                        U(i+1,L+1) = R(i,j);
//                    }
//                    if(j==L-1){
//                        U(i+1,0) = R(i,j);
//                    }
//                    E_tot += E_prev;
//                    E = E_prev;
//                    E_tot_sqrd += E*E;
//                    M_tot += M;
//                    M_tot_sqrd += M*M;
//                    //cout << "#3 The energy of the sec microstate is:" << E << "J" << endl;
//                    //Gaa tilbake til gamle grensebetingelser for U
//                }
//            }

//            else if(1 < exp(-beta*delta_E)){
//                E_tot += E;
//                E_tot_sqrd += E*E;
//                M += 2*R(i,j);
//                M_tot += M;
//                M_tot_sqrd += M*M;
//                //cout << "#4 The energy of the sec microstate is:" << E << "J" << endl;
//            }

//        }
//        else if(delta_E==0){
//                E_tot += E;
//                E_tot_sqrd += E*E;
//                M += 2*R(i,j);
//                M_tot += M;
//                M_tot_sqrd += M*M;
//                //cout << "#5 The energy of the sec microstate is:" << E << "J" << endl;
//            }

//        //Need this for doing measurements in exercise 4c
//        int M = 1000;               //Number of uniform distrubuted elements in file
//        if(t%(T/M)==0){
//            outfile << t+1 << "  " << t+1-number_of_discards << endl;
//        }
//        //cout << "M_mid: " << M << endl;
//        //if(M==0){
//        //    cout << "Equlibrium state reached, t= " << t << endl;
//        //    break;
//        //}
//        //cout << M << " " << E << " ";
//        //cout << R << endl;
//        //cout << U << endl;
//    }
//    //cout << U << endl;
//    outfile.close();

//    double E_average        = E_tot/(T + 1.0);
//    double E_average_sqrd   = E_tot_sqrd/(T+1.0);
//    double M_average        = M_tot/(T+ 1.0);
//    double M_average_sqrd   = M_tot_sqrd/(T+1.0);

//    cout << "E_tot: "           << E_tot << "J"     << endl;
//    cout << "E_average: "       << E_average        << endl;
//    cout << "E_average_sqrd: "  << E_average_sqrd   << endl;
//    cout << "M_tot: "           << M_tot            << endl;
//    cout << "M_average: "       << M_average        << endl;
//    cout << "M_tot_sqrd: "      << M_tot_sqrd       << endl;
//    cout << "M_average_sqrd: "  << M_average_sqrd   << endl;

//    *Cv  = (E_average_sqrd - E_average*E_average)*beta;
//    *X   = (M_average_sqrd - M_average*M_average)*beta;
}
