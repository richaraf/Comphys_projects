#include <iostream>
#include <fstream>
#include <variationalcalculation.h>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    //VariationalMethod(omega, N, trialversion, alpha, beta);
    string filename = "../E_L1_file_MCs.dat";
    ofstream ofs;
    ofs.open(filename, ofstream::out | ofstream::trunc);
    ofs.close();

//    double alpha, beta, omega;
//    for (int i = 0; i < 1; i++){
//        alpha = 1.0 + i*0.01;
//        for (int j = 0; j < 1; j++){
//            beta = 0.25 + j*0.05;
//            for (int k = 0; k < 50; k++){
//                omega = 0.01 + 100*k;
//                VariationalMethod(omega, 1e6, 2, alpha, beta, filename);
//            }
//        }
//    }
    double omega = 1.00;
    double beta = 1.00;
    for (int i = 1; i < 18; i++){
        int MC = pow(10,i/2.);
        VariationalMethod(omega, MC, 1, 0.95, beta, filename);
    }

    return 0;
}
