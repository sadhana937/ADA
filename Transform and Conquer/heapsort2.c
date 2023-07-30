// heapsort using recursion

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int a[20], count = 0, n;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[], int n, int i)
{
    count++;
    int root = i;
    int l = 2 * i;
    int r = 2 * i + 1;
    if (l < n && a[l] > a[root])
        root = l;
    if (r < n && a[r] > a[root])
        root = r;
    if (root != i)
    {
        swap(&a[i], &a[root]);
        heapify(a, n, root);
    }
}

void heapsort(int a[], int n)
{
    for (int i = n / 2; i >= 1; i--)
        heapify(a, n, i);
    for (int i = n; i >= 1; i--)
    {
        swap(&a[i], &a[1]);
        heapify(a, i, 1);
    }
}

void main()
{
    srand(time(NULL));
    n = 10;
    for (int i = 1; i <= n; i++)
        a[i] = rand() % 100;
    printf("elements of the array:\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
    heapsort(a, n);
    printf("count for sorting= %d\n", count);
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
