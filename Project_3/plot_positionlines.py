import matplotlib.pyplot as plt
import numpy as np

R = []
n = 0
with  open('positions.dat', 'r') as inFile :
    str = inFile.readline()
    str = str.split()
    n = len(str)/2
    num_lines = sum(1 for line in open('positions.dat'))


'''
for i in xrange(n) :
    R.append([])

# R = [[],[],[],..]
'''

infile = open('positions.dat', 'r')

R = np.zeros([n,num_lines])
j = 0
for line in infile:
    words= line.split()
    for i in xrange(n):
        R[0][j] = float(words[2*i])
        R[1][j] = float(words[2*i+1])

    j += 1


planets = ['Sun', 'Earth', 'Jupiter']
colors = ['oy', '.b', '.g', '.c', '.r', '.w', '.k']
ms=[8,5,5,5,5,5,5]

axis_size = {'size': '18'}
#plt.plot(0.0,0.0,'oy')
p=[]
#for i in xrange(len(R)):
#    p.append(planets[i])
#    for j in xrange(0,num_lines,1):
#        plt.plot(R[0][j],R[1][j])#[1],colors[i],markersize=ms[i])

plt.plot(R[0][:],R[1][:])
plt.plot(0.0,0.0,'oy')
plt.axis([-7,7,-7,7])
plt.xlabel('x-direction', **axis_size)
plt.ylabel('y-direction', **axis_size)
plt.grid()
plt.show()
