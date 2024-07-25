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

bool check_number(int countNumber ,int k){
    if (countNumber % k == 0){
        return true;
    }
    while (countNumber > 0){
        if(countNumber % 10 == k){
            return true;
        }
        countNumber = countNumber / 10;
    }
    return false;
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
    //. ********** Game **********/

    node_t *currentPlayer = startNode;
    int counter = 0;
    int ns_player = n_player;
    while (1){

        if (currentPlayer->data.isOut == false){
            counter++;
            currentPlayer->data.count = counter;           //. Increase the count of the current player
        }

        if(check_number(currentPlayer->data.count, k) && currentPlayer->data.isOut == false){   //. If the count of the current player is equal to k
            currentPlayer->data.Drink++;                    //. Increase the drink of the current player
        }

        if(currentPlayer->data.Drink == currentPlayer->data.limitDrink + 1 && currentPlayer->data.isOut == false){   //. If the drink of the current player is equal to the limit drink
            currentPlayer->data.isOut = true;                              //. Assign the player is out
            ns_player--;                                                   //. Decrease the number of players
        }
        
        if(ns_player == 1){
            break;
        }
        currentPlayer = currentPlayer->next;    //. Move to the next player
    }

    for(int i = 0; i < n_player; i++){
        if(currentPlayer->data.isOut == false){
            printf("%d\n", currentPlayer->data.myNumber);
            break;
        }
        currentPlayer = currentPlayer->next;
    }
    return 0;  


}