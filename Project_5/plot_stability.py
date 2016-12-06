import numpy as np
import matplotlib.pyplot as plt

file_length = 17
data = []
MC_list= [10**(0.5*(i+1)) for i in range(file_length)]

infile = open('E_L1_file_MCs.dat', 'r')

for line in infile:
    numbers = line.split()
    data.append(numbers[1])

label_size = {'size':'16'}

plt.plot(np.log10(MC_list),data,linewidth=2)
plt.xlabel('Number of Monte Carlo simulations, $\log_{10}(N)$',**label_size)
plt.ylabel('Local energy, $E_{L1}$',**label_size)
plt.grid()
plt.show()
