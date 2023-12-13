#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node {
    int vertex;
    struct node *next;
};

struct graph {
    int numVertices;
    struct node **adjLists;
};

struct node *createNode(int v) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct graph *createGraph(int vertices) {
    struct graph *graph = malloc(sizeof(struct graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node *));

    int i;
    for (i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addedge(struct graph *graph, int src, int dest) {
    // Add edge from src to dest
    struct node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct graph *graph) {
    int v;
    for (v = 0; v < graph->numVertices; v++) {
        struct node *temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct graph *graph = createGraph(4);
    addedge(graph, 0, 1);
    addedge(graph, 0, 2);
    addedge(graph, 0, 3);
    addedge(graph, 1, 2);

    printGraph(graph);

    return 0;
}
