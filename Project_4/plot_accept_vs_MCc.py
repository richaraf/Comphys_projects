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

infile1 = open('number_of_accept_T=2_4_ordered.dat', 'r')

steps1 = []; accept1 = []
for line in infile1:
    numbers = line.split()
    steps1.append(float(numbers[0]))
    accept1.append(float(numbers[1]))
infile1.close()

infile2 = open('number_of_accept_T=1_0_ordered.dat', 'r')

steps2 = []; accept2 = []
for line in infile2:
    numbers = line.split()
    steps2.append(float(numbers[0]))
    accept2.append(float(numbers[1]))
infile2.close()

infile3 = open('number_of_accept_T=2_4_random.dat', 'r')

steps3 = []; accept3 = []
for line in infile3:
    numbers = line.split()
    steps3.append(float(numbers[0]))
    accept3.append(float(numbers[1]))
infile3.close()

#---Plot---
SZ = {'size':'16'}

#plt.plot(log10(steps),log10(accept),'-b')
plt.subplot(2,1,1)
plt.plot(steps,accept)
plt.plot(steps3,accept3)
plt.title('Random', **SZ)
plt.xlabel(r'Number of flips, $C$', **SZ)
plt.ylabel(r'Ratio of acceped flips', **SZ)
plt.legend(['T = 1.0', 'T = 2.4'], loc = 'best')
plt.grid()

plt.subplot(2,1,2)
plt.plot(steps2,accept2)
plt.plot(steps1,accept1)
plt.title('Ordered', **SZ)
plt.xlabel(r'Number of flips, $C$', **SZ)
plt.ylabel(r'Ratio of accepted flips', **SZ)
plt.legend(['T = 1.0', 'T = 2.4'], loc = 'best')
plt.grid()
plt.axis([0,10000,-0.1,0.5])
#plt.savefig('accept_vs_MCc.png')

plt.subplots_adjust(hspace=0.5)
plt.show()
