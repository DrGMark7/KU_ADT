#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x, y;
} Point;

const Point directions[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValidMove(char **maze, bool **visited, int x, int y, int size) {
    return (x >= 0 && x < size && y >= 0 && y < size && maze[x][y] != '#' && !visited[x][y]);
}

bool traverseMaze(char **maze, bool **visited, Point current, Point end, int size) {
    if (current.x == end.x && current.y == end.y) {
        visited[current.x][current.y] = true;
        return true;
    }

    visited[current.x][current.y] = true;

    for (int i = 0; i < 4; i++) {
        Point next = {current.x + directions[i].x, current.y + directions[i].y};
        if (isValidMove(maze, visited, next.x, next.y, size)) {
            if (traverseMaze(maze, visited, next, end, size)) {
                return true;
            }
        }
    }

    visited[current.x][current.y] = false;
    return false;
}

void displaySolution(char **maze, bool **visited, int size, Point start, Point end) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == start.x && j == start.y) {
                printf("S");
            } else if (i == end.x && j == end.y) {
                printf("G");
            } else if (visited[i][j]) {
                printf(".");
            } else {
                printf("%c", maze[i][j]);
            }
        }
        printf("\n");
    }
}

int main(void) {
    int size;
    scanf("%d", &size);
    getchar();

    char **maze = (char**)malloc(size * sizeof(char*));
    bool **visited = (bool**)malloc(size * sizeof(bool*));
    for (int i = 0; i < size; i++) {
        maze[i] = (char*)malloc((size + 1) * sizeof(char));
        visited[i] = (bool*)calloc(size, sizeof(bool));
        fgets(maze[i], size + 2, stdin);
    }

    Point start = {-1, -1}, end = {-1, -1};
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (maze[i][j] == 'S') {
                start = (Point){i, j};
            } else if (maze[i][j] == 'G') {
                end = (Point){i, j};
            }
        }
    }

    if (solveMaze(maze, visited, start, end, size)) {
        displaySolution(maze, visited, size, start, end);
    } else {
        printf("No solution found\n");
    }

    for (int i = 0; i < size; i++) {
        free(maze[i]);
        free(visited[i]);
    }
    free(maze);
    free(visited);

    return 0;
}