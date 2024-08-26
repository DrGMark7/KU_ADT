#include <stdio.h>
#include <stdlib.h>
#define MAX_TOWNS 100000

typedef struct Node {
    int town;
    int hasThief;
    struct Node* parent;
    struct Node* nextSibling;
    struct Node* firstChild;
} City;

City* cityMap[MAX_TOWNS];

City* addTown(City* city, int parentTown, int newTown, int hasThief) {
    City* newTownNode = (City*)malloc(sizeof(City));
    newTownNode->town = newTown;
    newTownNode->hasThief = hasThief;
    newTownNode->parent = NULL;
    newTownNode->nextSibling = NULL;
    newTownNode->firstChild = NULL;

    City* parentNode = cityMap[parentTown];
    newTownNode->parent = parentNode;
    newTownNode->nextSibling = parentNode->firstChild;
    parentNode->firstChild = newTownNode;
    cityMap[newTown] = newTownNode;

    return city;
}

int solve(City* town, int remainingMoney) {
    if (town == NULL) {
        return 0;
    }

    int maxTowns = (town->town != 0) ? 1 : 0;
    City* child = town->firstChild;

    while (child != NULL) {
        if (child->hasThief == 1 && remainingMoney > 0) {
            maxTowns += solve(child, remainingMoney - 1);
        } else if (child->hasThief == 0) {
            maxTowns += solve(child, remainingMoney);
        }
        child = child->nextSibling;
    }
    return maxTowns;
}

void depthFirstSearch(City* city) {
    if (city == NULL) {
        return;
    }
    printf("City: %d\n", city->town);
    depthFirstSearch(city->firstChild);
    depthFirstSearch(city->nextSibling);
}

int main() {
    int numberOfTowns, parentTown, newTown, hasThief, money;
    City* rootCity = (City*)malloc(sizeof(City));
    *rootCity = (City){0, 0, NULL, NULL, NULL};
    cityMap[0] = rootCity;

    scanf("%d %d", &numberOfTowns, &money);

    for (int i = 0; i < numberOfTowns; i++) {
        scanf("%d %d %d", &parentTown, &newTown, &hasThief);
        rootCity = addTown(rootCity, parentTown, newTown, hasThief);
    }

    // Uncomment the following line to see the DFS traversal
    // depthFirstSearch(rootCity);

    printf("%d\n", solve(rootCity, money));
    return 0;
}
