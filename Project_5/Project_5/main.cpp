#include <iostream>
#include <variationalcalculation.h>

using namespace std;

int main(int argc, char *argv[])
{
    //VariationalMethod(omega, N, trialversion, alpha, beta)

    double alpha, beta;
    for (int i = 0; i < 10; i++){
        alpha = 0.95 + i*0.01;
        for (int j = 0; j < 1; j++){
            beta = 0.90 + j*0.01;
            VariationalMethod(1.0, 1000000, 1, alpha, beta);
        }

    }
    return 0;
}
