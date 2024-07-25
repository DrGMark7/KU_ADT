#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100000

typedef struct char_t{
    char c;
    struct inputChar *next;
} char_t;

void printString(char_t *startNode){
    char_t *current = startNode;
    while (current != NULL){
        printf("%c", current->c);
        current = current->next;
    }
}

void moveAfterNodetoFront(char_t *startNode){
    char_t *current = startNode;
    char_t *prev = NULL;
    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    current->next = startNode;
    startNode = current;
}

void moveAfterNodetoEnd(char_t *startNode){
    char_t *current = startNode;
    char_t *prev = NULL;
    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    current->next = NULL;
    current->next = startNode;
}

void getSizeof(char_t *startNode){
    char_t *current = startNode;
    int size = 0;
    while (current != NULL){
        size++;
        current = current->next;
    }
    printf("Size of the linked list: %d\n", size);
    printf("Size of the linked list: %d Byte \n", size*sizeof(startNode));
}   

int main(){
    // input String to the linked list
    char_t *startNode = (char_t *)malloc(sizeof(char_t));
    char_t *current = startNode;
    char_t *newNode;

    char c;
    while (1){
        scanf("%c", &c);
        if (c == '\n'){
            break;
        }
        newNode = (char_t *)malloc(sizeof(char_t));
        newNode->c = c;
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }
}