#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int a[20][20], opt[20], count = 0, c = 0;

typedef struct table
{
    int item, value, weight;
} T;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(T *t, int i, int j)
{
    count++;
    if (i == 0 || j == 0)
        return 0;
    if (a[i][j] < 0)
    {
        count++;
        if (j < t[i].weight)
        {
            a[i][j] = knapsack(t, (i - 1), j);
        }
        else
        {
            a[i][j] = max(knapsack(t, (i - 1), j), (t[i].value + knapsack(t, (i - 1), (j - t[i].weight))));
        }
    }
    return a[i][j];
}

void composition(T *t, int w, int n)
{
    int rc = w;
    for (int i = n; i >= 0; i--)
    {
        if (a[i][rc] != a[i - 1][rc])
        {
            opt[c++] = i;
            rc = rc - t[i].weight;
        }
        if (rc == 0)
            break;
    }
}

void main()
{
    int n = 4, w = 5;
    srand(time(NULL));
    T *t = (T *)malloc(sizeof(T) * (n + 1));
    for (int i = 1; i <= n; i++)
    {
        t[i].item = i;
        t[i].value = rand() % 100;
        t[i].weight = (rand() % 5) + 1;
        printf("%d ", t[i].item);
        printf("%d ", t[i].weight);
        printf("%d\n ", t[i].value);

        // scanf("%d%d",&t[i].value,&t[i].weight);
    }
    // assigning -1
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                a[i][j] = 0;
            else
                a[i][j] = -1;
        }
    }
    int x = knapsack(t, n, w);
    composition(t, w, n);
    printf("optimal value= %d\n", x);
    printf("count= %d\n", count);
    printf("The optimal set:");
    for (int i = 0; i < c; i++)
        printf(" %d ", opt[i]);
    printf("\n");
}