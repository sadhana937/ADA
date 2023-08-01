#include <stdio.h>
#include <stdlib.h>
int count = 0;
void insertionsort(int a[], int n)
{
    int temp, j;
    for (int i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        count++;
        while (j >= 0 && temp < a[j])
        {
            count++;
            a[j + 1] = a[j];
            j--;
        }
        if (j < 0)
            count--;
        a[++j] = temp;
    }
}

void main()
{
    FILE *fptr;
    fptr = fopen("insertiondata.txt", "a");
    for (int n = 10; n <= 100; n += 10)
    {
        int *a = malloc(n * sizeof(int));
        // best case
        for (int i = 0; i < n; i++)
            a[i] = i + 1;
        insertionsort(a, n);
        fprintf(fptr, "%d\t%d\t", n, count);
        count = 0;
        // worst case
        for (int i = 0; i < n; i++)
            a[i] = n - i + 1;
        insertionsort(a, n);
        fprintf(fptr,"%d\n", count);
        count = 0;
    }
    fclose(fptr);
}
