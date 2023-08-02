#include <stdio.h>
#include <stdlib.h>
int a[10][10], visited[10], n, acyclic = 1, connected = 1, count = 1, path[10], directed = 0;
int queue[10], f = 0, r = -1;

void dfs(int v, int p)
{
    path[v] = 1;
    visited[v] = ++count;
    printf(" ->%d ", v);
    for (int i = 0; i < n; i++)
    {
        // check whether the matrix is symmetric or not (directed->0 if symmetric)
        if (directed && a[v][i] && visited[i] && path[i] && i != p)
            acyclic = 0;
        if (!directed && a[v][i] && visited[i] && i != p)
            acyclic = 0;
        if (a[v][i] && !visited[i])
            dfs(i, v);
    }
    path[v] = 0;
}

void DFS(int start)
{
    visited[start] = count;
    printf("->%d ", start);
    for (int i = 0; i < n; i++)
        if (a[start][i] && !visited[i])
            dfs(i, start);
    if (count < n)
    {
        connected++;
        printf("The graph is disconnected.\n");
        int i = 0;
        while (visited[i] && i < n)
            i++;
        count++;
        DFS(i);
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
    DFS(start);
    cycandcon();
}