from scitools.std import *
import matplotlib.pyplot as plt

infile1 = open("E_M_T=1_0_file_random.dat", "r")
t1 = []
E_average1 = []
M_average1 = []

for line in infile1:
    words = line.split()
    t1.append(float(words[0]))
    E_average1.append(float(words[1]))
    M_average1.append(float(words[2]))

infile2 = open("E_M_T=2_4_file_random.dat", "r")
t2 = []
E_average2 = []
M_average2 = []

for line in infile2:
    words = line.split()
    t2.append(float(words[0]))
    E_average2.append(float(words[1]))
    M_average2.append(float(words[2]))

axis_size = {"size" : "16"}

plt.subplot(2,1,1)
plt.plot(log10(t1), E_average1)
plt.plot(log10(t2), E_average2)
plt.legend(("T=1.0","T=2.4"),loc='best')
#plt.title("Average energy", **axis_size)
plt.xlabel(r"Number of flips, $log_{10}(C)$", **axis_size)
plt.ylabel(r"Average energy, $\langle E\rangle/J$", **axis_size)
plt.axis([0, 8, -850, 100])
plt.grid()

plt.subplot(2,1,2)
plt.plot(log10(t1), M_average1)
plt.plot(log10(t2), M_average2)
plt.legend(["T=1.0","T=2.4"],loc='best')
#plt.title("Average magnetization", **axis_size)
plt.xlabel(r"Number of flips, $log_{10}(C)$", **axis_size)
plt.ylabel(r"Average magnetization, $\langle M\rangle$", **axis_size)
plt.axis([0, 8, 50, -450])
plt.grid()

plt.subplots_adjust(hspace=0.5)
plt.show()
