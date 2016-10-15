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

#---Static plot---
planets = ['Sun', 'Earth', 'Mars', 'Jupiter']
colors = ['oy', '.b', '.g', '.c', '.r', '.w', '.k']
ms=[8,5,5,5,5,5,5,5,5]
colors = colors + colors

#plt.plot(0.0,0.0,'oy')
p=[]
for i in xrange(len(R)):
    p.append(planets[i])
    for j in xrange(1,len(R[1]),1):
        plt.plot(R[i][j][0],R[i][j][1],colors[i], markersize=ms[i])#, label=planets[i])
plt.axis([-1.55,1.55,-1.25,1.25])
plt.xlabel('x-direction')
plt.ylabel('y-direction')
plt.legend(p,loc='best')
plt.grid()
plt.show()

#---Dynamic plot---
pylab.ion()
limits = (-10.0, 10.0)
fig = plt.figure()
ax = fig.add_subplot(111, autoscale_on = False, xlim= limits, ylim=limits)

colors = ['yo', 'bo', 'co', 'go', 'ro', 'wo', 'ko']
colors = colors + colors

#line, = ax.plot(0,0, "ro")
lines = [ax.plot([], [], colors[k],markersize=ms[k],label=planets[k])[0] for k in range(n)]
pylab.legend(loc='best')
pylab.xlabel('x-direction')
pylab.ylabel('y-direction')
pylab.show()

for i in xrange(0, lineNum, 50):
    for k in xrange(n):
        lines[k].set_data(R[k][i][0], R[k][i][1])
    pylab.draw()
pylab.close()
