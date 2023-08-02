#include <stdio.h>
#include <stdlib.h>
int a[10][10], visited[10], n, acyclic = 1, connected = 1, count = 1, path[10], directed = 0, pqueue[10];
int queue[10], f, r;

void bfs(int n, int start)
{
    f = r = -1;
    count++;
    queue[++r] = start;
    pqueue[r] = -1;
    int v, p;
    while (f != r)
    {
        v = queue[++f];
        path[v] = 1;
        p = pqueue[f];
        printf(" ->%d", v);
        for (int i = 0; i < n; i++)
        {
            // check whether the matrix is symmetric or not (directed->0 if symmetric)
            if (directed && a[v][i] && visited[i] && i != p && path[i])
                acyclic = 0;
            if (!directed && a[v][i] && visited[i] && i != p)
                acyclic = 0;
            if (!visited[i] && a[v][i])
            {
                count++;
                visited[i] = 1;
                queue[++r] = i;
                pqueue[r] = v;
            }
        }
        path[v] = 0;
    }
}

void BFS(int start)
{
    visited[start] = 1;
    bfs(n, start);
    int i = 0;
    if (count < n)
    {
        connected++;
        while (visited[i] && i < n)
            i++;
        BFS(i);
    }
}

void cycandcon()
{
    printf("\n");
    if (acyclic)
        printf("the graph is acyclic\n");
    else
        printf("the graph is cyclic\n");
    if (connected == 1)
        printf("the graph is connected\n");
    else
        printf("the graph is disconnected and there are %d connected components\n", connected);
}

void main()
{
    int start;
    printf("enter the number of vertices\n");
    scanf("%d", &n);
    printf("enter the adjacency matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
        visited[i] = 0;
        path[i] = 0;
    }
    printf("enter the starting vertex\n");
    scanf("%d", &start);
    BFS(start);
    cycandcon();
}