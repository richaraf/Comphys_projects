import matplotlib.pyplot as plt
import numpy as np

L = 140

T_list = [200, 205, 210, 215, 220, 225, 230]
infiles = []
for T in T_list:
    infiles.append('oppgdL%dT%d_file.dat'%(L, T))

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
plt.ylabel(r'Heat capacity $C_v$, $[J^2/k^3T]$',**SZ) 
plt.grid()
plt.show()

plt.plot(T_list, data[5,:])
plt.xlabel('Temperature $T$, $[kT/J]$',**SZ)
plt.ylabel(r'Susceptibility $\chi$',**SZ)
plt.grid()
plt.show()
