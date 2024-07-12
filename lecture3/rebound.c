#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int boundCnt(int x, int y, int box, int cmd, int N, int M, int **table){
    int nX,nY;
    int dx,dy;
    table[y][x] += 1;
    if(cmd == 0){ //N
        nX = x, nY = 0;
        cmd = 4;
    }
    else if(cmd == 1){ //NE
        dx = M-x;
        if(dx < y) nX = x+dx, nY = y-dx;
        else nX = x+y, nY = y-y;
        
        if(nY == 0) cmd = 3;
        else cmd = 7;
    }
    else if(cmd == 2){ //E
        nX = M, nY = y;
        cmd = 6;
    }
    else if(cmd == 3){ //SE
        dx = M-x, dy = N-y; 
        if(dx < dy) nX = x+dx, nY = y+dx;
        else nX = x+dy, nY = y+dy;
        if(nX == M) cmd = 5;
        else cmd = 1;
    }
    else if(cmd == 4){ //S
        nX = N, nY = y;
        cmd = 1;
    }
    else if(cmd == 5){ //SW
        dy = N-y;
        if(x < dy) nX = x-x, nY = y+x;
        else nX = x-dy, nY = y+dy;
        if(nY == N) cmd = 7;
        else cmd = 3;
    }
    else if(cmd == 6){//W
        nX = 0, nY = y;
        cmd = 2;
    }
    else {//NW
        if(x < y) nX = x-x, nY = y-x;
        else nX = x-y, nY = y-y;
        if(nX == 0) cmd = 1;
        else cmd = 5;
    }
    if(table[nY][nX] < 1){
        box += abs(x-nX) < abs(y-nY)? abs(x-nX):abs(y-nY);
    }
    // printf("%d %d | %d %d | %d | %d\n", nY, nX, y, x, cmd, box);
    if(table[nY][nX] == 2) return box;
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++) printf("%d ", table[i][j]);
        printf("\n");
    }
    printf("\n");
    
    return boundCnt(nX, nY, box, cmd, N, M, table);
}

int main(){
    
    int N,M,x,y,direc,cnt=0;
    int **table;
    
    scanf("%d %d %d %d %d", &N, &M, &y, &x, &direc);
    table = (int **)malloc(sizeof(int *) * N);
    for(int i = 0 ; i < N; i++){
        table[i] = (int *)malloc(sizeof(int) * M);
    }

    for(int i = 0 ; i < N ; i++) for(int j = 0 ; j < M ; j++) table[i][j] = 0;
    cnt = boundCnt(x, y, 0, direc, N-1, M-1, table);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++) printf("%d ", table[i][j]);
        printf("\n");
    }
    printf("%d", cnt);

    for(int i = 0 ; i < M ; i++) free(table[i]);
    free(table);
    return 0;
}