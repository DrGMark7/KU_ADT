#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *arr, int size, int target){ //. O(n) data does not need to be sorted
    for(int i = 0; i < size; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int binarySearch(int *arr, int size, int target){ //. O(log n) Data must be sorted
    int left = 0;
    int right = size - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] == target){
            return mid;
        } else if(arr[mid] < target){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    
    return 0;
}