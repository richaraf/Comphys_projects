#pragma once
#include "particle.h"
#include <vector>
#include <fstream>
#include <cmath>

class System {
private:
    bool                        m_writeToFile           = false;
    bool                        m_writeToFileMercury    = false;
    bool                        m_testvelocity          = false;
    bool                        m_outFileOpen           = false;
    bool                        m_outFileOpenMercury    = false;
    bool                        m_printEscape           = false;
    int                         m_integrateSteps        = 0;
    int                         m_numberOfParticles     = 0;
    double                      m_kineticEnergy         = 0;
    double                      m_angularMomentum       = 0;
    double                      m_totalEnergy           = 0;
    double                      m_potentialEnergy       = 0;
    double                      m_tol                   = 0;
    double                      m_velAnalytical         = 2*M_PI;
    double                      m_velNumerical          = 0;
    class Integrator*           m_integrator            = nullptr;
    class Potential*            m_potential             = nullptr;
    class InitialCondition*     m_initialCondition      = nullptr;
    std::ofstream               m_outFile;
    std::ofstream               m_outFile2;
    std::ofstream               m_outFilemercury;
    std::vector<Particle*>      m_particles;

public:
    System() {}
    void computeForces          ();
    void resetAllForces         ();
    void setPotential           (class Potential* potential);
    void setIntegrator          (class Integrator* integrator);
    void setInitialCondition    (class InitialCondition* initialCondition);
    void setDt                  (double dt);
    void setTestVelocity        (bool velocitytest, double tol);
    void integrate              (int numberOfSteps);
    void addParticle            (Particle* p);
    void printIntegrateInfo     (int stepNumber);
    void removeLinearMomentum   ();
    void testVelocity           ();
    void setFileWriting         (bool writeToFile);
    void printEscape            (bool printEscape);
    void writePositionsToFile   ();
    void setFileWritingMercury  (bool writetoFileMercury);
    void closeOutFile           ();
    double computeAngularMomentum();
    double computeKineticEnergy ();
    void EscapeVelocity         ();
};

