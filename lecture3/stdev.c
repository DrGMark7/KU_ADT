#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double findSD (int *nums, int n){

    double sigma;
    double sum = 0;
    double mean;
    double sumOfSquares = 0;
    for (int i = 0; i < n; i++){
        sum += *(nums+i);
    }

    mean = sum/n;

    for (int i = 0; i < n; i++){
        sumOfSquares += (*(nums+i) - mean) * (*(nums+i) - mean);
    }
    
    sigma = sqrt(sumOfSquares/n);
    return sigma;
}

int main(void) {
    int n, i;
    double result;
    int *nums;
    scanf("%d", &n);
    
    nums = (int *)malloc(sizeof(int) *n);
    
    for (i=0; i<n; i++){
        scanf("%d", nums+i);
    }
    result = findSD(nums, n);
    printf("%.2f", result);
    return 0;
}