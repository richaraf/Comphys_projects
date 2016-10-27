#ifndef EXACT2X2_H
#define EXACT2X2_H


class Exact2x2
{
private:
    double m_J = 1.0;
public:
    Exact2x2();
    double Energy(double T);
};

#endif // EXACT2X2_H
