#include "variationalcalculation.h"
#include <iostream>
#include <cmath>
#include "vec3.h"
#include "wavefunction.h"


using namespace std;

//double Psi_T1(vec3 r_1, vec3 r_2, double alpha, double omega){
//    double psi_t_value = exp(-alpha*omega*(r_1.lengthSquared() + r_2.lengthSquared())/2.0);
//    return psi_t_value;
//}

//double E_L1(vec3 r_1, vec3 r_2, double alpha, double omega){
//    return 0.5*omega*omega*(r_1.lengthSquared() + r_2.lengthSquared())*(1-alpha*alpha) + 3*alpha*omega;
//}


void VariationalMethod(double omega, int N, int trialversion, double alpha, double beta){

    WaveFunction Psi;
    Psi.setTrialWF(trialversion);

    //Initial positions
    vec3 r_1(1,1,1);
    vec3 r_2(-1, -1, -1);

    double steplength       = 1.0/sqrt(omega);
    double E_tot            = 0.0;
    double E_average        = 0.0;
    double E_sqrd_average   = 0.0;

    srand(time(NULL));

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
            E_tot = E_tot + Psi.E_L(r_1, r_2, alpha, omega, beta);
            //cout << "#1 E_tot: " << E_tot << endl;
        }
        else if(Psi_squared_new < Psi_squared_old){
            double random_number = (double)rand() / (double)RAND_MAX;
            double Psi_new_div_old_squared = Psi_squared_new/Psi_squared_old;

            if(random_number <= Psi_new_div_old_squared){
                E_tot = E_tot + Psi.E_L(r_1, r_2, alpha, omega, beta);
                //cout << "#2 E_tot: " << E_tot << endl;
            }

            else if(random_number > Psi_new_div_old_squared){
                r_1 = r_1_old;
                r_2 = r_2_old;
                E_tot = E_tot + Psi.E_L(r_1, r_2, alpha, omega, beta);
                //cout << "#3 E_tot: " << E_tot << endl;
            }
        }
        E_average = E_tot/(n+1.0);
        //cout << "Average Energy:" << " "<< E_average << endl;

    }
    cout <<"alpha: " << alpha << "E_average: " << E_average << endl;
}
