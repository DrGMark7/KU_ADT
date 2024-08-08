#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef node_t queue_ts;

typedef struct furry{
    int size_in_cm;
    int times;
    char side;
    int load_car;
} furry_t;

void enqueue(queue_ts **head, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

int dequeue(queue_ts **head) {
    if (*head == NULL) {
        return -1;
    }

    node_t *temp = *head;
    int data = temp->data;
    *head = temp->next;
    free(temp);
    return data;
}

void show(queue_ts *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int peek(queue_ts *head) {
    if (head == NULL) {
        return -1;
    }
    return head->data;
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

    queue_ts *R_side = NULL;
    queue_ts *L_side = NULL;

    scanf("%d", &size_in_m);

    furry_t furry = {size_in_m * 100, 0, 'L', 0};

    scanf("%d", &number_of_cars);

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
    while (R_side != NULL || L_side != NULL){
        if (furry.side == 'L' && L_side != NULL){
            furry.load_car = 0;
            while (1){
                car = peek(L_side);
                if (car == -1){
                    break;
                }

                if (furry.size_in_cm < furry.load_car + car){
                    break;
                }else{
                    car = dequeue(&L_side);
                    furry.load_car += car;
                }

                printf("Car: Pickup %d\n", car);
            }
            furry.times++;
            furry.side = 'R';

            printf("Furry: %d\n", furry.load_car);
            printf("Going to the R side\n");

        }else{
            if (L_side == NULL && R_side == NULL){
                break;
            }
            furry.side = 'R';
            furry.times++;
        } 
        if (furry.side == 'R' && R_side != NULL){
            furry.load_car = 0;
            while (1){
                car = peek(R_side);
                if (car == -1){
                    break;
                }

                if (furry.size_in_cm < furry.load_car + car){
                    break;
                }else{
                    car = dequeue(&R_side);
                    furry.load_car += car;
                }
                printf("Car: Pickup %d\n", car);
            }
            furry.times++;
            furry.side = 'L';

            printf("Furry: %d\n", furry.load_car);
            printf("Going to the L side\n");

        } else{
            if (L_side == NULL && R_side == NULL){
                break;
            }
            furry.side = 'L';
            furry.times++;
        }
    }
    float end = clock();
    printf("%d\n", furry.times);

    printf("Time: %f\n", (end - start) / CLOCKS_PER_SEC);
    return 0;
}