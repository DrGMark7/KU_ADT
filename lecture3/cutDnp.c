#include <stdio.h>

int countValue(int array[], int n, int value) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] == value) {
            count++;
        }
    }
    return count;
}

int findMaxCount(int tempArray[][2], int n) {
    int maxCount = 0;
    for (int i = 0; i < n; i++) {
        if (tempArray[i][1] > maxCount) {
            maxCount = tempArray[i][1];
        }
    }
    return maxCount;
}

int bubbleSort(int array[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    int set[n];
    int array[n];
    int tempArray[n][2];

    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        tempArray[i][0] = array[i];
        tempArray[i][1] = countValue(array, n, array[i]);
    }

    int maxCount = findMaxCount(tempArray, n);
    int temp = 0;

    for (int i = 0; i < n; i++) {
        if (tempArray[i][1] == maxCount) {
            // printf("%d ", tempArray[i][1]);
            set[i] = tempArray[i][0];           
        }else {
            set[i] = 0;
        }
    }
    int now = 0;
    int previuse = 0;

    bubbleSort(set, n);

    for (int i = 0; i < n; i++) {
        if (set[i] != 0) {
            now = set[i];
            if (now != previuse) {
                printf("%d ", set[i]);
                previuse = now;
            }
        }
    }
    return 0;
}   