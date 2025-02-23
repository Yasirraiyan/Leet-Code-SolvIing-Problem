Problem 1 - Basin of Attraction
Consider a differentiable function, denoted as  f(x) , that possesses multiple roots. When initiating Newton-Raphson's Method with a given starting value for  x , the process typically converges to one of the roots, barring exceptional cases outlined in the lecture slide. It stands to reason that starting points near each other should all end up at the same root, and for some functions this is true. However, it is not true in general.

A basin of attraction for a root is defined as the collection of  x -values that, under Newton iterations, converge to that specific root. In the context of this problem, you will generate color-coded plots to visualize the basins of attraction for the following functions according to the following procedure:

Find the actual roots of the function by hand (this should be easy on the functions below).
Assign each of the roots a different color.
Pick a starting point on the  x -axis and use it to start Newton-Raphson's method.
Color the starting point according to the root that it converges to.
Repeat this process for many many starting points so you get a colored picture of the  x -axis showing where the starting points converge to.
The group of points sharing a common color designation represents the basin of attraction corresponding to the root associated with that particular color.

An example basin of attraction image for a cubic function looks something like this.
image.png

Create a basin on attraction image for the function  f(x)=(x−4)(x+1) .
Create a basin on attraction image for the function  g(x)=(x−1)(x+3) .
Create a basin on attraction image for the function  h(x)=(x−4)(x−1)(x+3) .
Note: You can use matplotlib, plotly, pyplot, seaborn or whatever plotting package you want.


[36]
0s
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import math
from scipy.integrate import quad
def f(x):
  return x**2-3*x-4
def g(x):
  return x**2+2*x-3
def h(x):
  return x**3-2*x**2-11*x-12
def df(x):
  return 2*x-3
def dg(x):
  return 2*x+2
def dh(x):
  3*x**2-4*x-11
def findroot(f, df, x0, epsilon):
   while abs(f(x0))>=epsilon:
    x0=x0-f(x0)/df(x0)
   return x0;
xf = 4 
xg = 1
xh = 4  

# Tolerance
epsilon = 0.001
root_f = findroot(f, df, xf, epsilon)
print("Root for f(x) starting from xf[0]:", root_f)
root_g = findroot(g, dg, xg, epsilon)
print("Root for g(x) starting from xg[0]:", root_g)
x_vals = np.linspace(-5, 5, 400)
plt.plot(x_vals, f(x_vals), label='f(x) = x^2 - 3x - 4')
plt.plot(x_vals, g(x_vals), label='g(x) = x^2 + 2x - 3')
plt.plot(x_vals, h(x_vals), label='h(x) = x^3 - 2x^2 - 11x - 12')
plt.axhline(0, color='black', linewidth=0.5, linestyle='--')  # x-axis
plt.legend()
plt.xlabel('x')
plt.ylabel('f(x), g(x), h(x)')
plt.title('Plot of Functions')
plt.grid(True)
plt.show()

Problem 2 - The Goat Problem
To understand the problem statement, grab a pencil and a piece of paper at first!

Draw a coordinate plane
Draw a circle with radius 1 unit centered at the point (0,1). This circle will obviously be tangent to the x-axis.
Draw a circle with radius r centered at the point (0,0). Take 0<r<2 so there are two intersections of the two circles.
Label the left-hand intersection of the two circles as point A. (Point A should be in the second quadrant of your coordinate plane.)
Label the right-hand intersection of the two circles as point B. (Point B should be in the first quadrant of your coordinate plane.)
Label the point (0,0) as the point P.
A rancher has built a circular fence of radius 1 unit centered at the point (0,1) for his goat to graze. He tethers his goat at point P on the far south end of the circular fence. He wants to make the length of the goat’s chain, r, just long enough so that it can graze half of the area of the fenced region. How long should he make the chain?

Hints:

It would be helpful to write equations for both circles. Then you can use the equations to find the coordinates of the intersection points A and B.
You can either solve for the intersection points algebraically or you can use a numerical root finding technique to find the intersection points.
In any case, the intersection points will (obviously) depend on the value of r.
Set up an integral to find the area grazed by the goat.
You will likely need to use a numerical integration technique to evaluate the integral.
You might need to perform numerical integration for this problem. You can implement your own function for this or you can opt to use the scipy.integrate.quad() function.
Write your code to narrow down on the best value of r where the integral evaluates to half the area of the fenced region.


[ ]

Start coding or generate with AI.
Problem 3 - Game of Cookies
Alice is a dessert-queen who can make exceptionally yummy chocolate chip cookies. Bob is a cookie connoisseur whose hunger rivals that of the (in)famous Cookie Monster from Sesame Street. One day, Alice and Bob decide to play a game. Bob chooses an arbitrary positive integer k. Alice doesn't know what this number k is. She chooses two real numbers a and b randomly from within the interval [0,1] with uniform distribution. Suppose, you are acting as the referee in this game. You compute the square root of the sum (ak+1)2+(bk+1)2 and round it to the nearest integer. If the result is equal to k, Bob gets to eat k of Alice's cookies for free; otherwise he doesn't get to eat any cookies.

For example, if k=6, a=0.2, and b=0.85, then the value that you get would be (ak+1)2+(bk+1)2−−−−−−−−−−−−−−−−√=42.05−−−−√=6.484. After you round it to the nearest integer it becomes 6 which is equal to k. So, Bob will be allowed to eat 6 cookies.

Input
You'll be given the value of n, the number of turns of the game.

Output
Print the expected value of the total number of cookies Bob will eat, rounded to five decimal places, if he plays n turns with k=1, k=2, k=3, …, k=n (for the 1st, 2nd, 3rd, …, and nth turns respectively).

Sample Cases
Input
10

Output
10.20914

Input
73

Output
105.27674

Input
100000

Output
157055.80999

Input
69420

Output
109021.5883

Hint: You might need to perform numerical integration for this problem. You can implement your own function for this or you can opt to use the scipy.integrate.quad() function.


[ ]

Start coding or generate with AI.
Problem 4 - Geronimo!
An object falling vertically through the air is subject to friction due to air resistance as well as gravity. The function describing the position of such a function is
s(t)=s0−mgkt+m2gk2(1−e−kt/m)
where m is the mass measured in kg, g is gravity measured in meters per second per second, s0 is the initial position measured in meters, and k is the coefficient of air resistance.

If m=1kg, g=9.8ms−2, k=0.1, and s0=100m, how long will it take for the object to hit the ground?


[18]
0s
def s(s0,m,g,k,t):
  return s0-(m*g/k)*t+(m**2*g/(k**2))*(1-math.exp(-k*t/m))
t=s(100,1,9,8,0.1)
print("The result is:", t)
The result is: 99.96493811442102
Problem 5 - Int×Plot
Numerically integrate each of the functions over the interval [−1,2] with an appropriate technique and verify mathematically that your numerical integral is correct to 10 decimal places. Then provide a plot of the function along with its area beneath the curve.

f(x)=x1+x4
g(x)=(x−1)3(x−2)2
h(x)=sin(x2)
Note: Implement your own numerical integration function for this problem.


[35]
0s

from math import sin
from scipy.integrate import quad
import matplotlib.pyplot as plt
import numpy as np
import math
def f(x):
  return (x)/(1+x**4)
def g(x):
  return (((x-1)**3)*((x-2))**2)
def h(x):
 return np.sin(x**2)

resulf,errof=quad(f,-1,2)
resultg,errorg=quad(g,-1,2)
resulth,errorh=quad(h,-1,2)
print("The result of integration of f(x)is:",resulf)
print("The error of integration of f(x)is:",errof)
print("The result of integration of g(x)is:",resultg)
print("The error of integration of g(x)is:",errorg)
print("The result of integration of h(x)is:",resulth)
print("The error of integration of h(x)is:",errorh)
plt.xlabel('x')
plt.ylabel('y')
plt.show()
x=np.linspace(-1,2,10)
xf = f(x)
xg = g(x)
xh = h(x)
plt.xlabel('x')
#plt.ylabel('y')
plt.ylabel('f(x),g(x),h(x)')
plt.legend()
plt.plot(x,xf,label='f(x)')
plt.plot(x,xg,label='g(x)')
plt.plot(x,xh,label='h(x)')
plt.title('Functions f(x), g(x), and h(x)')
plt.show()



