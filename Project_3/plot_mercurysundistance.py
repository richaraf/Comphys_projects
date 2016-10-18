import matplotlib.pyplot as plt
import numpy as np


x = []
y = []
r = []
with open('mercurypositions.dat', 'r') as infile:
    for line in infile:
        words = line.split()
        x.append(float(words[0]))
        y.append(float(words[1]))
        r.append(float(words[2]))

plt.figure()
plt.plot(r)
plt.show()
