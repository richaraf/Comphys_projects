import matplotlib.pyplot as plt
import numpy as np

L = 100


T_list = [2.00, 2.05, 2.10, 2.15, 2.20, 2.25, 2.30]
infiles = []
for T in T_list:
    infiles.append('oppgdL%dT%d_file.dat'%(L, int(T*100+.5)))

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

plt.plot(T_list, data[0,:])
plt.xlabel('Temperature $T$, $[kT/J]$',**SZ)
plt.ylabel(r'Mean energy $\langle E\rangle$, $[J]$',**SZ) 
plt.grid()
plt.show()

plt.plot(T_list, data[2,:])
plt.xlabel('Temperature $T$, $[kT/J]$',**SZ)
plt.ylabel(r'Mean absolute magnetization $\langle |M|\rangle$',**SZ) 
plt.grid()
plt.show()

plt.plot(T_list, data[4,:])
plt.xlabel('Temperature $T$, $[kT/J]$',**SZ)
plt.ylabel(r'Heat capacity $C_v$, $[J^3/k^3T^2]$',**SZ) 
plt.grid()
plt.show()

plt.plot(T_list, data[5,:])
plt.xlabel('Temperature $T$, $[kT/J]$',**SZ)
plt.ylabel(r'Susceptibility $\chi$',**SZ)
plt.grid()
plt.show()
