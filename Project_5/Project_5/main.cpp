#include <iostream>
#include <variationalcalculation.h>

using namespace std;

int main(int argc, char *argv[])
{
    //VariationalMethod(omega, N, trialversion, alpha, beta)
    VariationalMethod(1.0, 1000, 1, 1.0, 1.0);

    return 0;
}
