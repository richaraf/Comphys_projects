#import numpy as np
from scitools.std import *
import matplotlib.pyplot as plt

infile = open('number_of_accept.dat', 'r')

steps = []; accept = []
for line in infile:
    numbers = line.split()
    steps.append(float(numbers[0]))
    accept.append(float(numbers[1]))
infile.close()

#---Plot---
SZ = {'size':'20'}

plt.plot(log10(steps),log10(accept),'-b')
#plt.title('Ratio of accepted sweeps as function of time', **SZ)
plt.xlabel(r'Time (MC cycles), $log_{10}$', **SZ)
plt.ylabel(r'Ratio of accepted flips, $log_{10}$', **SZ)
plt.grid()
plt.savefig('accept_vs_MCc.png')
plt.show()
