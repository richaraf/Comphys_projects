import matplotlib.pyplot as plt
import numpy as np

infile = open('number_of_accept.dat', 'r')

steps = []; accept = []
for line in infile:
    numbers = line.split()
    steps.append(numbers[0])
    accept.append(numbers[1])
infile.close()

#---Plot---
SZ = {'size':'16'}

plt.plot(steps,accept,'-b')
plt.title('Number of accepted sweeps as function of time', **SZ)
plt.xlabel('Time, [t]', **SZ)
plt.ylabel('Number of accepted flips', **SZ)
plt.grid()
plt.savefig('accept_vs_MCc.png')
plt.show()
