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
    for (int i = 0; i < 5; i++){
        alpha = 0.95 + i*0.05;
        for (int j = 0; j < 5; j++){
            beta = 0.20 + j*0.05;
            VariationalMethod(1.0, 1e5, 2, alpha, beta, filename);
        }
    }
    //outfile_EL1.close();
    return 0;
}
