import matplotlib.pyplot as plt
import numpy as np


x = []
y = []
r = []
with open('mercurypositions.dat', 'r') as infile:
    for line in infile:
        words = line.split()
        x.append(float(words[0]))
        y.append(float(words[1]))
        r.append(float(words[2]))

index_list=[]
for i in range(1,len(r)-1,1):
    if (r[i]<r[i-1]) & (r[i]<r[i+1]):
        index_list.append(i)
angles=np.zeros(len(index_list))

j=0
for i in index_list:
    angles[j]=np.arctan2(x[i], y[i])
    j+=1
print len(angles)
plt.plot(angles)
#plt.show()

plt.figure()
plt.plot(r)
plt.show()
