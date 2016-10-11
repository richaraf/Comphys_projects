# ODE integrator for FYS3150 project 3
This is an example class structure for project FYS3150 project 3, 2016: The solar system. 

## Making this code a basis for your own project
If you wish, you may [fork](https://help.github.com/articles/fork-a-repo/) this repository and use it as a basis for your own code. If you do, you will have to implement a lot of the crucial functions yourself. The relevant functions you need to implement are spread throughout the project, but they are all commented with a note saying what each function should do.

Please note that this is only a start, and when you have implemented all of these functions you will only have completed the first part of the exercise. However, once this is done, you will have a very good basis for further work, and adding functionality will be easier with a good class structure such as this one.

If you choose to make this code the basis of your code, start by following the steps listed under _Getting started_.

## Getting started
Here follows a step by step guide to getting started with using this class structure in your own project.
- The first thing you should do is fork this repository, pull it down to your computer, and make sure it compiles and runs. It should run and print some information to the terminal, but not much integration is actually done since none of the most important code snippets are implemented yet. 
- After this you should spend at least 30 minutes looking at the structure and familiarizing yourself with how the classes interact with eachother. A good way to do this is starting by the first line in the `main.cpp` file, and following the function calls from there. That should take you into `examples.cpp` which sets up a system of two bodies. Try to follow "where the code takes you," and make an effort familiar with the different classes. Note: It is not neccessary to understand everything that is happening at this point, but this may be a good time to ask the lab-instructors (or google!) about syntax which you do not understand. 
- Make sure to also take a look at the base classes, `Integrator`, `Potential`, and `InitialCondition`. Note carefully that the `System` class, which is organizing everything, does not know about any of the sub-classes (such as `Potential::NewtoninanGravity` or `Integrator::EulerCromer`).
- Once you have a fair (does not have to be perfect, learning by trial and error is an ok approach here) understanding of how the different classes interact with eachother, proceed to _completing the missing parts_.

## Completing the missing parts
Here follows a suggestion for how you can work to complete the missing parts of the code.
- Start by implementing the `NewtoninanGravity::computeForces(Particle& a, Particle& b)` method. This function should compute the forces between only the two particles a and b.
- Secondly, implement the missing `System::computeForces()` method. This should sum over all pairs of particles and compute the corresponding forces using the `NewtoninanGravity::computeForces` method which you just implemented.
- Third, you should complete the `EulerCromer::integrateOneStep()` method, which advances the ODE one time step forward. 
After you have done this, you should have a working implementation of the two-body problem. In the following, we need to do some more "fine tuning".
- Implement the `System::computeKineticEnergy()` method. If you did not do it earlier, go back to the `NewtoninanGravity::computeForces` method and calculate the potential energy. Now, when you run the code it should print energies (total, kinetic, and potential) to the terminal.
- Implement the `System::writePositionsToFile()` method.
- Implement the `System::removeLinearMomentum()` method. 
- Modify the `TwoBody::setupParticles(System* system)` method to give the correct orbit for the Sun-Earth system. 
Once done with all of the steps above, you are done with the basics of the project. You may now continue by implementing the missing `Integrator::VelocityVerlet` and the `InitialCondition::ThreeBody` classes. Later, you will go on to add more sub-classes to the project to include more example systems, a different potential, more integrators, and maybe more.




