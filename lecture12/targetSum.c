#include <stdio.h>
#include <stdlib.h>

void quickSort(int *arr, int low, int high){
    if(low < high){
        int pivot = arr[high];
        int i = low - 1;
        for(int j = low; j < high; j++){
            if(arr[j] < pivot){
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
    }
}

void targetSum(int *arr, int n, int p) {
    for (int i = 0; i < n-2; i++) {
        if (i > 0 && arr[i] == arr[i-1]) {
            continue;
        }
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            int sum = arr[i] + arr[l] + arr[r];
            
            if (sum == p) {
                printf("%d %d %d\n", arr[i], arr[l], arr[r]);
                while (l < r && arr[l] == arr[l + 1]) {
                    l++;
                }
                while (l < r && arr[r] == arr[r - 1]){
                    r--;
                }
                l++;
                r--;
            } else if (sum > p) {
                r--;
            } else {
                l++;
            }
        }
    }
}

int main(){
    int n, p, m;
    int *arr;
    scanf("%d %d", &n, &p);
    arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        scanf("%d", &m);
        arr[i] = m;
    }
    quickSort(arr, 0, n-1);
    targetSum(arr, n, p);
    return 0;
}
