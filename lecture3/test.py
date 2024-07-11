m,n,x,y,d = map(int, input().split())

class initMap:
    def __init__(self, m, n):
        self.m = m
        self.n = n
        self.Map = self.generate_map()

    def generate_map(self):
        return [[0 for _ in range(self.n)] for _ in range(self.m)]

    def set_spawn(self, x, y):
        self.Map[x][y] = -1

    def set_point(self, x, y):
        self.Map[x][y] = 1

    def get_point(self, x, y):
        return self.Map[x][y]

class initPacman:
    def __init__(self, x, y):
        self.x = x
        self.y = y

        self.direction_map = {
            0: (0, 1),
            1: (1, 1),
            2: (1, 0),
            3: (1,-1),
            4: (0,-1),
            5: (-1,-1),
            6: (-1,0),
            7: (-1,1)
        }

    def move(self, direction):
        dx, dy = self.direction_map[direction]
        self.x += dx
        self.y += dy
        return [self.x, self.y]

    def get_position(self):
        return self.x, self.y
        
def change_direction(direc,direcBefore,x=None,y=None):
    
    if x == None and y == None and direcBefore == None:
        if direc 
        

Map = initMap(m, n)
Pacman = initPacman(x, y)

Map.set_spawn(x, y)

while True:
    
    Pacman.move(d)
    Map.set_point(Pacman.x, Pacman.y)

    if Pacman.move(d)[0] < 0 or Pacman.move(d)[0] >= m or Pacman.move(d)[1] < 0 or Pacman.move(d)[1] >= n:
        d = change_direction(d)
    else:
        d = d
    
    if Map.get_point(Pacman.x, Pacman.y) == -1:
        break

    for i in range(m):
        for j in range(n):
            print(Map.get_point(i, j), end=' ')
        print()

