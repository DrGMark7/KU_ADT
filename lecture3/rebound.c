#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *data;
    int size;
    int capacity;
} Set;

void initSet(Set *set, int capacity) {
    set->data = (Point *)malloc(sizeof(Point) * capacity);
    set->size = 0;
    set->capacity = capacity;
}

int containsSet(Set *set, int x, int y) {
    for (int i = 0; i < set->size; i++) {
        if (set->data[i].x == x && set->data[i].y == y) {
            return 1;
        }
    }
    return 0;
}

void insertSet(Set *set, int x, int y) {
    if (containsSet(set, x, y)) return;
    if (set->size == set->capacity) {
        set->capacity *= 2;
        set->data = (Point *)realloc(set->data, sizeof(Point) * set->capacity);
    }
    set->data[set->size].x = x;
    set->data[set->size].y = y;
    set->size++;
}

void freeSet(Set *set) {
    free(set->data);
}

int countCellsPassed(int N, int M, int x, int y, int d) {
    int directions[8][2] = {
        {0, -1},   // N
        {1, -1},   // NE
        {1, 0},    // E
        {1, 1},    // SE
        {0, 1},    // S
        {-1, 1},   // SW
        {-1, 0},   // W
        {-1, -1}   // NW
    };
    
    Set visited;
    initSet(&visited, 100);
    insertSet(&visited, x, y);
    
    while (1) {
        int dx = directions[d][0];
        int dy = directions[d][1];
        int nx = x + dx;
        int ny = y + dy;
        
        if (nx < 0 || nx >= M) {
            dx = -dx;
            d = (d + 4) % 8;
        }
        
        if (ny < 0 || ny >= N) {
            dy = -dy;
            d = (d + 4) % 8;
        }
        
        x += dx;
        y += dy;

        if (containsSet(&visited, x, y)) {
            break;
        }
        
        insertSet(&visited, x, y);
    }
    
    int result = visited.size;
    freeSet(&visited);
    return result;
}

int main() {
    int N, M, x, y, d;
    scanf("%d %d %d %d %d\n", &N, &M, &x, &y, &d);
    
    int result = countCellsPassed(N, M, x, y, d);
    printf("%d\n", result);
    return 0;
}
