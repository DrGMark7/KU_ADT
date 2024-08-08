#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct furry{
    int size_in_cm;
    int times;
    char side;
    int load_car;
} furry_t;


typedef struct queue {
    int *arr; // array-based queue
    int capacity; // size of queue
    int front; // position of front
    int rear; // position of rear
} queue_t;


queue_t create(int size) {
    queue_t q = {NULL, size, 0, -1};
    q.arr = (int *)malloc(sizeof (int) * size);
    return q;
}

int enqueue(queue_t *q, int v) {
    if (q->rear == q->capacity-1) // queue is full
        return 0;
    q->rear++; // enqueue normally
    q->arr[q->rear] = v;
    return 1;
}

int dequeue(queue_t *q) {
    int v;
    if (q->front > q->rear) // queue is empty
        return 0;
    v = q->arr[q->front]; // dequeue normally
    q->front++;
    return v;
}

int peek(queue_t *q) {
    if (q->front > q->rear) // queue is empty
        return -1;
    return q->arr[q->front];
}

void show(queue_t *q) {
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}


int main(){
    //. Input size of the furry in metes and change to cm
    //. Input a number of cars for the same furry to pass
    //. Create a queue of cars
    //. For each car, input the size of the car in cm
    //. If Car is bigger than the furry, will be departed
    //. If Car is smaller than the furry, will be add to the queue

    int size_in_m;
    int number_of_cars;

    scanf("%d", &size_in_m);

    furry_t furry = {size_in_m * 100, 0, 'L', 0};

    scanf("%d", &number_of_cars);

    queue_t R_side = create(number_of_cars);
    queue_t L_side = create(number_of_cars);

    for (int i = 0; i < number_of_cars; i++){
        int size;
        char side;
        scanf("%d %c", &size, &side);
        if (side == 'R'){
            enqueue(&R_side, size);
        } else {
            enqueue(&L_side, size);
        }
    }

    // show(R_side);
    // show(L_side);
    float start = clock();
    int car = 0;

    while (R_side.front <= R_side.rear || L_side.front <= L_side.rear){
        if (furry.side == 'L' && L_side.front <= L_side.rear){
            furry.load_car = 0;
            while (1){
                car = peek(&L_side);
                if (car == -1){
                    break;
                }

                if (furry.size_in_cm < furry.load_car + car){
                    break;
                }else{
                    car = dequeue(&L_side);
                    furry.load_car += car;
                }

                // printf("Car: Pickup %d\n", car);
            }
            furry.times++;
            furry.side = 'R';

            // printf("Furry: %d\n", furry.load_car);
            // printf("Going to the R side\n");

        }else{
            if (L_side.front > L_side.rear && R_side.front > R_side.rear){
                break;
            }
            furry.side = 'R';
            furry.times++;
        } 
        if (furry.side == 'R' && R_side.front <= R_side.rear){
            furry.load_car = 0;
            while (1){
                car = peek(&R_side);
                if (car == -1){
                    break;
                }

                if (furry.size_in_cm < furry.load_car + car){
                    break;
                }else{
                    car = dequeue(&R_side);
                    furry.load_car += car;
                }
                // printf("Car: Pickup %d\n", car);
            }
            furry.times++;
            furry.side = 'L';

            // printf("Furry: %d\n", furry.load_car);
            // printf("Going to the L side\n");

        } else{
            if (L_side.front > L_side.rear && R_side.front > R_side.rear){
                break;
            }
            furry.side = 'L';
            furry.times++;
        }
    }

    // while (R_side != NULL || L_side != NULL){
    //     if (furry.side == 'L' && L_side != NULL){
    //         furry.load_car = 0;
    //         while (1){
    //             car = peek(L_side);
    //             if (car == -1){
    //                 break;
    //             }

    //             if (furry.size_in_cm < furry.load_car + car){
    //                 break;
    //             }else{
    //                 car = dequeue(&L_side);
    //                 furry.load_car += car;
    //             }

    //             printf("Car: Pickup %d\n", car);
    //         }
    //         furry.times++;
    //         furry.side = 'R';

    //         printf("Furry: %d\n", furry.load_car);
    //         printf("Going to the R side\n");

    //     }else{
    //         if (L_side == NULL && R_side == NULL){
    //             break;
    //         }
    //         furry.side = 'R';
    //         furry.times++;
    //     } 
    //     if (furry.side == 'R' && R_side != NULL){
    //         furry.load_car = 0;
    //         while (1){
    //             car = peek(R_side);
    //             if (car == -1){
    //                 break;
    //             }

    //             if (furry.size_in_cm < furry.load_car + car){
    //                 break;
    //             }else{
    //                 car = dequeue(&R_side);
    //                 furry.load_car += car;
    //             }
    //             printf("Car: Pickup %d\n", car);
    //         }
    //         furry.times++;
    //         furry.side = 'L';

    //         printf("Furry: %d\n", furry.load_car);
    //         printf("Going to the L side\n");

    //     } else{
    //         if (L_side == NULL && R_side == NULL){
    //             break;
    //         }
    //         furry.side = 'L';
    //         furry.times++;
    //     }
    // }
    float end = clock();
    printf("%d\n", furry.times);

    printf("Time: %f\n", (end - start) / CLOCKS_PER_SEC);
    return 0;
}


