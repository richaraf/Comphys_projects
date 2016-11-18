#include "variationalcalculation.h"
#include <iostream>
#include <cmath>
#include "vec3.h"


using namespace std;

double Psi_T1(vec3 r_1, vec3 r_2, double alpha, double omega){
    double psi_t_value = exp(-alpha*omega*(r_1.lengthSquared() + r_2.lengthSquared())/2.0);
    return psi_t_value;
}

double E_L1(vec3 r_1, vec3 r_2, double alpha, double omega){
    return 0.5*omega*omega*(r_1.lengthSquared() + r_2.lengthSquared())*(1-alpha*alpha) + 3*alpha*omega;
}


void VariationalMethod(double omega, int N){

    //Initial positions
    vec3 r_1(1,1,1);
    vec3 r_2(-1, -1, -1);

    double alpha        = 1.0;
    double steplength   = 1.0;
    double E_tot        = 0.0;

    srand(time(NULL));

    for(int n=0; n < N; n++){

        double Psi_T1_squared_old = Psi_T1(r_1, r_2, alpha, omega)*Psi_T1(r_1, r_2, alpha, omega);
        vec3 r_1_old = r_1;
        vec3 r_2_old = r_2;

        int particle_number = rand()%2;
        int dimension_number = rand()%3;
        if(particle_number ==0){
            r_1[dimension_number] = r_1_old[dimension_number] + (2.0*((double)rand() / (double)RAND_MAX) -1.0)*steplength; //(2.0*rand()%2 - 1.0)*steplength;
            //cout << r_1[dimension_number] << endl;
        }
        else if(particle_number ==1){
            r_2[dimension_number] = r_2_old[dimension_number] + (2.0*((double)rand() / (double)RAND_MAX) -1.0)*steplength;
            //cout << r_2[dimension_number] << endl;
        }

        double Psi_T1_squared_new = Psi_T1(r_1, r_2, alpha, omega)*Psi_T1(r_1, r_2, alpha, omega);

        //Accept or deny

        if(Psi_T1_squared_new >= Psi_T1_squared_old){
            //accept move
            E_tot = E_tot + E_L1(r_1, r_2, alpha, omega);
        }
        else if(Psi_T1_squared_new < Psi_T1_squared_old){
            double random_number = (double)rand() / (double)RAND_MAX;
            double Psi_T1_new_div_old_squared = Psi_T1_squared_new/Psi_T1_squared_old;

            if(random_number <= Psi_T1_new_div_old_squared){
                //accept
                E_tot = E_tot + E_L1(r_1, r_2, alpha, omega);
            }

            else if(random_number > Psi_T1_new_div_old_squared){
                //deny, reset r_1 and r_2
                r_1 = r_1_old;
                r_2 = r_2_old;
                E_tot = E_tot + E_L1(r_1, r_2, alpha, omega);


            }
        }
        double E_average = E_tot/N;
        cout << E_tot << endl;



    }

}



