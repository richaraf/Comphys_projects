#include <iostream>
#include <fstream>
#include <variationalcalculation.h>

using namespace std;

int main(int argc, char *argv[])
{
    //VariationalMethod(omega, N, trialversion, alpha, beta);
    string filename = "../E_L1_file_omega=0_01.dat";
    ofstream ofs;
    ofs.open(filename, ofstream::out | ofstream::trunc);
    ofs.close();

    double alpha, beta;
    for (int i = 0; i < 21; i++){
        alpha = .8 + i*0.02;
        for (int j = 0; j < 1; j++){
            beta = 0.15 + j*0.02;
            VariationalMethod(0.01, 1e8, 1, alpha, beta, filename);
        }
    }
    //outfile_EL1.close();
    return 0;
}
