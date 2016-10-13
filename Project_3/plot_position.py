from scitools.std import *
import matplotlib.pyplot as plt
import pylab
import numpy as np

pylab.ion()
limits = (-2.0, 2.0)
fig = plt.figure()
ax = fig.add_subplot(111, autoscale_on = False, xlim= limits, ylim=limits)

infile = open("positions.dat", "r")

r_0 = []
r_1 = []
r_2 = []

for line in infile:
    words= line.split()
    r_0.append([float(words[0]), float(words[1])])
    r_1.append([float(words[2]), float(words[3])])
    r_2.append([float(words[4]), float(words[5])])
#print r_1


Home, = ax.plot(r_1[0][0], r_1[0][1], "r-o")
Mars, = ax.plot(r_2[0][0], r_2[0][1], "g-o")
#Planet_1, = ax.plot(r_1_x[0], r_1_y[0], "g-o")
#Planet_5, = ax.plot(r_5_x[0], r_5_y[0], "b-o")
#Satellitt, = ax.plot(r_s_x[0], r_s_y[0], "c-o")
Sun, = ax.plot(0,0, "y-o")

pylab.show()



for i in xrange(0, 5000, 50):
    Home.set_data(r_1[i][0], r_1[i][1])
    Mars.set_data(r_2[i][0], r_2[i][1])

    #Planet_1.set_data(r_1_x[i], r_1_y[i])
    #Planet_5.set_data(r_5_x[i], r_5_y[i])
    #Satellitt.set_data(r_s_x[i], r_s_y[i])
    pylab.draw()

raw_input()  

