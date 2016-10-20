#include <system.h>
#include <Integrators/integrator.h>
#include <Potentials/potential.h>
#include <InitialConditions/initialcondition.h>
#include <particle.h>
#include <Potentials/newtoniangravity.h>
#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

void System::computeForces() {
    resetAllForces();
    m_potential->resetPotentialEnergy();
    for(int i = 0; i < m_numberOfParticles; i++){
        for (int j = i+1; j < m_numberOfParticles; j++){
            m_potential->computeForces(*m_particles.at(i), *m_particles.at(j));
        }
    }
}

void System::resetAllForces() {
    for (int i=0; i<m_numberOfParticles; i++) {
        m_particles.at(i)->resetForces();
    }
}

void System::setPotential(Potential* potential) {
    m_potential = potential;
}

void System::setIntegrator(Integrator* integrator) {
    m_integrator = integrator;
}

void System::setInitialCondition(InitialCondition* initialCondition) {
    m_initialCondition = initialCondition;
    m_initialCondition->setupParticles(*this);
}

void System::setDt(double dt) {
    m_integrator->setDt(dt);
}

void System::integrate(int numberOfSteps) {
    m_integrateSteps = numberOfSteps;
    printIntegrateInfo(0);
    for (int i=1; i<numberOfSteps+1; i++) {
        m_integrator->integrateOneStep(m_particles);
        printIntegrateInfo(i);
        if (m_writeToFile == true){
            writePositionsToFile();
        }
    }
    closeOutFile();
}

void System::addParticle(Particle* p) {
    m_particles.push_back(p);
    m_numberOfParticles += 1;
}

double System::computeKineticEnergy() {
    // Compute kinetic energy
    m_kineticEnergy = 0;
    for(int i = 0; i < m_numberOfParticles; i++){
        Particle *p = m_particles.at(i);
        m_kineticEnergy += 0.5*p->getMass()*p->getVelocity().lengthSquared();
    }
    return m_kineticEnergy;
}

void System::printIntegrateInfo(int stepNumber) {
    if (stepNumber == 0) {
        cout << endl
             << " STARTING INTEGRATION "    << endl
             << "-------------------------" << endl
             << "  o Number of steps:     " << m_integrateSteps << endl
             << "  o Time step, dt:       " << m_integrator->getDt() << endl
             << "  o Initial condition:   " << m_initialCondition->getName() << endl
             << "  o Number of particles: " << m_particles.size() << endl
             << "  o Potential in use:    " << m_potential->getName() << endl
             << "  o Integrator in use:   " << m_integrator->getName() << endl
             << endl;
    } else if (stepNumber % 1000 == 0) {
        m_kineticEnergy     = computeKineticEnergy();
        m_angularMomentum   = computeAngularMomentum();
        m_potentialEnergy   = m_potential->getPotentialEnergy();
        m_totalEnergy       = m_kineticEnergy + m_potentialEnergy;
        printf("Step: %5d    E =%10.7f   Ek =%10.7f    Ep =%10.7f   L =%10.7f\n",
               stepNumber, m_totalEnergy, m_kineticEnergy, m_potentialEnergy, m_angularMomentum);
        if (m_printEscape == true){
            EscapeVelocity();
        }
        if (m_testvelocity == true){
            testVelocity();
        }
        fflush(stdout);
    }
}

void System::setFileWriting(bool writeToFile) {
    m_writeToFile = writeToFile;
}

void System::setFileWritingMercury(bool writetoFileMercury){
    m_writeToFileMercury = writetoFileMercury;
}

void System::writePositionsToFile() {
    if (m_outFileOpen == false) {
        m_outFile.open("../positions.dat", std::ios::out);
        m_outFile2.open("../energies.dat", std::ios::out);
        m_outFileOpen = true;
    }
    // write positions of the system to file
    for (int i = 0; i < m_numberOfParticles; i++){
        Particle *p = m_particles.at(i);
        m_outFile << setprecision(20) << p->getPosition()(0) << " " << setprecision(20) << p->getPosition()(1) << " ";
    }
    m_outFile << "\n";
    // write total energy of system to the terminal
    m_kineticEnergy     = computeKineticEnergy();
    m_potentialEnergy   = m_potential->getPotentialEnergy();
    m_totalEnergy       = m_kineticEnergy + m_potentialEnergy;
    m_outFile2 << setprecision(20) << m_totalEnergy << endl;
    if(m_writeToFileMercury = true){
    if(m_outFileOpenMercury == false) {
        m_outFilemercury.open("../mercurypositions.dat", std::ios::out);
        m_outFileOpenMercury = true;
    }
    Particle *p = m_particles.at(1);
    m_outFilemercury << setprecision(15) << p->getPosition()(0) << " " << setprecision(15) << p->getPosition()(1) << " " << (p->getPosition()-m_particles.at(0)->getPosition()).length() << "\n";
    }
}

void System::closeOutFile() {
    if (m_writeToFile == true) {
        m_outFile.close();
        m_outFileOpen = false;
        m_outFile2.close();
    }
}

void System::setTestVelocity(bool velocitytest, double tol){
    m_testvelocity = velocitytest;
    m_tol = tol;
}

void System::testVelocity(){
    Particle* p = m_particles.at(1);       //Earth
    m_velNumerical = (p->getVelocity()).length();
    if(abs(m_velNumerical-m_velAnalytical) > m_tol){
        throw invalid_argument("The calculated velocity has larger error than the tolerance");
    }
}

double System::computeAngularMomentum() {
    vec3 L;
    for(int i = 0; i < m_numberOfParticles; i++){
        Particle* p = m_particles.at(i);
        vec3 P = vec3(p->getMass()*p->getVelocity());
        L = L + vec3(p->getPosition().cross(P));
    }
    return L.length();
}

void System::printEscape(bool printEscape) {
    m_printEscape = printEscape;
}

void System::EscapeVelocity(){
    Particle *p_0 = m_particles.at(0);
    Particle *p_1 = m_particles.at(1);
    double velocity = p_1->getVelocity().length();
    double kinetic_E = 0.5*p_1->getMass()*p_1->getVelocity().lengthSquared();
    double potential_E = - 4*pow(M_PI, 2)*p_1->getMass()*p_0->getMass()/p_1->getPosition().length();
    double total_E = kinetic_E + potential_E;

    if(total_E > - pow(10,-10)){
        cout << "Planet escaped" <<" " << "velocity:" << velocity <<"AU/yr" <<endl;
    }
    else if(total_E < - pow(10, -10)){
        cout << "Planet trapped " <<" " <<"velocity:" << velocity <<"AU/yr" <<endl;
    }
}
