import matplotlib.pyplot as plt
import numpy as np

time_list = [1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9]
error_E = [2.04334e-00,1.9172e-01,2.873e-02,2.07e-03,5.2e-04,1.6e-04,8.0e-05,8.0e-05]
error_M = [3.04950e-00,3.90410e-00,1.67623e-00,3.24477e-01,1.06978e-01,1.03671e-01,5.21412e-02,4.55952e-03]
error_Cv = [1.2105771e+01,1.490831e-00,2.28029e-01,1.6526e-02,4.155e-03,1.302e-03,6.47e-04,5.91e-04]
error_X = [1.275783e+01,1.5566813e+01,2.8581e-00,1.018e-01,1.05e-02,1.1e-02,2.6e-03,1.0e-04]

#---Plot---
SZ = {'size':'16'}

plt.plot(np.log10(time_list),np.log10(error_E),marker='o')
plt.plot(np.log10(time_list),np.log10(error_M),marker='o')
plt.plot(np.log10(time_list),np.log10(error_Cv),marker='o')
plt.plot(np.log10(time_list),np.log10(error_X),marker='o')
plt.legend([r'$\langle E\rangle$',r'$\langle M\rangle$',r'$C_v$',r'$\chi$'],loc='best')
plt.xlabel('Number of flips, $\log_{10}(C)$',**SZ)
plt.ylabel('Absolute error, $\log_{10}({\cal O})$',**SZ)
plt.axis([1,10,-5,2])
plt.grid()
plt.savefig('error_plot.png')
plt.show()
