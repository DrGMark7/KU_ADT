#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int *arr;      //. Array to store elements (Keep Address of the first element)
    int capacity;  //. Maximum capacity of the queue
    int front;     //. Index of the front element
    int rear;      //. Index of the rear element
    int size;      //. Number of elements in the queue
} queue_t;

queue_t *createQueue(int capacity) {
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    queue->capacity = capacity;
    queue->front = 0;     //. Initialize front of the queue (0) because queue is empty
    queue->rear = -1;     //. Initialize rear of the queue (-1) because queue is empty
    queue->size = 0;      //. Initialize size of the queue (0) because queue is empty
    queue->arr = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

int enqueue(queue_t *queue, int data) {
    if(queue->size < queue->capacity){
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->arr[queue->rear] = data;
        queue->size++;
        return 1;
    }else{
        return 0;
    }
}

int dequeue(queue_t *queue){
    if(queue->size > 0){
        int data = queue->arr[queue->front];
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size--;
        return data;
    }else{
        return -1;
    }
}

int front(queue_t *queue){
    if(queue->size > 0){
        return queue->arr[queue->front];
    }else{
        return -1;
    }
}

int rear(queue_t *queue){
    if(queue->size > 0){
        return queue->arr[queue->rear];
    }else{
        return -1;
    }
}

int isEmpty(queue_t *queue){
    return queue->size == 0;
}

int isFull(queue_t *queue){
    return queue->size == queue->capacity;
}

int main(){
    queue_t *queue = createQueue(5);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printf("Front: %d\n", front(queue));
    printf("Rear: %d\n", rear(queue));
    printf("Dequeue: %d\n", dequeue(queue));
    printf("Front: %d\n", front(queue));
    printf("Rear: %d\n", rear(queue));
    enqueue(queue, 6);
    printf("Front: %d\n", front(queue));
    printf("Rear: %d\n", rear(queue));
    return 0;    
}
