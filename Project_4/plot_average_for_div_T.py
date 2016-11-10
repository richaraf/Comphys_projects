import matplotlib.pyplot as plt
import numpy as np

L = 140

T_list = [2, 2.1, 2.15, 2.2]
for i in range(0,20):
	T_list.append(2.225+i*0.005)



infiles = []
for T in T_list:
    infiles.append('oppgdL%dT%d_file.dat'%(L, int(round(T*1000))))
    print int(round(T*1000))
data = np.zeros([6,len(T_list)])

i = 0
for infile in infiles:
    infile = open(infile, 'r')
    j = 0
    for line in infile:
        data[j,i] = line
        j += 1
    i += 1

#---Plot---
SZ = {'size':'16'}

parameters = [0,2,4,5] 
parameter_labels = [r'Mean energy $\langle E\rangle$, $[J]$', 
                    r'Mean energy squared $\langle E^2\rangle$, $[J^2]$',
                    r'Mean absolute magnetization $\langle |M|\rangle$',
                    r'Mean magnetization squared $\langle M^2\rangle$', 
                    r'Heat capacity $C_v$, $[J^2/k^3T]$', 
                    r'Susceptibility $\chi$']

for para in parameters:
    plt.plot(T_list, data[para,:]/L**2)
    plt.xlabel('Temperature $T$, $[kT/J]$',**SZ)
    plt.ylabel(parameter_labels[para],**SZ) 
    plt.grid()
    plt.show()


#Plot the average, heat and susceptibility for various system sizes
#in the same plot

'''
L_list = [40, 60, 100, 140]
T_list = [200, 205, 210, 215, 220, 225, 230]
data = np.zeros(shape=[6,len(T_list),len(L_list)])

k = 0
for L in L_list:
    infiles = []
    for T in T_list:
        infiles.append('oppgdL%dT%d_file.dat'%(L, T))

    i = 0
    for infile in infiles:
        infile = open(infile, 'r')
        j = 0
        for line in infile:
            data[j,i,k] = line
            j += 1
        i += 1
    k += 1

#---Plot---
for para in parameters:
    for i in range(len(L_list)):
        plt.plot(T_list, data[para][:,i]/L_list[i]**2,label="L = %d"%L_list[i])
    plt.ylabel(parameter_labels[para],**SZ)
    plt.xlabel('Temperature $T$, $[kT/J]$',**SZ)
    plt.legend(loc='best')
    plt.grid()
    plt.show()
'''
