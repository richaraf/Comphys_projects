import matplotlib.pyplot as plt
import numpy as np
"""
def read_file(myfile):
    eigenvec1=[];eigenvec2=[];eigenvec3=[]
    infile=open(myfile,'r')

    M = 0
    for line in infile:
	    numbers=line.split()
            print numbers
            N = len(numbers)
            M += 1
    values = np.zeros([N,M])
    i = 0; j = 0

    infile=open(myfile,'r')
    for line in infile:
	    numbers=line.split()
            print numbers
            for number in numbers:
                print number
                values[j,i] = number
                j += 1
            i += 1
    infile.close()
    return values
"""
#--Importing rho and omega--
infile=open('variable_file.txt','r')
elements=[]
for line in infile:
	numbers=line.split()
        if len(numbers) > 0:
            elements.append(float(numbers[0]))
infile.close()
print elements
rho_max = elements[0]
omega = elements[1]

#--Reading u_interact file--
infile=open('u_interact.txt','r')
u_interact=[]
for line in infile:
	numbers=line.split()
        if len(numbers) > 0:
            u_interact.append(float(numbers[0]))
infile.close()
u_interact = np.array(u_interact)

#--Reading u_noninteract file--
infile=open('u_noninteract.txt','r')
u_noninteract=[]
for line in infile:
	numbers=line.split()
        if len(numbers) > 0:
            u_noninteract.append(float(numbers[0]))
infile.close()
u_noninteract = np.array(u_noninteract)

N = len(u_interact) - 1;
rho = np.zeros(N+1)
rho[0] = 0.0
rho[-1] = rho_max

h = (rho[-1] - rho[0])/(N)

#Lager rho
for i in range(N):
        rho[i] = rho[0] + i*h;

#Plot
SZ={'size':'18'}
plt.plot(rho,u_interact**2)
plt.plot(rho,u_noninteract**2)
plt.title(r'The ground state of two electron systems $\omega$ = 0.5 ',**SZ)
plt.xlabel(r'$\rho$',**SZ)
plt.ylabel(r' $|\psi(\rho)|\cdot|\psi(\rho)|$',**SZ)
plt.legend(['$|u_{interact}|^2$', '$|u_{noninteract}|^2$'],loc='best')
plt.grid()
plt.show()
