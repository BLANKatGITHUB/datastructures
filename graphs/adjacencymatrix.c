#include<stdio.h>
#include<stdlib.h>
#define max 4

void initGraph(int graph[][max]) {
    int i, j;
    for(i = 0; i < max; i++) {
        for(j = 0; j < max; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int graph[][max], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void printGraph(int graph[][max]) {
    int i, j;
    for(i = 0; i < max; i++) {
        for(j = 0; j < max; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[max][max] = {0};
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    printGraph(graph);
    return 0;
}