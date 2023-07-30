#include <stdio.h>
#include <stdlib.h>

int c[20][20], visited[20] = {0}, selected[20] = {0}, heapsize = 0, n, count = 0;

typedef struct vertex
{
    int u, v;
    int dist;
} v;

v heap[20], MST[20];

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
    if (r < n && a[r].dist < a[root].dist)
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

void prim()
{
    heap[1].v = -1, heap[1].u = 0, heap[1].dist = 0;
    heapsize += 1;
    visited[0] = 1;

    while (count < n)
    {
        v min = heap_delete(heap);
        MST[count] = min;
        int v = min.u;
        selected[v] = 1;
        count++;
        for (int i = 1; i < n; i++)
        {
            if (c[v][i] && !selected[i])
            {
                if (!visited[i])
                {
                    visited[i] = 1;
                    heapsize += 1;
                    heap[heapsize].v = v;
                    heap[heapsize].u = i;
                    heap[heapsize].dist = c[v][i];
                }
                for (int j = 1; j <= heapsize; j++)
                {
                    if (heap[j].u == i && c[v][i] < heap[j].dist)
                    {
                        heap[j].dist = c[v][i];
                        heap[j].v = v;
                        break;
                    }
                }
            }
        }
        heapsort(heap, heapsize);
    }
}

void main()
{
    printf("Enter the total number of vertices:");
    scanf("%d", &n);
    printf("Enter the cost matrix of the Graph\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &c[i][j]);
    prim();
    int sum = 0;
    for (int i = 1; i < count; i++)
    {
        printf("%c -> %c = %d\n", MST[i].v + 65, MST[i].u + 65, MST[i].dist);
        sum += MST[i].dist;
    }
    printf("Minimum Distance is: %d", sum);
}