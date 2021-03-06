#ifndef EXACT2X2_H
#define EXACT2X2_H


class Exact2x2
{
private:
    double m_J = 1.0;
    double m_k = 1.0; // temporary value
    double m_eightJk = 8*m_J/m_k;
public:
    Exact2x2();
    double PartitionFunction(double T);
    double Energy(double T);
    double MagneticMoment(){return 0.0;}
    double EnergySquared(double T);
    double MagneticMomentSquared(double T);
    double HeatCapacity(double E_squared, double E, double T);
    double Susceptibility(double M_squared, double M, double T);
};

#endif // EXACT2X2_H
