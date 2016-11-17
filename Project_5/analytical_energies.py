from sympy import symbols, diff, exp, sqrt, factor, Symbol, printing
x, y, z, Z = symbols('x y z Z')
r = sqrt(x*x + y*y + z*z)
phi = (Z*r - 2)*exp(-Z*r/2)
R = Symbol('r') #Creates a symbolic equivalent of r
#print latex and c++ code
print "Latex code:", printing.latex(diff(phi, x).factor().subs(r, R))
print "C++ code:", printing.ccode(diff(phi, x).factor().subs(r, R))