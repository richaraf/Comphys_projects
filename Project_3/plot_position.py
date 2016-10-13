from scitools.std import *
import matplotlib.pyplot as plt
import pylab
import numpy as np

pylab.ion()
limits = (-33.0, 33.0)
fig = plt.figure()
ax = fig.add_subplot(111, autoscale_on = False, xlim= limits, ylim=limits)

infile = open("positions.dat", "r")

r_0 = []
r_1 = []
r_2 = []
r_3 = []
r_4 = []
r_5 = []
r_6 = []
for line in infile:
    words= line.split()
    r_0.append([float(words[0]), float(words[1])])
    r_1.append([float(words[2]), float(words[3])])
    r_2.append([float(words[4]), float(words[5])])
    r_3.append([float(words[6]), float(words[7])])
    r_4.append([float(words[8]), float(words[9])])
    r_5.append([float(words[9]), float(words[10])])
    r_6.append([float(words[11]), float(words[12])])
#print r_4

Sun, = ax.plot(r_0[0][0], r_0[0][1], "y-o")
Home, = ax.plot(r_1[0][0], r_1[0][1], "r-o")
Mars, = ax.plot(r_2[0][0], r_2[0][1], "g-o")
Jupiter, = ax.plot(r_3[0][0], r_3[0][1], "b-o")
Neptune, = ax.plot(r_4[0][0], r_4[0][1], "c-o")
Saturn, = ax.plot(r_5[0][0], r_5[0][1], "r-o")
Uranus, = ax.plot(r_6[0][0], r_6[0][1], "g-o")
#Planet_1, = ax.plot(r_1_x[0], r_1_y[0], "g-o")
#Planet_5, = ax.plot(r_5_x[0], r_5_y[0], "b-o")
#Satellitt, = ax.plot(r_s_x[0], r_s_y[0], "c-o")
#Sun, = ax.plot(0,0, "y-o")

pylab.show()



for i in xrange(0, 50000, 200):
    Home.set_data(r_1[i][0], r_1[i][1])
    Mars.set_data(r_2[i][0], r_2[i][1])
    Jupiter.set_data(r_3[i][0], r_3[i][1])
    Neptune.set_data(r_4[i][0], r_4[i][1])
    Saturn.set_data(r_5[i][0], r_5[i][1])
    Uranus.set_data(r_6[i][0], r_6[i][1])
    Sun.set_data(r_0[i][0], r_0[i][1])
    #Planet_1.set_data(r_1_x[i], r_1_y[i])
    #Planet_5.set_data(r_5_x[i], r_5_y[i])
    #Satellitt.set_data(r_s_x[i], r_s_y[i])
    #plt.legend('%d' %200*i)
    pylab.draw()

raw_input()  

