#include <stdio.h>
#include <stdlib.h>
int count = 0;

void search(int a[], int val, int low, int high)
{
    count++;
    if (high >= low)
    {
        int mid = (high + low) / 2;
        if (val == a[mid])
            return;
        else if (val > a[mid])
            search(a, val, mid + 1, high);
        else
            search(a, val, low, mid - 1);
    }
}

void main()
{
    int n;
    FILE *fptr;
    fptr = fopen("binarydata.txt", "a");
    for (n = 10; n < 100000; n *= 10)
    {
        int *a = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            *(a + i) = i + 1;
        // best case
        search(a, *(a + (n / 2)), 0, n);
        fprintf(fptr, "%d\t%d\t", n, count);
        count = 0;
        // worst case
        search(a, *(a), 0, n);
        fprintf(fptr, "%d\n", count);
        count = 0;
    }
    fclose(fptr);
}
