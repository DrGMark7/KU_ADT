#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int rowDir[] = {-1, 1, 0, 0};
int colDir[] = {0, 0, -1, 1};

int isValid(char **maze, int **visited, int x, int y, int num_row_col) {
    return (x >= 0 && x < num_row_col && y >= 0 && y < num_row_col && maze[x][y] != '#' && !visited[x][y]);
}

bool traverseMaze(char **maze, int **visited, int x, int y, int end_x, int end_y, int num_row_col) {
    if (x == end_x && y == end_y) {
        visited[x][y] = 1;
        return true;
    }
    
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int next_x = x + rowDir[i];
        int next_y = y + colDir[i];

        if (isValid(maze, visited, next_x, next_y, num_row_col)){    
            if (traverseMaze(maze, visited, next_x, next_y, end_x, end_y, num_row_col)) {
                return true;
            }
        }
    }

    visited[x][y] = 0;
    return false;
}



void printMazeWithPath(char **maze, int **visited, int number_row_col,int start_x , int start_y, int end_x , int end_y) {
    for (int i = 0; i < number_row_col; i++) {
        for (int j = 0; j < number_row_col; j++) {
            if (visited[i][j]) {
                if (i == start_x && j == start_y){
                    printf("S");
                }else if (i == end_x && j == end_y){
                    printf("G");
                }else{
                    printf(".");
                }
            } else {
                printf("%c", maze[i][j]);
            }
        }
        printf("\n");
    }
}

int main(void) {
    int n_row, start_x, start_y, end_x, end_y;
    scanf("%d", &n_row);
    getchar();

    char **array_map = (char**)malloc(sizeof(char*) * n_row);
    int  **visited   = (int**)malloc(sizeof(int*) * n_row);
    for (int i = 0; i < n_row; i++) {
        array_map[i] = (char*)malloc(sizeof(char) * (n_row + 1));
        visited[i] = (int*)malloc(sizeof(int) * n_row);
    }

    for (int i = 0; i < n_row; i++) {
        fgets(array_map[i], n_row + 1, stdin);
        getchar();
    }

    for (int i = 0; i < n_row; i++) {
        for (int j = 0; j < n_row; j++) {
            if (array_map[i][j] == 'S') {
                start_x = i;
                start_y = j;
            } else if (array_map[i][j] == 'G') {
                end_x = i;
                end_y = j;
            }
        }
    }
    if (traverseMaze(array_map, visited, start_x, start_y, end_x, end_y, n_row)) {
        printMazeWithPath(array_map, visited, n_row, start_x, start_y, end_x,end_y);
    }

    for (int i = 0; i < n_row; i++) {
        free(array_map[i]);
        free(visited[i]);
    }
    free(array_map);
    free(visited);

    return 0;
}
