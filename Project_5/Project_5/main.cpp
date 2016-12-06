#include <iostream>
#include <fstream>
#include <variationalcalculation.h>

using namespace std;

int main(int argc, char *argv[])
{
    //VariationalMethod(omega, N, trialversion, alpha, beta);
    string filename = "../E_L1_file_omegas.dat";
    ofstream ofs;
    ofs.open(filename, ofstream::out | ofstream::trunc);
    ofs.close();

    double alpha, beta, omega;
    for (int i = 0; i < 1; i++){
        alpha = 1.0 + i*0.01;
        for (int j = 0; j < 1; j++){
            beta = 0.25 + j*0.05;
            for (int k = 0; k < 1; k++){
                if (k == 0){
                    omega = 0.1;
                }
                if (k == 1){
                    omega = 0.5;
                }
                if (k == 2){
                    omega = 1.0;
                }
                VariationalMethod(0.01, 1e7, 2, 0.9, 0.05, filename);
            }
        }
    }
    return 0;
}
