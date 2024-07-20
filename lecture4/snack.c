// Time complexity: O(mv)
#include <stdio.h>
#include <limits.h>

#define MAX_M 100000
#define MAX_V 100000

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

int main() {
    int m, v;
    int prices[MAX_M];
    
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &prices[i]);
    }
    scanf("%d", &v);
    
    int result = min_snacks(m, prices, v);
    printf("%d\n", result);
    
    return 0;
}