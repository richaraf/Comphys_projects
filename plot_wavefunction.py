import numpy as np
import matplotlib.pyplot as plt

#Reading "eigenvectors.dat"
eigenvec1=[]; eigenvec2=[];, eigenvec3=[]
infile=open('eigenvectors.dat','r')
for line in infile:
	numbers=line.split()
	eigenvec1.append(float(numbers[0]))
	eigenvec2.append(float(numbers[1]))
    eigenvec3.append(float(numbers[2]))
infile.close()

rho=np.linspace(0,1,len(eigenvec1))

#Plot
SZ={'size':'16'}
plt.plot(x,eigenvec1)
plt.plot(x,eigenvec2)
plt.title(r'The wavefunction plotted with three different $\omega_r$s',**SZ)
plt.xlabel(r'$\psi(\rho)$',**SZ)
plt.ylabel(r'$\rho$',**SZ)
plt.legend([r'$\omega_r=0.5$', '$\omega_r=1.0$'],loc='best'])
plt.grid()
plt.show()
