#include <iostream>
#include <fstream>
#include <variationalcalculation.h>

using namespace std;

int main(int argc, char *argv[])
{
    //VariationalMethod(omega, N, trialversion, alpha, beta);
    string filename = "../E_L2_file_omega=0_01.dat";
    ofstream ofs;
    ofs.open(filename, ofstream::out | ofstream::trunc);
    ofs.close();

    double alpha, beta;
    for (int i = 0; i < 12; i++){
        alpha = 0.7 + i*0.025;
        for (int j = 0; j < 11; j++){
            beta = 0.0 + j*0.05;
            VariationalMethod(0.01, 1e7, 2, alpha, beta, filename);
        }
    }
    //outfile_EL1.close();
    return 0;
}
