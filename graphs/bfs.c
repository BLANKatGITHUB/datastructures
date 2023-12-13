#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Function to perform breadth-first search
void BFS(int graph[MAX_SIZE][MAX_SIZE], int vertices, int startVertex) {
    bool visited[MAX_SIZE] = {false}; // Array to keep track of visited vertices
    int queue[MAX_SIZE]; // Queue for BFS traversal
    int front = 0, rear = 0; // Pointers for front and rear of the queue

    // Mark the start vertex as visited and enqueue it
    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("BFS traversal: ");
    

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Explore all adjacent vertices of the current vertex
        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int vertices, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_SIZE][MAX_SIZE];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    BFS(graph, vertices, startVertex);

    return 0;
}
