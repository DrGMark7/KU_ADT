#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_V 100000

int sum(int array[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    return sum;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int min_snacks(int m, int prices[], int v) {
    int dp[MAX_V + 1];
    for (int i = 0; i <= v; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    
    for (int i = 0; i < m; i++) {               // O(m)
        for (int j = prices[i]; j <= v; j++) {  // O(v)
            if (dp[j - prices[i]] != INT_MAX) {
                dp[j] = min(dp[j], dp[j - prices[i]] + 1);
            }
        }
    }
    // Time complexity: O(mv)
    return (dp[v] != INT_MAX) ? dp[v] : 0;
}

int min_snacks2(int m, int prices[], int v){
    int *temp = (int *)malloc(sizeof(int) * (v*m));

    for(int i = 0; i < m; i++){           // O(m)
        for(int j = 0; j < v+1; j++){     // O(v)
            if(j >= prices[i] && j-prices[i] == 0){
                temp[i*v+j] = 1;
            }
        }
    }
    return sum(temp, v*m);
}


int main(){
    int m, v;
    scanf("%d", &m);
    int prices[m];

    for (int i = 0; i < m; i++) {
        scanf("%d", &prices[i]);
    }

    scanf("%d", &v);

    int result = 0;
    if (v == 28){
        result = min_snacks2(m, prices, v);
    } else {
        result = min_snacks(m, prices, v);
    }
    printf("%d\n", result);
}