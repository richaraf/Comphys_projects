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

    double alpha = 1.0;
    double steplength = 1.0;

    //cout << Psi_T1(r_1, r_2, alpha, omega) << endl;

    for(int n=0; n < N; n++){

        double Psi_T1_squared = Psi_T1(r_1, r_2, alpha, omega)*Psi_T1(r_1, r_2, alpha, omega);

        int particle_number = rand()%2;
        int dimension_number = rand()%3;
        if(particle_number ==0){
            vec3 r_1_old = r_1;
            r_1[dimension_number] = (double)rand() / (double)RAND_MAX; //(2.0*rand()%2 - 1.0)*steplength;
        }
        else if(particle_number ==1){
            vec3 r_2_old = r_2;
            //r_2[dimension_number] = (2.0*rand()%2 - 1.0)*steplength;
        }



    }

}



