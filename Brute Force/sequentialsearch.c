#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count = 0;

void search(int a[], int n, int val)
{
    for (int i = 0; i < n; i++)
    {
        count++;
        if (a[i] == val)
            break;
    }
}

void main()
{
    int n;
    FILE *fptr;
    srand(time(NULL));
    fptr = fopen("lineardata.txt", "a");
    for (n = 10; n < 101; n += 10)
    {
        int *a = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            *(a + i) = rand() % 40000;
        // best case
        search(a, n, *(a));
        fprintf(fptr, "%d\t%d\t", n, count);
        count = 0;
        // average case
        search(a, n, *(a + (n / 2)));
        fprintf(fptr, "%d\t", count);
        count = 0;
        // worst case
        search(a, n, *(a + n));
        fprintf(fptr, "%d\t", count);
        count = 0;
    }
    fclose(fptr);
}
