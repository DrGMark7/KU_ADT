#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef node_t stack_ts;
typedef node_t queue_ts;

void push(stack_ts **stack, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = *stack;
    *stack = new_node;
}

int pop(stack_ts **stack) {
    if (*stack == NULL) {
        return -1;
    }
    node_t *temp = *stack;
    *stack = (*stack)->next;
    int data = temp->data;
    free(temp);
    return data;
}

void enqueue(queue_ts **queue, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (*queue == NULL) {
        *queue = new_node;
    } else {
        node_t *temp = *queue;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

int dequeue(queue_ts **queue) {
    if (*queue == NULL) {
        return -1;
    }
    node_t *temp = *queue;
    *queue = (*queue)->next;
    int data = temp->data;
    free(temp);
    return data;
}

// void show(queue_ts *queue) {
//     while (queue != NULL) {
//         printf("%d ", queue->data);
//         queue = queue->next;
//     }
//     printf("\n");
// }

int check_sorted(queue_ts *queue) {
    int prev = -1;
    while (queue != NULL) {
        int data = dequeue(&queue);
        if (prev > data) {
            return 0;
        }
        prev = data;
    }
    return 1;
}

int main() {
    queue_ts *queue = NULL;
    stack_ts *stack = NULL;

    queue_ts *sorted = NULL;

    int n = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int data = 0;
        scanf("%d", &data);
        enqueue(&queue, data);
    }

    float start = clock();

    int counter = 1;
    while (queue != NULL) {
        int data = dequeue(&queue);
        
        if(data == counter) {
            enqueue(&sorted, data);
            counter++;
        } else {
            push(&stack, data);
        }

        while (stack != NULL && stack->data == counter) {
            int data = pop(&stack);
            enqueue(&sorted, data);
            counter++;
        }
    }

    while (stack != NULL) {
        int data = pop(&stack);
        enqueue(&sorted, data);
    }

    printf("%d\n", check_sorted(sorted));

    float end = clock();
    printf("Time: %f\n", (end - start) / CLOCKS_PER_SEC);
}
