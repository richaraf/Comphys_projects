#include <iostream>
#include "lattice.h"

using namespace std;

int main(int argc, char *argv[])
{
    Lattice testing;
    testing.setL(4);
    int L = testing.getL();
    cout << "Lattice with L = " << L << endl;
    return 0;
}
