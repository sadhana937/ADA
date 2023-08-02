#include <stdio.h>
#include <stdlib.h>

int a[20][20], indeg[20], visited[20], queue[20];
int f = 0, r = -1, n, count = 0;

void indegree()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (a[j][i])
                indeg[i]++;
        if (!indeg[i])
        {
            count++;
            queue[++r] = i;
            visited[i] = 1;
        }
    }
}

void sourceremoval()
{
    int c = 0;
    while (count != 0)
    {
        int src = queue[f++];
        count--;
        c++;
        for (int i = 0; i < n; i++)
        {
            if (a[src][i] == 1)
                indeg[i]--;
            if (indeg[i] == 0 && visited[i] == 0)
            {
                count++;
                visited[i] = 1;
                queue[++r] = i;
            }
        }
    }
    if (c != n)
        printf("cycle exists\n");
    else
    {
        printf("topological sorting:\n");
        for (int i = 0; i < n; i++)
            printf("%c  ", queue[i] + 65);
    }
}

void main()
{
    printf("enter the number of vertices\n");
    scanf("%d", &n);
    printf("enter the adjacency matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
        indeg[i] = 0;
        visited[i] = 0;
    }
    indegree();
    sourceremoval();
}