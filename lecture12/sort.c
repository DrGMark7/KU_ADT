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
    } //. O(n^2)
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
    } //. O(n^2)
}

void insertionSort(int *arr, int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    } //. O(n^2)
}

void quickSort(int *arr, int low, int high){
    if(low < high){
        int pivot = arr[high];
        int i = low - 1;
        for(int j = low; j < high; j++){ //. Loop from low to high - 1
            if(arr[j] < pivot){          //. if arr[j] > pivot then it will be descending order
                i++;  
                int temp = arr[i];       //. swap
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

void merge(int *arr, int low, int mid, int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++){
        L[i] = arr[low + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = low;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int low, int high){
    if(low < high){
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
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