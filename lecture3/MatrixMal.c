#include <stdio.h>
#define ROW 5
#define COL 5

int main() {
    
    int a[ROW][COL] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int b[ROW][COL] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int c[ROW][COL] = {0};

    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            for(int k = 0; k < COL; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}