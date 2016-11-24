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
    double K                = 0.0;
    double V                = 0.0;
    double E                = 0.0;

    //Initial positions
    vec3 r_1(random_position(steplength), random_position(steplength),random_position(steplength));
    vec3 r_2(random_position(steplength), random_position(steplength),random_position(steplength));
    vec3 r1minus;
    vec3 r1plus;
    vec3 r2plus;
    vec3 r2minus;


    for(int n=0; n < N; n++){
        double Psi_squared_old = Psi.Psi_value(r_1, r_2, alpha, omega, beta)*Psi.Psi_value(r_1, r_2, alpha, omega, beta);
        vec3 r_1_old = r_1;
        vec3 r_2_old = r_2;

        int particle_number = rand()%2;
        int dimension_number = rand()%3;
        if(particle_number ==0){
            r_1[dimension_number] = r_1_old[dimension_number] + (2.0*((double)rand() / (double)RAND_MAX) -1.0)*steplength;
        }
        else if(particle_number ==1){
            r_2[dimension_number] = r_2_old[dimension_number] + (2.0*((double)rand() / (double)RAND_MAX) -1.0)*steplength;
        }

        double Psi_squared_new = Psi.Psi_value(r_1, r_2, alpha, omega, beta)*Psi.Psi_value(r_1, r_2, alpha, omega, beta);

        if(Psi_squared_new >= Psi_squared_old){
//            //vec3 rPlus = rMinus = r1;
//            double h = 0.001;
//            double waveFunctionMinus = 0;
//            double waveFunctionPlus = 0;
//            double waveFunctionCurrent = 0;
//            // Kinetic energy, brute force derivations
//            double kineticEnergy = 0;
//            for(int i = 0; i < 2; i++) {
//                for(int j = 0; j < 3; j++) {
//                    if(i==0){
//                        //rPlus = rMinus = r1;
//                        //rPlus(j) += h;
//                        //rMinus(j) -= h;
//                        r1plus(j) = r_1(j) + h;
//                        r1minus(j) = r_1(j) - h;
//                        waveFunctionMinus = Psi.Psi_value(r1minus, r_2, alpha, omega, beta);
//                        waveFunctionPlus = Psi.Psi_value(r1plus, r_2, alpha, omega, beta);
//                    }
//                    if(i==1){
//                        //rPlus = rMinus = r2;
//                        //rPlus(j) += h;
//                        //rMinus(j) -= h;
//                        r2plus(j) = r_2(j) + h;
//                        r2minus(j) = r_2(j) - h;
//                        waveFunctionMinus = Psi.Psi_value(r_1, r2minus, alpha, omega, beta);
//                        waveFunctionPlus = Psi.Psi_value(r_1, r2plus, alpha, omega, beta);


//                    }
//                    waveFunctionCurrent = Psi.Psi_value(r_1, r_2, alpha, omega, beta);
//                    kineticEnergy -= (waveFunctionMinus + waveFunctionPlus - 2 * waveFunctionCurrent);
//                    r1plus = r1minus = r_1;
//                    r2plus = r1minus = r_2;
//                }
//            }

//            kineticEnergy = 0.5 * (1/(h*h) * kineticEnergy + omega*omega*(r_1.lengthSquared() + r_2.lengthSquared())) / waveFunctionCurrent;
//            cout << kineticEnergy << endl;
//            E_tot = E_tot + kineticEnergy;
//            E_sqrd_tot += kineticEnergy*kineticEnergy;
            K = Psi.KineticE(r_1, r_2, alpha, omega, beta);
            V = Psi.PotentialE(r_1, r_2, alpha, omega, beta);
            E = K + V;
            K_tot += K;
            V_tot += V;
            E_tot += E;
            E_sqrd_tot += E*E;
            //cout << "#1 E_tot: " << E_tot << endl;
        }
        else if(Psi_squared_new < Psi_squared_old){
            double random_number = (double)rand() / (double)RAND_MAX;
            double Psi_new_div_old_squared = Psi_squared_new/Psi_squared_old;

            if(random_number <= Psi_new_div_old_squared){
//                //vec3 rPlus = rMinus = r1;
//                double h = 0.001;
//                double waveFunctionMinus = 0;
//                double waveFunctionPlus = 0;
//                double waveFunctionCurrent = 0;
//                // Kinetic energy, brute force derivations
//                double kineticEnergy = 0;
//                for(int i = 0; i < 2; i++) {
//                    for(int j = 0; j < 3; j++) {
//                        if(i==0){
//                            //rPlus = rMinus = r1;
//                            //rPlus(j) += h;
//                            //rMinus(j) -= h;
//                            r1plus(j) = r_1(j) + h;
//                            r1minus(j) = r_1(j) - h;
//                            waveFunctionMinus = Psi.Psi_value(r1minus, r_2, alpha, omega, beta);
//                            waveFunctionPlus = Psi.Psi_value(r1plus, r_2, alpha, omega, beta);
//                        }
//                        if(i==1){
//                            //rPlus = rMinus = r2;
//                            //rPlus(j) += h;
//                            //rMinus(j) -= h;
//                            r2plus(j) = r_2(j) + h;
//                            r2minus(j) = r_2(j) - h;
//                            waveFunctionMinus = Psi.Psi_value(r_1, r2minus, alpha, omega, beta);
//                            waveFunctionPlus = Psi.Psi_value(r_1, r2plus, alpha, omega, beta);


//                        }
//                        waveFunctionCurrent = Psi.Psi_value(r_1, r_2, alpha, omega, beta);
//                        kineticEnergy -= (waveFunctionMinus + waveFunctionPlus - 2 * waveFunctionCurrent);
//                        r1plus = r1minus = r_1;
//                        r2plus = r1minus = r_2;
//                    }
//                }

//                kineticEnergy = 0.5 * (1/(h*h) * kineticEnergy + omega*omega*(r_1.lengthSquared() + r_2.lengthSquared())) / waveFunctionCurrent;
//                cout << kineticEnergy << endl;
//                E_tot = E_tot + kineticEnergy;
//                E_sqrd_tot += kineticEnergy*kineticEnergy;
                K = Psi.KineticE(r_1, r_2, alpha, omega, beta);
                V = Psi.PotentialE(r_1, r_2, alpha, omega, beta);
                E = K + V;
                K_tot += K;
                V_tot += V;
                E_tot += E;
                E_sqrd_tot += E*E;
                //cout << "#2 E_tot: " << E_tot << endl;
            }

            else if(random_number > Psi_new_div_old_squared){
                r_1 = r_1_old;
                r_2 = r_2_old;
//                //vec3 rPlus = rMinus = r1;
//                double h = 0.001;
//                double waveFunctionMinus = 0;
//                double waveFunctionPlus = 0;
//                double waveFunctionCurrent = 0;
//                // Kinetic energy, brute force derivations
//                double kineticEnergy = 0;
//                for(int i = 0; i < 2; i++) {
//                    for(int j = 0; j < 3; j++) {
//                        if(i==0){
//                            //rPlus = rMinus = r1;
//                            //rPlus(j) += h;
//                            //rMinus(j) -= h;
//                            r1plus(j) = r_1(j) + h;
//                            r1minus(j) = r_1(j) - h;
//                            waveFunctionMinus = Psi.Psi_value(r1minus, r_2, alpha, omega, beta);
//                            waveFunctionPlus = Psi.Psi_value(r1plus, r_2, alpha, omega, beta);
//                        }
//                        if(i==1){
//                            //rPlus = rMinus = r2;
//                            //rPlus(j) += h;
//                            //rMinus(j) -= h;
//                            r2plus(j) = r_2(j) + h;
//                            r2minus(j) = r_2(j) - h;
//                            waveFunctionMinus = Psi.Psi_value(r_1, r2minus, alpha, omega, beta);
//                            waveFunctionPlus = Psi.Psi_value(r_1, r2plus, alpha, omega, beta);


//                        }
//                        waveFunctionCurrent = Psi.Psi_value(r_1, r_2, alpha, omega, beta);
//                        kineticEnergy -= (waveFunctionMinus + waveFunctionPlus - 2 * waveFunctionCurrent);
//                        r1plus = r1minus = r_1;
//                        r2plus = r1minus = r_2;
//                    }
//                }

//                kineticEnergy = 0.5 * (1/(h*h) * kineticEnergy + omega*omega*(r_1.lengthSquared() + r_2.lengthSquared())) / waveFunctionCurrent;
//                cout << kineticEnergy << endl;
//                E_tot = E_tot + kineticEnergy;
//                E_sqrd_tot += kineticEnergy*kineticEnergy;
                E_tot = E_tot + Psi.E_L(r_1, r_2, alpha, omega, beta);
                E_sqrd_tot += Psi.E_L(r_1, r_2, alpha, omega, beta)*Psi.E_L(r_1, r_2, alpha, omega, beta);
                //cout << "#3 E_tot: " << E_tot << endl;
            }
        }
        E_average = E_tot/(n+1.0);
        E_sqrd_average = E_sqrd_tot/(n+1.0);
        //cout << "Average Energy:" << " "<< E_average << endl;

    }

    outfile_EL2 << setprecision(15) << setw(18) << alpha  << ' ' << beta << ' ' << E_average << ' ' << E_sqrd_average - E_average*E_average << endl;
    outfile_EL2.close();
    cout <<"alpha: " << alpha << "beta: " << beta << " E_average: " << E_average << " Variance E: " << E_sqrd_average - E_average*E_average << endl;
}
