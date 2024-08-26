#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create_node(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insert_node(Node **head, int data) {
    Node *node = create_node(data);
    node->next = *head;
    *head = node;
}

void delete_node(Node **head, int data) {
    Node *prev = NULL;
    Node *curr = *head;  
    while (curr != NULL) {
        if (curr->data == data) {
            if (prev == NULL) {
                *head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void delete_node_p(Node **head, Node *p){
    Node *prev = NULL;
    Node *curr = *head;             //. Assign the head to curr (is local variable)
    while (curr != NULL) {          //. Loop through the list
        if (curr == p) {            //. If the current node is the node to be deleted
            if (prev == NULL) {     //. If the previous node is NULL, then the head is the node to be deleted 
                *head = curr->next; //. Assign the next node to the head
            } else {                       
                prev->next = curr->next; //. Assign the next node of the current node to the next node of the previous node
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

int detele_after(Node *head, Node *p){
    Node *temp = NULL;
    if (p == NULL || p->next == NULL){
        return 0;
    }
    temp = p->next;
    
    p->next = temp->next->next;
    
    free(temp);
    return 1;
}

void print_list(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void free_list(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
}


int main() {
    Node *head = NULL;
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);
    insert_node(&head, 5);
    print_list(head);
    
    delete_node(&head, 3);
    print_list(head);
    
    free_list(head);
    
    return 0;
}