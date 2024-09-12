#include <stdio.h>
#include <stdlib.h>

// Function to find the position to insert the current element
// using binary search in a sorted portion of the array
int binarySearch(float arr[], float item, int low, int high) {
    if (low >= high) {
        return (item > arr[low]) ? (low + 1) : low;
    }

    int mid = (low + high) / 2;

    if (item == arr[mid])
        return mid + 1;                                                           

    if (item > arr[mid])
        return binarySearch(arr, item, mid + 1, high);

    return binarySearch(arr, item, low, mid - 1);
}

// Function to print the median of the stream of integers
void printMedian(float arr[], int n) {
    int i, j, pos;
    float num;
    int count = 1;

    printf("Median after reading 1 element is %.1f\n", arr[0]);

    for (i = 1; i < n; i++) {
        float median;
        j = i - 1;
        num = arr[i];

        // Find position to insert current element in sorted array
        pos = binarySearch(arr, num, 0, j);

        // Shift elements to the right to create space for insertion
        while (j >= pos) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = num;

        // Increment count of sorted elements
        count++;

        // Calculate median
        if (count % 2 != 0) {
            median = arr[count / 2];
        } else {
            median = (arr[(count / 2) - 1] + arr[count / 2]) / 2;
        }

        printf("Median after reading %d elements is %.1f\n", i + 1, median);
    }
}

int main() {
    int n;
    scanf("%d", &n);  // Read the number of elements

    float* arr = (float*)malloc(n * sizeof(float));  // Allocate memory for the array

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);  // Read each float value

        // Print the median after each element
        printMedian(arr, i + 1);
    }

    free(arr);  // Free allocated memory
    return 0;
}
