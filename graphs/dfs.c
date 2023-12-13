
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void dfs(int adj[][MAX], int visited[], int start)
{
    int stack[MAX];
    int top = -1;
    int i;

    printf("%c ", start + 65);
    visited[start] = 1;
    stack[++top] = start;

    while (top != -1)
    {
        start = stack[top];
        for (i = 0; i < MAX; i++)
        {
            if (adj[start][i] && visited[i] == 0)
            {
                stack[++top] = i;
                printf("%c ", i + 65);
                visited[i] = 1;
                break;
            }
        }
        if (i == MAX)
            top--;
    }
}

int main()
{
    int adj[MAX][MAX];
    int visited[MAX] = {0};
    int i, j;

    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++){
            printf("Enter the value of adj[%d][%d]: ", i, j);
            scanf("%d", &adj[i][j]);}

    printf("\nDFS Traversal: ");
    dfs(adj, visited, 0);
    printf("\n");

    return 0;
}