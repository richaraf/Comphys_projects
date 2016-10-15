import matplotlib.pyplot as plt

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

planets = ['Sun', 'Earth', 'Mars', 'Jupiter']
colors = ['oy', '.b', '.g', '.c', '.r', '.w', '.k']
ms=[8,5,5,5,5,5,5]

#plt.plot(0.0,0.0,'oy')
p=[]
for i in xrange(len(R)):
    p.append(planets[i])
    for j in xrange(1,len(R[1]),1):
        plt.plot(R[i][j][0],R[i][j][1],colors[i], markersize=ms[i])
plt.axis([-1.55,1.55,-1.25,1.25])
plt.xlabel('x-direction')
plt.ylabel('y-direction')
plt.legend(p,loc='best')
plt.grid()
plt.show()
