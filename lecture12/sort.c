#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){  //. if arr[j] < arr[j + 1] then it will be descending order
                int temp = arr[j];    //. swap
                arr[j] = arr[j + 1];  //. swap
                arr[j + 1] = temp;    //. swap
            }
        }
    }
}

void selectionSort(int *arr, int size){
    for(int i = 0; i < size - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}