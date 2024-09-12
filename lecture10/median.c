#include <stdio.h>
#include <stdlib.h>

// Max Heap for lower half of numbers
typedef struct {
    int* data;
    int size;
} MaxHeap;

// Min Heap for upper half of numbers
typedef struct {
    int* data;
    int size;
} MinHeap;

// Function to initialize a Max Heap
MaxHeap* createMaxHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->data = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    return heap;
}

// Function to initialize a Min Heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    return heap;
}

// Max Heapify for MaxHeap
void maxHeapify(MaxHeap* heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left] > heap->data[largest])
        largest = left;

    if (right < heap->size && heap->data[right] > heap->data[largest])
        largest = right;

    if (largest != index) {
        int temp = heap->data[index];
        heap->data[index] = heap->data[largest];
        heap->data[largest] = temp;
        maxHeapify(heap, largest);
    }
}

// Min Heapify for MinHeap
void minHeapify(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left] < heap->data[smallest])
        smallest = left;

    if (right < heap->size && heap->data[right] < heap->data[smallest])
        smallest = right;

    if (smallest != index) {
        int temp = heap->data[index];
        heap->data[index] = heap->data[smallest];
        heap->data[smallest] = temp;
        minHeapify(heap, smallest);
    }
}

// Insert into MaxHeap
void insertMaxHeap(MaxHeap* heap, int value) {
    heap->size++;
    int index = heap->size - 1;
    heap->data[index] = value;

    // Reheapify upwards
    while (index != 0 && heap->data[(index - 1) / 2] < heap->data[index]) {
        int temp = heap->data[index];
        heap->data[index] = heap->data[(index - 1) / 2];
        heap->data[(index - 1) / 2] = temp;
        index = (index - 1) / 2;
    }
}

// Insert into MinHeap
void insertMinHeap(MinHeap* heap, int value) {
    heap->size++;
    int index = heap->size - 1;
    heap->data[index] = value;

    // Reheapify upwards
    while (index != 0 && heap->data[(index - 1) / 2] > heap->data[index]) {
        int temp = heap->data[index];
        heap->data[index] = heap->data[(index - 1) / 2];
        heap->data[(index - 1) / 2] = temp;
        index = (index - 1) / 2;
    }
}

// Extract maximum from MaxHeap
int extractMax(MaxHeap* heap) {
    int root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    maxHeapify(heap, 0);
    return root;
}

// Extract minimum from MinHeap
int extractMin(MinHeap* heap) {
    int root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return root;
}

// Function to get the current median
float getMedian(MaxHeap* maxHeap, MinHeap* minHeap) {
    if(maxHeap->size > minHeap->size)
        return (float)maxHeap->data[0];
    else
        return (maxHeap->data[0] + minHeap->data[0]) / 2.0;
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    MaxHeap* maxHeap = createMaxHeap(n);
    MinHeap* minHeap = createMinHeap(n);

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        // Insert into appropriate heap
        if (maxHeap->size == 0 || num <= maxHeap->data[0]) {
            insertMaxHeap(maxHeap, num);
        } else {
            insertMinHeap(minHeap, num);
        }

        // Rebalance the heaps if necessary
        if (maxHeap->size > minHeap->size + 1) {
            int max = extractMax(maxHeap);
            insertMinHeap(minHeap, max);
        } else if (minHeap->size > maxHeap->size) {
            int min = extractMin(minHeap);
            insertMaxHeap(maxHeap, min);
        }

        // Print the current median
        printf("%.1f\n", getMedian(maxHeap, minHeap));
    }

    // Free memory
    free(maxHeap->data);
    free(minHeap->data);
    free(maxHeap);
    free(minHeap);

    return 0;
}
