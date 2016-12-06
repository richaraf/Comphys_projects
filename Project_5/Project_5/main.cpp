#include <iostream>
#include <fstream>
#include <variationalcalculation.h>

using namespace std;

int main(int argc, char *argv[])
{
    //VariationalMethod(omega, N, trialversion, alpha, beta);
    string filename = "../E_L3_file_omegas.dat";
    ofstream ofs;
    ofs.open(filename, ofstream::out | ofstream::trunc);
    ofs.close();

    double alpha, beta, omega;
    for (int i = 0; i < 1; i++){
        alpha = 1.0 + i*0.01;
        for (int j = 0; j < 1; j++){
            beta = 0.25 + j*0.05;

            for (int k = 1; k < 2; k++){

                VariationalMethod(1, 1e6, 1, 1.0, 0.2, filename);
            }
        }
    }
    return 0;
}
