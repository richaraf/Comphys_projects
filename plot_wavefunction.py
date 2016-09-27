import numpy as np
import matplotlib.pyplot as plt

#Reading "u_file.txt"
eigenvec1=[]; eigenvec2=[]; eigenvec3=[]


infile=open('u_file.txt','r')
for line in infile:
	numbers=line.split()
        if len(numbers) > 0:
                eigenvec1.append(float(numbers[0]))
                eigenvec2.append(float(numbers[1]))
                eigenvec3.append(float(numbers[2]))
infile.close()

eigenvec1 = np.array(eigenvec1)
eigenvec2 = np.array(eigenvec2)
eigenvec3 = np.array(eigenvec3)

rho=np.linspace(0,1,len(eigenvec1))

#Plot
SZ={'size':'16'}
plt.plot(rho,eigenvec1)
#plt.plot(rho,eigenvec2**2)
#plt.plot(rho,eigenvec3**2)
plt.title(r'The wavefunction plotted with three different $\omega_r$s',**SZ)
plt.xlabel(r'$\psi(\rho)$',**SZ)
plt.ylabel(r'$\rho$',**SZ)
plt.legend([r'$\omega_r=0.5$', '$\omega_r=1.0$'],loc='best')
plt.grid()
plt.show()
