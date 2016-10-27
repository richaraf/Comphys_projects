#include <iostream>
#include "lattice.h"
#include "exact2x2.h"

using namespace std;

int main()
{
    Lattice testing;
    //testing.setL(4);

    int L = testing.getL();
    cout << "Lattice with L = " << L << endl;
    Exact2x2 exact;
    double E = exact.Energy(1.0);
    cout << "Exact energy for 2x2, E = " << E << endl;

    return 0;
}
