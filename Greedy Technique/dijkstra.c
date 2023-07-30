#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int c[20][20], d[20], sel[20] = {0}, heapsize, src, count = 0;
int i, j, n;

typedef struct vertex
{
    int id;
    int dist;
} v;

v heap[20];

void swap(v *a, v *b)
{
    v temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(v a[], int n, int i)
{
    int root = i;
    int l = 2 * i;
    int r = 2 * i + 1;
    if (l < n && a[l].dist < a[root].dist)
        root = l;
    if (r <= n && a[r].dist < a[root].dist)
        root = r;
    if (root != i)
    {
        swap(&a[i], &a[root]);
        heapify(a, n, root);
    }
}

void heapsort(v a[], int n)
{
    for (int i = n / 2; i >= 1; i--)
        heapify(a, n, i);
}

v heap_delete(v a[])
{
    v min = a[1];
    a[1] = a[heapsize];
    heapsize -= 1;
    heapify(a, heapsize, 1);
    return min;
}

void dijkstra()
{
    for (i = 0; i < n; i++)
    {
        heap[i].id = i;
        heap[i].dist = INT_MAX;
    }
    heap[src].dist = 0;
    heapsize = n;
    heapsort(heap, heapsize);
    while (count < n)
    {
        v selected = heap_delete(heap);
        count += 1;
        int p = selected.id;
        sel[p] = 1;
        for (i = 0; i < n; i++)
        {
            if (!sel[i] && c[p][i])
            {
                if (d[i] > (d[p] + c[p][i]))
                {
                    d[i] = d[p] + c[p][i];
                    for (j = 1; j <= heapsize; j++)
                    {
                        if (heap[j].id == i)
                        {
                            heap[j].dist = d[i];
                            break;
                        }
                    }
                    heapsort(heap, heapsize);
                }
            }
        }
    }
}

void main()
{
    printf("enter the total number of vertices\n");
    scanf("%d", &n);
    printf("enter the cost matrix of the graph\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &c[i][j]);
            if (c[i][j] < 0)
            {
                printf("The weight of the edge entered is negative. Algorithm cannot be applied\n");
                exit(1);
            }
        }

    printf("enter the source vertex\n");
    scanf("%d", &src);
    for (i = 0; i < n; i++)
        d[i] = INT_MAX;
    d[src] = 0;

    dijkstra();
    printf("Source vertex: %d\nShortest path:\n", src);
    for (i = 0; i < n; i++)
    {
        if (src != i)
            printf("%d -> %d = %d\n", src, i, d[i]);
    }
}
