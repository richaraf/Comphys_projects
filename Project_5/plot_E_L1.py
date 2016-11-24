import matplotlib.pyplot as plt
import numpy as np

infiles = ['E_L1_file_omega=1_0.dat', 'E_L1_file_omega=0_5.dat', 'E_L1_file_omega=0_01.dat']

data = np.zeros(shape=[len(infiles),21,3])

i = 0
for infile in infiles:
    myfile = open(infile, 'r')
    j = 0
    for line in myfile:
        numbers = line.split()
        for k in range(3):
            data[i,j,k] = numbers[k]
        j += 1
    i += 1

#---PLOT---
label_size = {'size':'16'}

#---Plot energy and variance in the same plot---
fig, ax1 = plt.subplots()
ax1.plot(data[2,:,0], data[2,:,1], color = 'k', label = 'Energy')
ax1.set_xlabel(r'Variational parameter, $\alpha$',**label_size)
ax1.set_ylabel(r'Local energy, $E_{L1}(\alpha)$', fontsize = 16, color='k')
for tl in ax1.get_yticklabels():
    tl.set_color('k')
ax1.legend(loc='lower left')

ax2 = ax1.twinx()
ax2.plot(data[2,:,0], data[2,:,2],color = 'r', linestyle = '--')
ax2.set_ylabel(r'Variance, $\sigma_E^2$', fontsize = 16, color='r')
for tl in ax2.get_yticklabels():
    tl.set_color('r')
ax2.axis([0.94, 1.06, 0.00, 1e-6])
ax2.legend(['Variance'],loc='lower right')
plt.show()
'''
#---Plot energy---
for i in range(len(infiles)):
    plt.plot(data[i,:,0], data[i,:,1],label = 'r')
plt.xlabel(r'Variational parameter, $\alpha$',**label_size)
plt.ylabel(r'Local energy, $E_{L1}(\alpha)$',**label_size)
plt.grid()
plt.show()

#---Plot energy---
for i in range(len(infiles)):
    plt.plot(data[i,:,0], np.log10(data[i,:,2]),label = 'r')
plt.xlabel(r'Variational parameter, $\alpha$',**label_size)
plt.ylabel(r'Local energy, $E_{L1}(\alpha)$',**label_size)
plt.grid()
plt.show()
'''
