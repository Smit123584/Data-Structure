#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n;

// Depth First Search
void DFS(int vertex)
{
    int i;
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

// Breadth First Search
void BFS(int start)
{
    int queue[MAX];
    int front = 0, rear = 0;
    int i, vertex;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        vertex = queue[front++];
        printf("%d ", vertex);

        for (i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (n < 1 || n > MAX || start < 0 || start >= n)
    {
        printf("Invalid input.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(start);

    printf("\nBFS Traversal: ");
    BFS(start);

    printf("\n");
    return 0;
}
