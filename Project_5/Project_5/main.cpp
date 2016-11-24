#include <iostream>
#include <fstream>
#include <variationalcalculation.h>

using namespace std;

int main(int argc, char *argv[])
{
    //VariationalMethod(omega, N, trialversion, alpha, beta);

    double alpha, beta;
    for (int i = 0; i < 11; i++){
        alpha = 0.90 + i*0.01;
        for (int j = 0; j < 11; j++){
            beta = 0.90 + j*0.01;
            VariationalMethod(1.0, 1e6, 1, alpha, beta, "../E_L2_file_omega=1.dat");
        }
    }
    //outfile_EL1.close();
    return 0;
}