import matplotlib.pyplot as plt
import numpy as np

number_of_frequences = 100
number_of_parameters = 4

data1 = np.zeros([number_of_parameters, number_of_frequences])
data2 = np.zeros([number_of_parameters, number_of_frequences])

#---READ FILE---
infile = open('E_L1_file_omegas.dat', 'r')
j = 0
for line in infile:
    numbers = line.split()
    for k in range(number_of_parameters):
        data1[k,j] = numbers[k+4]
    j += 1

infile = open('E_L2_file_omegas.dat', 'r')
j = 0
for line in infile:
    numbers = line.split()
    for k in range(number_of_parameters):
        data2[k,j] = numbers[k+4]
    j += 1

#---PLOT---
label_size = {'size':'16'}

plt.plot(data1[0], data1[2]/data1[3], label=r'$E_{L1}$', linewidth=2)
plt.plot(data1[0], data2[2]/data2[3], label=r'$E_{L2}$', linewidth=2)
plt.xlabel('Frequency, $\omega$', **label_size)
plt.ylabel(r'Energy ratio, $\langle T\rangle/\langle V\rangle$', **label_size)
plt.legend(loc='best')
plt.xlim([0.0,1.1])
plt.grid()
plt.show()
