import math
def function  (x,A,B):
    return A*math.sin((math.pi*x)/B)   

def area (y1, y2, dx):
    return (y1+y2)*dx/2

a,b,A,B = 0.3,1.7,6,10
a,b,A,B = 1,2,1,1
n = 100

dx = (b-a)/n
sumation = 0

for i in range(1,n):
    sumation += area(function(a+i*dx,A,B),function(a+(i-1)*dx,A,B),dx)

print(sumation)