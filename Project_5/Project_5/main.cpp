#include <iostream>
#include <variationalcalculation.h>

using namespace std;

int main(int argc, char *argv[])
{
    //VariationalMethod(omega, N, trialversion, alpha, beta)

    double alpha;
    for (int i = 0; i < 20; i++){
        alpha = 0.90 + i*0.01;
        VariationalMethod(1.0, 1000000, 1, alpha, 1.0);
    }
    return 0;
}
