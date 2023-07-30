//heapsort using iteration

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int a[100], count = 0;

void heapify(int *a, int n)
{
    int pi, pv, heap, ci;
    for (int i = n / 2; i >= 1; i--)
    {
        pi = i;
        pv = a[i];
        heap = 0;

        while (!heap && 2 * pi <= n)
        {
            ci = 2 * pi;
            if (ci < n)
            {
                count++;
                if (a[ci + 1] > a[ci])
                    ci++;
            }
            count++;
            if (pv > a[ci])
                heap = 1;
            else
            {
                a[pi] = a[ci];
                pi = ci;
            }
        }
        a[pi] = pv;
    }
}

void heapdel(int *a, int n)
{
    int pi, pv, heap, ci, size = n, temp;
    for (int i = 0; i <= size - 1; i++)
    {
        temp = a[1];
        a[1] = a[n];
        a[n] = temp;
        n--;
        pi = 1;
        pv = a[pi];
        heap = 0;

        while (!heap && 2 * pi <= n)
        {
            ci = 2 * pi;
            if (ci < n)
            {
                count++;
                if (a[ci + 1] > a[ci])
                    ci++;
            }
            count++;
            if (pv > a[ci])
                heap = 1;
            else
            {
                a[pi] = a[ci];
                pi = ci;
            }
        }
        a[pi] = pv;
    }
}

void main()
{
    srand(time(NULL));
    int n = 10;
    for (int i = 1; i <= n; i++)
        a[i] =rand()%100;
    heapify(a, n);  
    printf("elements of the array:\n");
    for (int i = 1; i <= n; i++)
            printf("%d ",a[i]);
    printf("\n");
    heapdel(a, n);
    printf("count for sorting= %d\n", count);
    for (int i = 1; i <= n; i++)
            printf("%d ", a[i]);
    printf("\n");
}
