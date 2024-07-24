#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

typedef struct people{
    int myNumber;
    int limitDrink;
    int Drink;
    int count;
    bool isOut;
} people_t;

typedef struct node{
    people_t data;
    struct node *next;
} node_t;

void printList(node_t *startNode, int n_player){
    node_t *current = startNode;
    for(int t = 0; t < n_player; t++){
        printf("%d ",  current->data.myNumber);
        printf("%d\n", current->data.limitDrink);
        current = current->next;
    }
}

void printCurrentPlayer(node_t *currentPlayer){
    printf("Current player: %d\n", currentPlayer->data.myNumber);
    printf("Current player's limit drink: %d\n", currentPlayer->data.limitDrink);
    printf("Current player's count: %d\n", currentPlayer->data.count);
    printf("Current player's drink: %d\n", currentPlayer->data.Drink);
    printf("Current player's isOut: %s\n", currentPlayer->data.isOut ? "true" : "false");
    printf("--------------------\n");
}

int main() {
    int n_player, k;
    scanf("%d %d", &n_player, &k);
    people_t player[n_player];
    
    //+ Initialize the data of the players
    int data_player[n_player];
    for(int i = 0; i < n_player; i++){
        scanf("%d", &data_player[i]);
        player[i].myNumber = i+1;
        player[i].limitDrink = data_player[i];
        player[i].count = 0;
        player[i].Drink = 0;
        player[i].isOut = false;
    }
    
    //. Assign the first player to the start node
    node_t *startNode = (node_t *)malloc(sizeof(node_t));
    startNode->data = player[0];
    startNode->next = NULL;
    //. Assign the rest of the players to the Circula linked list
    node_t *current = startNode;
    for(int i = 1; i < n_player; i++){
        node_t *newNode = (node_t *)malloc(sizeof(node_t));
        newNode->data = player[i];
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }
    current->next = startNode;   //. Assign the start node to the next node of the last node
    printList(startNode, n_player);
    printf("********** Game **********\n");

    //. ********** Game **********/

    node_t *currentPlayer = startNode;
    int counter = 0;
    for(int i = 1; i <= 30; i++){

        if (currentPlayer->data.isOut == false){
            counter++;
            currentPlayer->data.count = counter;           //. Increase the count of the current player
        }
        
        if(currentPlayer->data.count % k == 0 && currentPlayer->data.isOut == false){   //. If the count of the current player is equal to k
            currentPlayer->data.Drink++;       //. Increase the drink of the current player
        }

        if(currentPlayer->data.Drink == currentPlayer->data.limitDrink && currentPlayer->data.isOut == false){   //. If the drink of the current player is equal to the limit drink
            printf("Player %d is out\n", currentPlayer->data.myNumber);    //. Display the player is out
            currentPlayer->data.isOut = true;                              //. Assign the player is out
            printCurrentPlayer(currentPlayer);     //. Display After Next Player
        }

        
        currentPlayer = currentPlayer->next;    //. Move to the next player
    }
    printf("Counter: %d\n", counter);
    printf("End of the game\n");
    for (int i = 0; i < n_player; i++){
        printCurrentPlayer(currentPlayer);     //. Display Before Next Player
        currentPlayer = currentPlayer->next;
    }
    return 0;    
}

