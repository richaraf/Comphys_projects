import numpy as np
import matplotlib.pyplot as plt

with open('energies.dat', 'r') as ins:
    energies = [0.0]
    for line in ins:
        energies.append(float(line))
del energies[-1] # delete empty line


plt.plot(energies)
plt.axis([0, len(energies), energies[10]*0.9, energies[10]*1.1])
plt.show()