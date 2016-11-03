#ifndef LATTICE_H
#define LATTICE_H
#include <iostream>
#include <armadillo>
using namespace std;

class Lattice
{
private:
    int m_L = 0;
public:
    Lattice();
    double setL(int L)     {return m_L = L;}


    double getL()     {return m_L;}
    void makeLattice(arma::mat &R, bool random, int L);
};

#endif // LATTICE_H
