#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef node_t stack_ts;
// Write your code here

//. Note that Macbook (Darwin) Can't Define the stack as stack_t *stack_t
//. So, I defined stack_ts as node_t

stack_ts *push(stack_ts *s, int value) {
    stack_ts *newNode = (stack_ts *)malloc(sizeof(stack_ts));
    newNode->data = value;
    newNode->next = s;
    return newNode;
}

void top(stack_ts *s) {
    if (s == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("%d\n", s->data);
    }
}

stack_ts *pop(stack_ts *s) {
    if (s == NULL) {
        
    } else {
        stack_ts *temp = s;
        s = s->next;
        free(temp);
    }
    return s;
}

void empty(stack_ts *s) {
    if (s == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }
}

void size(stack_ts *s) {
    int count = 0;
    stack_ts *temp = s;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("%d\n", count);
}


int main(void) {
    stack_ts *s = NULL;
    int n, i, command, value;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &command);
        switch(command) {
            case 1:
                scanf("%d", &value);
                s = push(s, value);
                break;
            case 2:
                top(s);
                break;
            case 3:
                s = pop(s);
                break;
            case 4:
                empty(s);
                break;
            case 5:
                size(s);
                break;
        }
    }
    return 0;
}