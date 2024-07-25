#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

//. Create Append function

node_t *append(node_t *startNode) {
    node_t *newNode = (node_t *)malloc(sizeof(node_t));  //. Allocate memory for the new node
    scanf("%d", &newNode->data);                         //. Read the data of the new node
    newNode->next = NULL;                                //. Assign NULL to the next node of the new node
    if (startNode == NULL) {                             //. If the start node is NULL
        startNode = newNode;                             //. Assign the new node to the start node
    } else {
        node_t *current = startNode;                     //. Declare a pointer to the start node
        while (current->next != NULL) {                  //. Loop through the list until the last node
            current = current->next;                     //. Assign the next node to the current node
        }
        current->next = newNode;                         //. Assign the new node to the next node of the current node
    }
    return startNode;                                    //. Return the start node
}

//. Create Get function

void *get(node_t *startNode) {
    int index;
    scanf("%d", &index);
    
    node_t *current = startNode;
    for(int i = 0; i < index; i++){      //. Assuve that index is less than the number of nodes
        current = current->next;         //. Loop for index times 
    }
    printf("%d\n", current->data);
}

//. Create Show function
void show(node_t *startNode) {  
    node_t *current = startNode;    //. Declare a pointer to the start node
    while (current != NULL) {         
        printf("%d ", current->data);  //. Print the data of the current node use Pointer to Structure Operator (->)
        current = current->next;       //. Assign the next node to the current node
    }
    printf("\n");
}

//. Create Reverse function

node_t *reverse(node_t *startNode){
    node_t *prev = NULL;              //. Declare a pointer to the previous node
    node_t *current = startNode;      //. Declare a pointer to the start node

    while(current != NULL){           //. Loop through the list
        node_t *next = current->next; //. Declare a pointer to the next node
        current->next = prev;         //. Assign the previous node to the next node of the current node
        prev = current;               //. Assign the current node to the previous node
        current = next;               //. Assign the next node to the current node
    }
    startNode = prev;                //. Assign the previous node to the start node
    return startNode;                //. Return the start node
}

//. Create Cut function
//. Cut by range [start, end]
node_t *cut(node_t *startNode){
    
    int start, end;
    scanf("%d %d", &start, &end);
    node_t *current = startNode;    //. Declare a pointer to the start node
    node_t *prev = NULL;            //. Declare a pointer to the previous node

    for(int i = 0; i < start; i++){  //. Loop for start times
        prev = current;              //. Assign the current node to the previous node
        current = current->next;     //. Assign the next node to the current node
    }

    node_t *startCut = current;        //. Assign the current node to the start cut node
    for(int i = start; i < end; i++){  //. Loop for end-start times
        current = current->next;       //. Assign the next node to the current node
    }
    
    current->next = NULL;              //. Assign NULL to the next node of the current node

    return startCut;                   //. Return the start cut node
}

int main(void) {
    node_t *startNode;              //. Declare a pointer to the start node
    int n,i;                   
    char command;         
    startNode = NULL;               //. Initialize the start node to NULL
    scanf("%d", &n);           
    for (i=0; i<n; i++) {
        scanf(" %c", &command);
        switch (command) {
            case 'A':
                startNode = append(startNode);
                break;
            case 'G':
                get(startNode);
                break;
            case 'S':
                show(startNode);
                break;
            case 'R':
                startNode = reverse(startNode);
                break;
            case 'C':
                startNode = cut(startNode);
                break;
            default:
                break;
        }
    }
    return 0;
}