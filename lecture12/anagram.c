#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char data[50];
    struct node *next;
} node_t;

node_t *append(node_t *startNode) {
    node_t *newNode = (node_t *)malloc(sizeof(node_t));  //. Allocate memory for the new node
    scanf("%s", &newNode->data);                         //. Read the data of the new node
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

void sortString(char *string) {
   char temp;
   int i, j;
   int n = strlen(string);

   for (i = 0; i < n-1; i++) {
      for (j = i+1; j < n; j++) {
         if (string[i] > string[j]) {
            temp = string[i];
            string[i] = string[j];
            string[j] = temp;
         }
      }
   }
}

int main(){
    int m ,n;
    scanf("%d %d", &m, &n);
    node_t *startNode = NULL;

    for(int i = 0; i < m; i++){
        startNode = append(startNode);
    }
    
    for(int i = 0; i < n; i++){
        char inputTest[50];
        scanf("%s", inputTest);
        sortString(inputTest);

        node_t *current = startNode;
        
        while(current != NULL){
            char temp[50];
            memcpy(temp,current->data, 50);
            sortString(temp);
            if(strcmp(temp, inputTest) == 0){
                printf("%s ", current->data);
            }
            current = current->next;
        }
        printf("\n");
    }
    return 0;
}