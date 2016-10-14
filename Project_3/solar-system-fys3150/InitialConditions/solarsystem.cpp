#include "solarsystem.h"
#include "../vec3.h"
#include "../system.h"
#include <cmath>


void SolarSystem::setupParticles(System &system) {
    /*
     * This is where you should implement the initialization of a three-body
     * system.
     *
     * You should start by impelmenting the two-body scheme in the
     * InitialiCondition::TwoBody class, and then implement the more
     * complicated three-body initialization only after you have a working
     * implementation of the two-body case.
     */


    // sun mass 1.988544E30 kg

    // initial positions for oct 12
    Particle* Sun = new Particle(vec3(3.571526865010806E-03, 3.389038138932890E-03, 0), vec3(-1.970078468466432E-06, 6.846218005095042E-06, 0)*365.25, 1.0);
    //Particle* Sun = new Particle(vec3(0,0,0), vec3(0,0,0), 1.0);

    //Earth initial velocity[AU/yr] and mass in masses of sun
    Particle* Earth= new Particle(vec3(9.479178499336547E-01, 3.261066313699268E-01,0), vec3(-5.849360690746023E-03, 1.621703296479702E-02, 0)*365.25, 3.00329789E-06);
    //Mars
    Particle* Mars = new Particle(vec3(1.136999274118817E+00, -7.886673045811080E-01 ,0), vec3(8.545468568248289E-03, 1.267637022893171E-02 ,0)*365.25, 3.227738486E-05);
    //Jupiter
    Particle* Jupiter = new Particle(vec3(-5.430133496003112E+00, -4.320838090483172E-01, 0), vec3(5.120612945394301E-04, -7.165562916536973E-03, 0)*365.25, 9.545325625*pow(10,-4));
    //Neptune
    Particle* Neptune = new Particle(vec3(2.825787471159655E+01, -9.931234946012548E+00, 0), vec3(1.020071131634030E-03, 2.979877053087604E-03, 0)*365.25, 5.149999195*pow(10,-5));
    //Saturn
    Particle* Saturn = new Particle(vec3(-2.282432370743082E+00, -9.770968263962711E+00, 0), vec3(5.126047128541801E-03, -1.286363002735174E-03, 0)*365.25, 2.857965426*pow(10,-4));
    //Uranus
    Particle* Uranus = new Particle(vec3(1.846778022429348E+01, 7.551054732258933E+00, 0), vec3(1.846778022429348E+01, 7.551054732258933E+00, 0)*365.25, 4.365510645*pow(10,-5));
    //Venus
    //Particle* Venus = new Particle(vec3(1.422942118656473E-01, -7.105570386923493E-01, 0), vec3(1.971755883600314E-02*365, 3.794686413925673E-03*365, 0), 2.448273712E-06);
    system.addParticle(Sun);
    system.addParticle(Earth);
    system.addParticle(Mars);
    system.addParticle(Jupiter);
    system.addParticle(Neptune);
    system.addParticle(Saturn);
    system.addParticle(Uranus);
    //system.addParticle(Venus);

}

std::string SolarSystem::getName() {
    return "Solar system";
}
