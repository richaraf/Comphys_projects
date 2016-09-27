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

N = len(eigenvec1) - 1;
rho = np.zeros(N+1)
rho[0] = 0.0
rho[-1] = 5.0

h = (rho[-1] - rho[0])/(N)

#Lager rho
for i in range(N):
        rho[i] = rho[0] + i*h;


#Plot
SZ={'size':'18'}
plt.plot(rho,eigenvec1**2)
plt.plot(rho,eigenvec2**2)
plt.plot(rho,eigenvec3**2)
plt.title(r'The three lowest wave functions, two electrons, $\omega$ = 0.01 ',**SZ)
plt.xlabel(r'$\rho$',**SZ)
plt.ylabel(r' $|\psi(\rho)|\cdot|\psi(\rho)|$',**SZ)
plt.legend([r'|u_0|**2', '|u_1|**2', '|u_3|**2'],loc='best')
plt.grid()
plt.show()
