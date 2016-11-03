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

axis_size = {"size" : "20"}

plt.plot(log10(t), E_average)
plt.legend(("E_average"))
#plt.title("E_average", **axis_size)
plt.xlabel(r"number of MC cycles, $log_{10}$", **axis_size)
plt.ylabel("E_average", **axis_size)
plt.show()

plt.plot(log10(t), M_average)
plt.legend(( "M_average"))
#plt.title("M_average", **axis_size)
plt.xlabel(r"MC cycles,  $log_{10}$", **axis_size)
plt.ylabel("M_average", **axis_size)
plt.show()
