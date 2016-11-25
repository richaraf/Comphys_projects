import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

infiles = ['E_L2_file_omega=1.dat']#, 'E_L2_file_omega=0_5.dat', 'E_L2_file_omega=0_01.dat']

number_of_lines = 0
with open('E_L2_file_omega=1.dat','r') as fil:
    for line in fil:
        number_of_lines += 1

data = np.zeros(shape=[len(infiles), number_of_lines, 4])

i = 0
for infile in infiles:
    myfile = open(infile, 'r')
    j = 0
    for line in myfile:
        numbers = line.split()
        for k in range(4):
            data[i,j,k] = numbers[k]
        j += 1

    label_size = {'size':'16'}

    geir = data[i, :, 0][::11]
    even = data[i, :, 1][::11]
    espen = data[i, :, 2][::11]
    lars = data[i, :, 3][::11]
    plt.plot(geir, espen)

    aksel = np.zeros([21,11])
    brede = np.zeros([21,11])
    tom   = np.zeros([21,11])
    tor   = np.zeros([21,11])

    h = 0
    for u in range(21):
        for v in range(11):
            tor[u,v]   = data[0,h, 3]
            aksel[u,v] = data[0,h, 2]
            brede[u,v] = data[0,h, 1]
            tom[u,v]   = data[0,h, 0]
            h += 1

    plt.figure()
    plt.contourf(tom, brede, aksel, 50)
    plt.colorbar()
    plt.xlabel(r'Variational paramater, $\beta$',**label_size)
    plt.ylabel(r'Variational parameter, $\alpha$',**label_size)

    fig1 = plt.figure()
    ax = fig1.add_subplot(111, projection='3d') 
    ax.set_xlabel(r'Variational parameter, $\alpha$',**label_size)
    ax.set_ylabel(r'Variational parameter, $\beta$',**label_size)
    ax.set_zlabel(r'Local energy, $E_{L2}$',**label_size)
    ax.plot_surface(tom, brede, aksel)

    fig2 = plt.figure()
    ax = fig2.add_subplot(111, projection='3d') 
    ax.set_xlabel(r'Variational parameter, $\alpha$',**label_size)
    ax.set_ylabel(r'Variational parameter, $\beta$',**label_size)
    ax.set_zlabel(r'Energy variance, $\sigma_E^2$',**label_size)
    ax.plot_surface(tom, brede, tor)
    plt.show()
    i += 1
