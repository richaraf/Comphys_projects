from scitools.std import *
import matplotlib.pyplot as plt
import matplotlib.lines as mlines
import pylab
import numpy as np
import sys

R = []
with  open('positions.dat', 'r') as inFile :
    str = inFile.readline()
    str = str.split()
    n = len(str)/2

for i in xrange(n) :
    R.append([])        

# R = [[],[],[],..]

infile = open('positions.dat', 'r')

lineNum = 0
for line in infile:
    lineNum += 1
    words = line.split()
    for i in xrange(n):
        R[i].append([float(words[2*i]), float(words[2*i+1])])

pylab.ion()
limits = (-.5, .5)
fig = plt.figure()
ax = fig.add_subplot(111, autoscale_on = False, xlim= limits, ylim=limits)

colors = ['yo', 'bo', 'co', 'go', 'ro', 'wo', 'ko']
colors = colors + colors
ms=[8,5,5,5,5,5,5,5,5]
planets = ['Sun', 'Earth', 'Mars', 'Jupiter','a','b','c','d','e']

#line, = ax.plot(0,0, "ro")
lines = [ax.plot([], [], colors[k],markersize=ms[k],label=planets[k])[0] for k in range(n)]
pylab.legend(loc='best')
pylab.xlabel('x-direction')
pylab.ylabel('y-direction')
pylab.show()

for i in xrange(0, lineNum, 5000):
    for k in xrange(n):
        lines[k].set_data(R[k][i][0], R[k][i][1])
    pylab.draw()
pylab.close()
