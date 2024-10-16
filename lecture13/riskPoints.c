#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100000

// Graph structure
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

// Function to add an edge to the graph (undirected)
void addEdge(Graph* graph, int u, int v) {
    Node* temp = newNode(v);
    temp->next = graph->head[u];
    graph->head[u] = temp;

    temp = newNode(u);
    temp->next = graph->head[v];
    graph->head[v] = temp;
}

// Helper function for DFS to find articulation points
void DFS(Graph* graph, int u, bool visited[], int discovery[], int low[], int parent[], bool articulation[], int* time) {
    visited[u] = true;
    discovery[u] = low[u] = ++(*time);
    int children = 0;

    Node* temp = graph->head[u];
    while (temp != NULL) {
        int v = temp->vertex;

        // If v is not visited, explore it
        if (!visited[v]) {
            children++;
            parent[v] = u;
            DFS(graph, v, visited, discovery, low, parent, articulation, time);

            // Check if the subtree rooted at v has a connection back to one of the ancestors of u
            low[u] = (low[u] < low[v]) ? low[u] : low[v];

            // u is an articulation point in two cases:
            // 1. u is the root of the DFS tree and has more than one child
            if (parent[u] == -1 && children > 1) {
                articulation[u] = true;
            }
            // 2. u is not the root and there is no back edge from the subtree rooted at v to an ancestor of u
            if (parent[u] != -1 && low[v] >= discovery[u]) {
                articulation[u] = true;
            }
        }
        // If v is already visited and not the parent of u, then it's a back edge
        else if (v != parent[u]) {
            low[u] = (low[u] < discovery[v]) ? low[u] : discovery[v];
        }

        temp = temp->next;
    }
}

// Function to find all articulation points in the graph
void findArticulationPoints(Graph* graph, int n) {
    bool visited[n];
    int discovery[n], low[n], parent[n];
    bool articulation[n];
    int time = 0;

    // Initialize arrays
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        discovery[i] = -1;
        low[i] = -1;
        parent[i] = -1;
        articulation[i] = false;
    }

    // Call DFS for each unvisited node
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited, discovery, low, parent, articulation, &time);
        }
    }

    // Print all articulation points in sorted order
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (articulation[i]) {
            if (found) {
                printf(" ");
            }
            printf("%d", i);
            found = true;
        }
    }
    if (!found) {
        printf("\n");  // No articulation points found
    }
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

    // Find and print articulation points
    findArticulationPoints(graph, n);

    // Free graph memory (not implemented here for simplicity)
    return 0;
}