from scitools.std import *
import numpy as np
import matplotlib.pyplot as plt

infile = open("oppgdT24_file.dat", "r")

# run for 100000 MC cycles
# T = 1.0 sigma^2 = 16.1344, T = 2.4 sigma^2 = 3194.79

E = []
for line in infile:
    words = line.split()
    E.append(float(words[0]))


E = np.array(E)

def unique_count(a):
    unique, inverse = np.unique(a, return_inverse=True)
    count = np.zeros(len(unique), np.int)
    np.add.at(count, inverse, 1)
    return np.vstack(( unique, count)).T


Result_array = unique_count(E)
Freq_array = []
Measure_array = []

for n in range(len(Result_array)):
    Freq_array.append(Result_array[n][1])
    Measure_array.append(Result_array[n][0])
    
Measure_array = np.array(Measure_array)
Freq_array = np.array(Freq_array)
Prob_array = Freq_array/sum(Freq_array)

#---Plot---
SZ = {'size':'16'}
width = 0.9
plt.bar(Measure_array-0.5*width, Prob_array,  width = width)
plt.xlabel(r'Energy, $E/J$',**SZ)
plt.ylabel(r'Probability of energy, $P(E)$',**SZ)
plt.show()
