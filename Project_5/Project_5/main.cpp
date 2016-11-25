#include <iostream>
#include <fstream>
#include <variationalcalculation.h>

using namespace std;

int main(int argc, char *argv[])
{
    //VariationalMethod(omega, N, trialversion, alpha, beta);
    string filename = "../E_L2_file_omega=1.dat";
    ofstream ofs;
    ofs.open(filename, ofstream::out | ofstream::trunc);
    ofs.close();

    double alpha, beta;
    for (int i = 0; i < 21; i++){
        alpha = 1 + i*0.01;
        for (int j = 0; j < 11; j++){
            beta = 0.30 + j*0.01;
            VariationalMethod(1.0, 1e6, 2, alpha, beta, filename);
        }
    }
    //outfile_EL1.close();
    return 0;
}
