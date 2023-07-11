print("This is Taylor Polynomial File")
import math
import numpy as np
import matplotlib.pyplot as plt

def func_sin(x, n):
    sin_approx = 0
    for i in range(n):
        coef = (-1)**(i)
        num = x**((2*i)+1)
        denom = math.factorial((2*i)+1)
        sin_approx += ( coef ) * ( (num)/(denom) )
    
    return sin_approx
angles = np.arange(-2*np.pi,2*np.pi,0.1)
p_sin = np.sin(angles)
t_sin = [func_sin(angle,5) for angle in angles]

fig, ax = plt.subplots()
ax.plot(angles,p_sin)
ax.plot(angles,t_sin)
ax.set_ylim([-5,5])
plt.xlabel("Value of Angles (in radians)")
plt.ylabel("Value of sin()")
plt.title("Value of sin() approximated using Taylor's polynomial\n as compared to the actual function", loc= 'center')

plt.show()