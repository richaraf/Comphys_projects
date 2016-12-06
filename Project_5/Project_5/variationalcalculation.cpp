#include "variationalcalculation.h"
#include <iostream>
#include <cmath>
#include "vec3.h"
#include "wavefunction.h"
#include <fstream>
#include <iomanip>

using namespace std;

double random_position(double steplength){
    return ((double)rand() / (double)RAND_MAX)*steplength;
}

void VariationalMethod(double omega, int N, int trialversion, double alpha, double beta, string fileName){

    WaveFunction Psi;
    Psi.setTrialWF(trialversion);
    ofstream outfile_EL2;
    outfile_EL2.open(fileName, ios::app);
//    ofstream outfile_EL1;
//    outfile_EL1.open(fileName, ios::app);

    srand(time(NULL));

    double steplength       = 1.0/sqrt(omega);
    double K_tot            = 0.0;
    double K_average        = 0.0;
    double V_tot            = 0.0;
    double V_average        = 0.0;
    double E_tot            = 0.0;
    double E_sqrd_tot       = 0.0;
    double E_average        = 0.0;
    double E_sqrd_average   = 0.0;
    double r12_tot          = 0.0;
    double r12_average      = 0.0;
    double K                = 0.0;
    double V                = 0.0;
    double E                = 0.0;
    double eq               = 0.0;
    int accepted = 0;

    //Initial positions
    vec3 r_1(random_position(steplength), random_position(steplength),random_position(steplength));
    vec3 r_2(random_position(steplength), random_position(steplength),random_position(steplength));
    vec3 r1minus;
    vec3 r1plus;
    vec3 r2plus;
    vec3 r2minus;


    for(int n=0; n < N; n++){
        double Psi_squared_old = Psi.Psi_value(r_1, r_2, alpha, omega, beta)*Psi.Psi_value(r_1, r_2, alpha, omega, beta);

        int particle_number = rand()%2;
        int dimension_number = rand()%3;

        double change = (2.0*((double)rand() / (double)RAND_MAX) -1.0)*steplength;

        if(particle_number ==0){
            r_1[dimension_number] += change;
        }
        else if(particle_number ==1){
            r_2[dimension_number] += change;
        }

        double Psi_squared_new = Psi.Psi_value(r_1, r_2, alpha, omega, beta)*Psi.Psi_value(r_1, r_2, alpha, omega, beta);

        if(Psi_squared_new >= Psi_squared_old){
            if(n > eq*N) {
                accepted += 1;
                K_tot += Psi.KineticE(r_1, r_2, alpha, omega, beta);
                V_tot += Psi.PotentialE(r_1, r_2, alpha, omega, beta);
                r12_tot += fabs(r_1.length()-r_2.length());
                E_tot = E_tot + Psi.E_L(r_1, r_2, alpha, omega, beta);
                E_sqrd_tot += Psi.E_L(r_1, r_2, alpha, omega, beta)*Psi.E_L(r_1, r_2, alpha, omega, beta);
//              //cout << "#1 E_tot: " << E_tot << endl;
            }
        }
        else if(Psi_squared_new < Psi_squared_old){
            double random_number = (double)rand() / (double)RAND_MAX;
            double Psi_new_div_old_squared = Psi_squared_new/Psi_squared_old;

            if(random_number <= Psi_new_div_old_squared){
                if(n > eq*N) {
                    accepted += 1;
                    K_tot += Psi.KineticE(r_1, r_2, alpha, omega, beta);
                    V_tot += Psi.PotentialE(r_1, r_2, alpha, omega, beta);
                    r12_tot += fabs(r_1.length()-r_2.length());
                    E_tot = E_tot + Psi.E_L(r_1, r_2, alpha, omega, beta);
                    E_sqrd_tot += Psi.E_L(r_1, r_2, alpha, omega, beta)*Psi.E_L(r_1, r_2, alpha, omega, beta);
    //              //cout << "#1 E_tot: " << E_tot << endl;
                }            }

            else if(random_number > Psi_new_div_old_squared){

                if(particle_number ==0){
                    r_1[dimension_number] -= change;
                }
                else if(particle_number ==1){
                    r_2[dimension_number] -= change;
                }

                if(n > eq*N) {
                    //accepted += 1;
                    K_tot += Psi.KineticE(r_1, r_2, alpha, omega, beta);
                    V_tot += Psi.PotentialE(r_1, r_2, alpha, omega, beta);
                    r12_tot += fabs(r_1.length()-r_2.length());
                    E_tot = E_tot + Psi.E_L(r_1, r_2, alpha, omega, beta);
                    E_sqrd_tot += Psi.E_L(r_1, r_2, alpha, omega, beta)*Psi.E_L(r_1, r_2, alpha, omega, beta);
    //              //cout << "#1 E_tot: " << E_tot << endl;
                }//cout << "#3 E_tot: " << E_tot << endl;
            }
        }



        //cout << "Average Energy:" << " "<< E_average << endl;

    }

    //cout << E_tot << " " << E_sqrd_tot << endl;
    r12_average = r12_tot/((1-eq)*(N-1));
    E_average = E_tot/((1-eq)*(N-1));
    E_sqrd_average = E_sqrd_tot/((1-eq)*(N-1));

    K_average = K_tot/((1-eq)*(N-1));
    V_average = V_tot/((1-eq)*(N-1));
    outfile_EL2 << setprecision(15) << setw(5) << alpha  << ' ' << setw(5) << beta << ' ' << setw(30) << E_average << ' ' << setw(30) << E_sqrd_average - E_average*E_average << setw(30) << omega << setw(30) << r12_average << setw(30) << K_average << setw(30) << V_average << endl;
    outfile_EL2.close();
    cout <<" alpha: " << alpha << " beta: " << beta << " E_average: " << E_average << " Variance E: " << E_sqrd_average - E_average*E_average << endl;
    cout <<" Acc ratio: " << accepted/((double)((1-eq)*N)) << " r12_average: " << r12_average << endl;
    cout <<" omega: " << omega << " KineticE: " << K_average << " PotentialE: " << V_average << " K/V: " << K_average/V_average <<endl;
}
