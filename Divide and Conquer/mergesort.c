#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int count = 0;

void merge(int a[], int beg, int mid, int end)
{
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int l[n1], r[n2];
    for (int i = 0; i < n1; i++)
        l[i] = a[beg + i];
    for (int i = 0; i < n2; i++)
        r[i] = a[mid + i + 1];
    int i = 0, j = 0, k = beg;
    while (i < n1 && j < n2)
    {
        count++;
        if (l[i] <= r[j])
            a[k++] = l[i++];
        else
            a[k++] = r[j++];
    }
    while (i < n1)
        a[k++] = l[i++];
    while (j < n2)
        a[k++] = r[j++];
}

void mergesort(int a[], int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergesort(a, beg, mid);
        mergesort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void worstCaseDataGen(int a[], int n)
{
    int i, j, k = 1, temp;
    for (i = 0, j = n / 2; i < n / 2; i++, j++)
    {
        a[i] = k;
        a[j] = k + 1;
        k += 2;
    }
    for (i = 1, j = n / 2 - 2; i < j; i += 2, j -= 2)
        swap(&a[i], &a[j]);
    for (i = n / 2 + 1, j = n - 2; i < j; i += 2, j -= 2)
        swap(&a[i], &a[j]);
}

void main()
{
    FILE *fptr;
    int n = 0;
    float p = 2;
    fptr = fopen("mergedata.txt", "a");
    while(p<11)
    {
        n = pow(2.0,p++);//arguments need to be of float datatype
        int *a = (int *)malloc(n * sizeof(int));
        // best case
        for (int i = 0; i < n; i++)
            a[i] = i + 1;
        mergesort(a, 0, n - 1);
        fprintf(fptr, "%d\t%d\t", n, count);
        count = 0;
        // worst case
        worstCaseDataGen(a, n);
        mergesort(a, 0, n - 1);
        fprintf(fptr, "%d\n", count);
        count = 0;
    }

    fclose(fptr);
}
