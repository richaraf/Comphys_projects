import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

infiles = ['E_L2_file_omega=1.dat']#, 'E_L2_file_omega=0_5.dat', 'E_L2_file_omega=0_01.dat']

number_of_columns = 4
number_of_alphas  = 21
number_of_betas   = 11
number_of_lines   = number_of_alphas*number_of_betas

data = np.zeros(shape=[len(infiles), number_of_lines, number_of_columns])

i = 0
for infile in infiles:
    myfile = open(infile, 'r')
    j = 0
    for line in myfile:
        numbers = line.split()
        for k in range(number_of_columns):
            data[i,j,k] = numbers[k]
        j += 1

    label_size = {'size':'16'}
    meshgrid  = np.zeros(shape=[number_of_columns, number_of_alphas, number_of_betas])

    for p in range(number_of_columns):
        h = 0
        for u in range(number_of_alphas):
            for v in range(number_of_betas):
                meshgrid[p, u, v] = data[i, h, p]
                h += 1

    label_list = [r'Local energy, $E_{L2}$',
                  r'Energy variance, $\sigma_E^2$']

    for j in range(number_of_columns-2):
        plt.figure()
        plt.contourf(meshgrid[0], meshgrid[1], meshgrid[j+2], 500)
        plt.colorbar()
        plt.title(label_list[j],**label_size)
        plt.xlabel(r'Variational parameter, $\alpha$',**label_size)
        plt.ylabel(r'Variational parameter, $\beta$',**label_size)

        fig = plt.figure()
        ax = fig.add_subplot(111, projection='3d') 
        ax.set_xlabel(r'Variational parameter, $\alpha$',**label_size)
        ax.set_ylabel(r'Variational parameter, $\beta$',**label_size)
        ax.set_zlabel(label_list[j],**label_size)
        ax.plot_surface(meshgrid[0], meshgrid[1], meshgrid[j+2]) 
    plt.show()
    i += 1
