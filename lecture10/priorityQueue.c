#include <stdio.h>
#include <stdlib.h>
typedef struct heap {
    int *data;
    int last_index;
} heap_t;

heap_t *init_heap(int m) {
    heap_t *heap = (heap_t *)malloc(sizeof(heap_t));
    heap->data = (int *)malloc(sizeof(int) * (m+1)); // Return Array Pointer of m+1 integers
    heap->last_index = 0;
    return heap;
}

//. Example 
//. m = 5
//. [0, 0, 0, 0, 0, 0]
//. Insert 2
//. [0, 2, 0, 0, 0, 0]
//. Insert 3
//. [0, 3, 2, 0, 0, 0]
//. Insert 4
//. [0, 4, 2, 3, 0, 0]


void insert(heap_t *heap, int data) {
    int i;
    i = ++heap->last_index;
    while (i != 1 && data > heap->data[i/2]) {
        heap->data[i] = heap->data[i/2];
        i /= 2;
    }
    heap->data[i] = data;
}

void delete_max(heap_t *heap) {
    int parent, child;
    int temp;
    if (heap->last_index == 0) {
        return;
    }
    temp = heap->data[heap->last_index--];
    parent = 1;
    child = 2;
    while (child <= heap->last_index) {
        if (child < heap->last_index && heap->data[child] < heap->data[child+1]) {
            child++;
        }
        if (temp >= heap->data[child]) {
            break;
        }
        heap->data[parent] = heap->data[child];
        parent = child;
        child *= 2;
    }
    heap->data[parent] = temp;
}

int find_max(heap_t *heap) {
    if (heap->last_index == 0) {
        return -1;
    }
    return heap->data[1];
}

void update_key(heap_t *heap, int old_key, int new_key) {
    int i;
    for (i=1; i<=heap->last_index; i++) {
        if (heap->data[i] == old_key) {
            heap->data[i] = new_key;
            break;
        }
    }

    while (i != 1 && new_key > heap->data[i/2]) {  //. Update all data in the heap
        heap->data[i] = heap->data[i/2];           //. if the new_key is greater than the parent
        i /= 2;
    }
    heap->data[i] = new_key;
}

void bfs(heap_t *heap) {
    int i;
    for (i=1; i<=heap->last_index; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}


int main(void) {
    heap_t *max_heap = NULL;
    int m, n, i;
    int command, data;
    int old_key, new_key;
    scanf("%d %d", &m, &n);
    max_heap = init_heap(m);
    for (i=0; i<n; i++) {
        scanf("%d", &command);
        switch (command) {
            case 1:
                scanf("%d", &data);
                insert(max_heap, data);
                break;
            case 2:
                delete_max(max_heap);
                break;
            case 3:
                printf("%d\n", find_max(max_heap));
                break;
            case 4:
                scanf("%d %d", &old_key, &new_key);
                update_key(max_heap, old_key,
                new_key);
                break;
            case 5:
                bfs(max_heap);
                break;
        }
    }
    return 0;
}