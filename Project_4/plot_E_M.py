from scitools.std import *
import matplotlib.pyplot as plt

infile = open("E_M_T=1_0_file.dat", "r")
t = []
E_average = []
M_average = []

for line in infile:
    words = line.split()
    t.append(float(words[0]))
    E_average.append(float(words[1]))
    M_average.append(float(words[2]))

plt.plot(t, E_average)
plt.legend(("E_average [J]"))
plt.show()

plt.plot(t, M_average)
plt.legend(( "M_average [M]"))
plt.show()
