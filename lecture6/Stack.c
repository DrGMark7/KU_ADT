#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int *arr;      //. Array to store elements (Keep Address of the first element)
    int capacity;  //. Maximum capacity of the stack
    int topstack;  //. Index of the top element
} stack_t;

stack_t *createStack(int capacity) {
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
    stack->capacity = capacity;
    stack->topstack = -1;     //. Initialize top of the stack (-1) because stack is empty
    stack->arr = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

stack_t create(int size){
    stack_t s = {NULL, size, -1};
    s.arr = (int *)malloc(s.capacity * sizeof(int));
    return s;
}

int push(stack_t stack, int data) {
    if(stack.topstack < stack.capacity-1){
        stack.topstack++;
        stack.arr[stack.topstack] = data;
        return 1;
    }else{
        return 0;
    }
}

int push_p(stack_t *stack, int data) {
    if(stack->topstack < stack->capacity-1){
        stack->topstack++;
        stack->arr[stack->topstack] = data;
        return 1;
    }else{
        return 0;
    }
}

int pop(stack_t *stack){
    if(stack->topstack >= 0){
        int data = stack->arr[stack->topstack];
        stack->topstack--;
        return data;
    }else{
        return -1;
    }
}

int top(stack_t *stack){
    if(stack->topstack >= 0){
        return stack->arr[stack->topstack];
    }else{
        return -1;
    }
}

int is_full(stack_t *stack){
    return stack->topstack == stack->capacity-1;
}

int is_empty(stack_t *stack){
    return stack->topstack == -1;
}

int main() {
    stack_t *stack = createStack(10); //. Create like Pointer
    stack_t s = create(10);           //. Create like Variable

    push(s, 10);  //. Pass by Value send a copy of the stack and then s will not be updated
    push_p(&s, 20);  //. Pass by Reference send the address of the stack and then s will be updated

    return 0;
}