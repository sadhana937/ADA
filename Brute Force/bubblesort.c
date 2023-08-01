#include <stdio.h>
#include <stdlib.h>
int count = 0;

void bubblesort(int a[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            count++;
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
}

void main()
{
    FILE *fptr;
    fptr = fopen("bubbledata.txt", "a");
    for (int n = 10; n <= 100; n += 10)
    {
        int *a = malloc(n * sizeof(int));
        // count remains same for different inputs of same size
        for (int i = 0; i < n; i++)
            a[i] = i + 1;
        bubblesort(a, n);
        fprintf(fptr, "%d\t%d\t", n, count);
        count = 0;
    }
    fclose(fptr);
}