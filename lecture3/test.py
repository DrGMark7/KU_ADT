class Map:
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.map = [[0 for x in range(width)] for y in range(height)]
    
    def walked(self, x, y):
        self.map[x][y] = 1
    
    def print_map(self):
        for row in self.map:
            print(row)
        print()  # Add a blank line for better readability

class Ball:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    def move(self, dx, dy):
        self.x += dx
        self.y += dy


def calculate_angle(direction):
    if direction in [0,2,4,6]:
        return 90
    else:
        return 45

def change_direction(d, x, y, m, n):
    if (x == 0 and y == 0) or (x == n-1 and y == 0) or (x == n-1 and y == m-1) or (x == 0 and y == m-1):
        d = (d + 4) % 8  #. Reverse direction
        print("Corner")

    elif (x == 0 or x == n-1):
        print("Wall X")
        if calculate_angle(d) == 90:
            d = (d + 4) % 8
        elif calculate_angle(d) == 45:
            if d in [7, 3]:
                d = d - 2
            elif d in [5, 1]:
                d = d + 2
    elif (y == 0 or y == m-1):
        print("Wall Y")
        if calculate_angle(d) == 90:
            if calculate_angle(d) == 90:
                d = (d + 4) % 8
        elif calculate_angle(d) == 45:
            if d == 5:
                d = 3
            elif d == 7:
                d = 1
            elif d == 3:
                d = 5
            elif d == 1:
                d = 7


direction_map = {
    0: (-1,0),    #. N
    1: (-1,1),    #. NE
    2: (0, 1),    #. E
    3: (1, 1),    #. SE
    4: (1, 0),    #. S
    5: (1,-1),    #. SW
    6: (0,-1),    #. W
    7: (-1,-1)    #. NW
}

direction_print = {
    0: "N",
    1: "NE",
    2: "E",
    3: "SE",
    4: "S",
    5: "SW",
    6: "W",
    7: "NW"
}

    
n, m, x, y, d = 6, 5, 0, 0, 3

myMap  = Map(m, n)
myBall = Ball(x, y)

myMap.walked(myBall.x, myBall.y)
print(myBall.y, myBall.x, f"{direction_print[d]}({d})")
myMap.print_map()

prev_sum_map = 0
count_time = 0

import time
while True:
    
    #. Change Direction
        
    if (myBall.x == 0 and myBall.y == 0) or (myBall.x == n-1 and myBall.y == 0) or (myBall.x == n-1 and myBall.y == m-1) or (myBall.x == 0 and myBall.y == m-1):
        d = (d + 4) % 8  #. Reverse direction
        print("Corner")

    elif (myBall.x == 0 or myBall.x == n-1) and count_time != 0:
        print("Wall X")
        if calculate_angle(d) == 90:
            d = (d + 4) % 8
        elif calculate_angle(d) == 45:
            if d in [7, 3]:
                d = d - 2
            elif d in [5, 1]:
                d = d + 2
    elif (myBall.y == 0 or myBall.y == m-1) and count_time != 0:
        print("Wall Y")
        if calculate_angle(d) == 90:
            if calculate_angle(d) == 90:
                d = (d + 4) % 8
        elif calculate_angle(d) == 45:
            if d == 5:
                d = 3
            elif d == 7:
                d = 1
            elif d == 3:
                d = 5
            elif d == 1:
                d = 7

    print(myBall.y, myBall.x, f"{direction_print[d]}({d})")
    myBall.move(*direction_map[d])
    myMap.walked(myBall.x, myBall.y)
    myMap.print_map()
    
    time.sleep(0.5)
    count_time += 1
    sum_map = sum(sum(myMap.map[i]) for i in range(n))
    
    if sum_map == prev_sum_map and count_time == n*m:
        break

    prev_sum_map = sum_map


print(f"Pacman changed direction {sum(sum(myMap.map[i]) for i in range(n))} times.")
