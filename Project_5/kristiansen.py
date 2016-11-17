import numpy as np
import sys

class System:
    
    def __init__(self, Nparticles, Ndimensions, stepLength, alpha, beta, omega, numberOfMetropolisSteps):
        
        self.Nparticles               = Nparticles
        self.Ndimensions              = Ndimensions
        self.stepLength               = stepLength
        self.alpha                    = alpha
        self.beta                     = beta
        self.particles                = self.setInitialState()
        self.numberOfMetropolisSteps = numberOfMetropolisSteps
        self.omega                      = omega
        self.WaveFunction              = TrialWaveFunctionTwoParticles(self.omega)
        
    def setInitialState(self):
        
        particles = []
        
        for i in range(0,self.Nparticles):
            
            particle_i = Particle()
            
            r_init = np.zeros(self.Ndimensions)
            
            for j in range(0,self.Ndimensions):
                r_init[j] = 2.0*np.random.uniform(0,1) - 1.0 #Draw random number between -1 and 1

            particle_i.setPosition(r_init)
            particles.append(particle_i)

        return particles

    def runMetropolisSteps(self):

        nrOfAcceptedSteps = 0
        accumulatedEnergy = self.computeLocalEnergy()

        for i in range(0,self.numberOfMetropolisSteps):
            accepted = self.metropolisStep() #Do a metropolisStep
            #Sample stuff
            if(accepted):
                nrOfAcceptedSteps += 1
                accumulatedEnergy += self.computeLocalEnergy()
            else:
                accumulatedEnergy += self.computeLocalEnergy()

        print nrOfAcceptedSteps/float(self.numberOfMetropolisSteps), accumulatedEnergy/(self.numberOfMetropolisSteps+1)
            

    def metropolisStep(self):
        #Here you should implement the Metropolis Algorithm
        
        #Compute probability at current position
        PR = self.computeProbability()
        
        #Change the position of a random particle at random dimension
        random_particle  = np.random.randint(0,self.Nparticles)
        random_dimension = np.random.randint(0,self.Ndimensions)

        change = 2.0*np.random.uniform(0,1) - 1.0
        self.particles[random_particle].adjustPosition(change*self.stepLength,random_dimension)

        #Compute probability at proposed position
        PR_new = self.computeProbability()

        w = PR_new/PR

        if(w >= np.random.uniform(0,1)):
            #Accept
            return True
        else:
            #Reject step and reset position
            self.particles[random_particle].adjustPosition(-change*self.stepLength,random_dimension)
            return False

    def computeProbability(self):
        #Compute |psi_T|^2
    
    def computeLocalEnergy(self):
        #Here you want to compute the local energy using the analytical expression you derive in
        #exercise 5b.

class TrialWaveFunctionTwoParticles:
    def __init__(self, omega, alpha):
        self.omega = omega
        self.alpha = alpha
    def evaluate(self, r1, r2, alpha):
        #Evaluate the trial wavefunction
    
    def evaluateLaplacian(self,r1,r2,alpha):
        #Here you should implement the anlytical expression of the laplacian of the trial wavefunction

    #At a later stage you should also include the possibility of evaluating the wavefunction and its laplacian with
    #jastrow factor

class Particle:
    def __init__(self, dimension=3):
        self.position = np.zeros(dimension) #position[0] = x, position[1] = y, ...
    def setPosition(self, pos):
        for i in range(0,len(pos)):
            self.position[i] = pos[i]
    def adjustPosition(self, change, whichDim):
        self.position[whichDim] += change
    def getPosition(self):
        return self.position

#Nparticles  = 2
#Ndimensions = 3
#stepLength  = ...
#alpha = ...
#beta  = ...
#numberOfMetropolisSteps = int(1e5)
#omega = 1.0

#system_test = System(Nparticles,Ndimensions,stepLength,alpha,beta,omega, numberOfMetropolisSteps)
#system_test.runMetropolisSteps()
