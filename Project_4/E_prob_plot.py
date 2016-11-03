from scitools.std import *
import numpy as np
import matplotlib.pyplot as plt

infile = open("E_prob_file.dat", "r")

E = []

for line in infile:
    words = line.split()
    E.append(float(words[1]))


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
    
Freq_array = array(Freq_array)
Prob_array = Freq_array/sum(Freq_array)

#plot(Measure_array, Prob_array)
width = 0.9
plt.bar(Measure_array, Prob_array,  width = width)
plt.show()
