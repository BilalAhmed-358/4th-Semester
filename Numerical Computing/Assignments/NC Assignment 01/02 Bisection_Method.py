import math
import numpy as np
import matplotlib.pyplot as plt
def f(x):
    return x**3-5*x-9

def bisection(x0,x1,e):
    step = 1
    condition = True
    while condition:
        x2 = (x0 + x1)/2
        print('c = %0.6f and f(c) = %0.6f' % ( x2, f(x2)))

        if f(x0) * f(x2) < 0:
            x1 = x2
        else:
            x0 = x2
        
        step = step + 1
        condition = abs(f(x2)) > e

    print('\nRoot is : %0.8f' % x2)


# Converting input to float
x0 = -100
x1 = 100
e = float(math.e)

if f(x0) * f(x1) > 0.0:
    print('Given guess values do not bracket the root.')
    print('Try Again with different guess values.')
else:
    bisection(x0,x1,e)
