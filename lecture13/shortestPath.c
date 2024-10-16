#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the maximum number of nodes
#define MAX_NODES 100000

// Structure for adjacency list nodes
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Structure for the graph
typedef struct {
    Node* head[MAX_NODES];  // Adjacency list
} Graph;

// Structure for the Min-Heap (Priority Queue)
typedef struct {
    int vertex;
    int distance;
} MinHeapNode;

typedef struct {
    MinHeapNode* heap[MAX_NODES];
    int size;
} MinHeap;

// Function to create a new graph node
Node* newNode(int vertex, int weight) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->vertex = vertex;
    temp->weight = weight;
    temp->next = NULL;
    return temp;
}

// Function to initialize the graph
Graph* createGraph(int nodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    for (int i = 0; i < nodes; i++) {
        graph->head[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph (undirected)
void addEdge(Graph* graph, int u, int v, int w) {
    Node* temp = newNode(v, w);
    temp->next = graph->head[u];
    graph->head[u] = temp;

    // Since the graph is undirected, add the reverse edge as well
    temp = newNode(u, w);
    temp->next = graph->head[v];
    graph->head[v] = temp;
}

// Function to create a new Min-Heap node
MinHeapNode* newMinHeapNode(int vertex, int distance) {
    MinHeapNode* minHeapNode = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    minHeapNode->vertex = vertex;
    minHeapNode->distance = distance;
    return minHeapNode;
}

// Function to initialize the Min-Heap
MinHeap* createMinHeap() {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    return minHeap;
}

// Function to swap two nodes of Min-Heap
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify the Min-Heap
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->heap[left]->distance < minHeap->heap[smallest]->distance) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->heap[right]->distance < minHeap->heap[smallest]->distance) {
        smallest = right;
    }

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->heap[smallest], &minHeap->heap[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to extract the node with the minimum distance from the Min-Heap
MinHeapNode* extractMin(MinHeap* minHeap) {
    if (minHeap->size == 0) return NULL;

    MinHeapNode* root = minHeap->heap[0];
    minHeap->heap[0] = minHeap->heap[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);

    return root;
}

// Function to decrease the distance value of a given vertex in the Min-Heap
void decreaseKey(MinHeap* minHeap, int vertex, int distance) {
    int i;
    for (i = 0; i < minHeap->size; i++) {
        if (minHeap->heap[i]->vertex == vertex) {
            minHeap->heap[i]->distance = distance;
            break;
        }
    }

    while (i && minHeap->heap[i]->distance < minHeap->heap[(i - 1) / 2]->distance) {
        swapMinHeapNode(&minHeap->heap[i], &minHeap->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to check if a vertex is in the Min-Heap
int isInMinHeap(MinHeap* minHeap, int vertex) {
    for (int i = 0; i < minHeap->size; i++) {
        if (minHeap->heap[i]->vertex == vertex) {
            return 1;
        }
    }
    return 0;
}

// Function to implement Dijkstra's Algorithm
void dijkstra(Graph* graph, int src, int nodes, int* dist) {
    // Initialize the distance array
    for (int i = 0; i < nodes; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Create a Min-Heap and add the source node
    MinHeap* minHeap = createMinHeap();
    minHeap->heap[minHeap->size++] = newMinHeapNode(src, 0);

    // Process the Min-Heap
    while (minHeap->size) {
        MinHeapNode* minNode = extractMin(minHeap);
        int u = minNode->vertex;

        // Traverse through all adjacent vertices
        Node* temp = graph->head[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                if (!isInMinHeap(minHeap, v)) {
                    minHeap->heap[minHeap->size++] = newMinHeapNode(v, dist[v]);
                } else {
                    decreaseKey(minHeap, v, dist[v]);
                }
            }
            temp = temp->next;
        }
    }

    // Free the memory used by the Min-Heap
    free(minHeap);
}

int main() {
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);

    // Create the graph
    Graph* graph = createGraph(n);

    // Read edges and build the graph
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u, v, w);
    }

    // Process each query
    for (int i = 0; i < p; i++) {
        int s, t;
        scanf("%d %d", &s, &t);

        // Array to store shortest distances
        int dist[n];
        dijkstra(graph, s, n, dist);

        if (dist[t] == INT_MAX) {
            printf("-1\n");  // No path found
        } else {
            printf("%d\n", dist[t]);  // Print the shortest distance
        }
    }

    // Free graph memory (not implemented here for simplicity)
    return 0;
}
