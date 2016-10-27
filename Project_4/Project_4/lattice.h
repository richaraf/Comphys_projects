#ifndef LATTICE_H
#define LATTICE_H
#include <iostream>
using namespace std;

class Lattice
{
private:
    int m_L = 2;
public:
    Lattice();
    double setL(int L)     {return m_L = L;}


    double getL()     {return m_L;}
};

#endif // LATTICE_H
