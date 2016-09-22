#include <armadillo>
#include <iostream>

using namespace arma;
using namespace std;

int main(){


    //Lager rho-arrayen
    double* rho = new double[N+1];
    rho[0] = 0.0;
    rho[N] = 1000.0; //Approx infinity

    double h; h = (rho[N] - rho[0])/(N+1); //N+1 eller N?

    //Lager rho, looper til N-1
    for(int i = 1; i < N; i++)
    {
        rho[i] = rho[0] + i*h;
    }

    //Setter opp matri

    return 0;
}
