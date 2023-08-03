#include <stdio.h>
#include <stdlib.h>
int count = 0;
void string(int *t, int *p, int m)
{
    for (int i = 0; i <= 10 - m; i++)
    {
        int j = 0;
        count++;
        while (j < m && p[j] == t[j + i])
        {
            count++;
            j++;
        }
        if (j == m)
            return;
    }
}

void main()
{
    FILE *fptr;
    int *w, *b, *t;
    t = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)
        t[i] = 'a';
    fptr = fopen("bfsmcount.txt", "a");
    for (int i = 2; i < 10; i++)
    {
        w = (int *)malloc(i * sizeof(int));
        b = (int *)malloc(i * sizeof(int));
        for (int j = 0; j < i; j++)
        {
            b[j] = 'a';
            if (j == i - 1)
                w[j] = 'b';
            else
                w[j] = 'a';
        }
        // best case
        string(t, b, i);
        fprintf(fptr, "%d\t%d\t", i, count);
        count = 0;
        // worst case
        string(t, w, i);
        fprintf(fptr, "%d\n", count);
        count = 0;
    }
    fclose(fptr);
}
