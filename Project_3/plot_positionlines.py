from scitools.std import *
import matplotlib.pyplot as plt
import pylab
import numpy as np
import sys
'''
pylab.ion()
limits = (-10.0, 10.0)
fig = plt.figure()
ax = fig.add_subplot(111, autoscale_on = False, xlim= limits, ylim=limits)
'''
R = []
n = 0
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
    words= line.split()
    for i in xrange(n):
        R[i].append([float(words[2*i]), float(words[2*i+1])])

'''
colors = ['bo', 'go', 'co', 'yo', 'ro']
colors = colors + colors
line, = ax.plot(0,0, "ro")
lines = [ax.plot([], [], colors[k])[0] for k in range(n)]


pylab.show()


for i in xrange(0, lineNum, 50):
    for k in xrange(n):
        lines[k].set_data(R[k][i][0], R[k][i][1])
    pylab.draw()

raw_input()  
'''


plt.figure(2)
plt.hold('on')
for i in xrange(0, lineNum, 1000):
    for k in xrange(n):
        plt.plot(R[k][i][0], R[k][i][1])
plt.axis([-2,2,-2,2])
plt.show()
#raw_input()  
