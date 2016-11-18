from sympy import symbols, diff, exp, sqrt, factor, Symbol, printing, latex, simplify
from IPython.display import display

#x, y, z, Z = symbols('x y z Z')

r1, r2, alpha, beta, omega, C = symbols('r1 r2 alpha beta omega C')

Psi_T2 = C*(-alpha*omega*r1)*exp(-alpha*omega*(r1**2+r2**2)/2.)*exp(sqrt(r1-r2)/(2.*(1+beta*sqrt(r1-r2))))

der1 = Psi_T2.diff(r1)
der2 = der1.diff(r2)

print simplify(der2)

#print latex(der2)

#display(der2)

#r = sqrt(x*x + y*y + z*z)
#phi = (Z*r - 2)*exp(-Z*r/2)

#R = Symbol('r') #Creates a symbolic equivalent of r

#print latex and c++ code
#print "Latex code:", printing.latex(diff(phi, x).factor().subs(r, R))
#print "C++ code:", printing.ccode(diff(phi, x).factor().subs(r, R))
