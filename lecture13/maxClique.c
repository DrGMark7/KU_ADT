#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 100000

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node* head[MAX_NODES];  // Adjacency list
} Graph;

// Function to create a new node in the adjacency list
Node* newNode(int vertex) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->vertex = vertex;
    temp->next = NULL;
    return temp;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int u, int v) {
    Node* temp = newNode(v);
    temp->next = graph->head[u];
    graph->head[u] = temp;

    temp = newNode(u);
    temp->next = graph->head[v];
    graph->head[v] = temp;
}

// Bron-Kerbosch algorithm to find maximum clique
void bronKerbosch(Graph* graph, bool R[], bool P[], bool X[], int n, int* maxCliqueSize, int cliqueSize) {
    bool emptyP = true, emptyX = true;

    // Check if P and X are both empty
    for (int i = 0; i < n; i++) {
        if (P[i]) {
            emptyP = false;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (X[i]) {
            emptyX = false;
            break;
        }
    }

    // If both P and X are empty, we've found a maximal clique
    if (emptyP && emptyX) {
        if (cliqueSize > *maxCliqueSize) {
            *maxCliqueSize = cliqueSize;
        }
        return;
    }

    for (int v = 0; v < n; v++) {
        if (P[v]) {
            bool R_new[MAX_NODES], P_new[MAX_NODES], X_new[MAX_NODES];

            for (int i = 0; i < n; i++) {
                R_new[i] = R[i];
                P_new[i] = false;
                X_new[i] = false;
            }

            R_new[v] = true;

            // Update P_new and X_new
            Node* temp = graph->head[v];
            while (temp != NULL) {
                if (P[temp->vertex]) {
                    P_new[temp->vertex] = true;
                }
                if (X[temp->vertex]) {
                    X_new[temp->vertex] = true;
                }
                temp = temp->next;
            }

            bronKerbosch(graph, R_new, P_new, X_new, n, maxCliqueSize, cliqueSize + 1);

            P[v] = false;
            X[v] = true;
        }
    }
}

// Function to find the maximum clique
int findMaxClique(Graph* graph, int n) {
    bool R[MAX_NODES] = {0};  // Current clique set
    bool P[MAX_NODES];  // Potential members of clique
    bool X[MAX_NODES] = {0};  // Already processed vertices

    for (int i = 0; i < n; i++) {
        P[i] = true;
    }

    int maxCliqueSize = 0;
    bronKerbosch(graph, R, P, X, n, &maxCliqueSize, 0);

    return maxCliqueSize;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Create the graph
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    for (int i = 0; i < n; i++) {
        graph->head[i] = NULL;
    }

    // Read edges and build the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    // Find and print the size of the maximum clique
    int maxCliqueSize = findMaxClique(graph, n);
    printf("%d\n", maxCliqueSize);

    // Free graph memory (not implemented here for simplicity)
    return 0;
}
