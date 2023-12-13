#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include<malloc.h>

#define MAX_VERTICES 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node* adjList[MAX_VERTICES];
    bool visited[MAX_VERTICES];
};

// Create a new node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Depth First Search
void DFS(struct Graph* graph, int vertex) {
    struct Node* adjList = graph->adjList[vertex];
    struct Node* temp = adjList;

    graph->visited[vertex] = true;
    printf("%d ", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (!graph->visited[connectedVertex]) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// Main function
int main() {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = 6;

    for (int i = 0; i < graph->numVertices; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = false;
    }

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);

    printf("Depth First Traversal: ");
    DFS(graph, 0);

    return 0;
}

