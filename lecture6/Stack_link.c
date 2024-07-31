#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct stack {
    node_t *top;
    int size;
} stack_t;

stack_t *createStack() {
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

int push(stack_t *stack, int data) {
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    if(newNode == NULL){
        return 0;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
    return 1;
}

int pop(stack_t *stack){
    if(stack->top != NULL){
        node_t *temp = stack->top;
        int data = temp->data;
        stack->top = stack->top->next;
        free(temp);
        stack->size--;
        return data;
    }else{
        return -1;
    }
}

int top(stack_t *stack){
    if(stack->top != NULL){
        return stack->top->data;
    }else{
        return -1;
    }
}

int isEmpty(stack_t *stack){
    return stack->size == 0;
}

int main(){
    
}