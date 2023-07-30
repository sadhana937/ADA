#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INF 999
int a[20][20], count = 0;

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int floyd(int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                count++;
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    return count;
}

void main()
{
    FILE *fptr;
    fptr = fopen("floyd.txt", "a");
    for (int n = 4; n < 11; n++)
    {
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(i==j) a[i][j]=0;
                else if(i%j==0) a[i][j]=INF;
                else a[i][j] = rand() % 10;
            }
        }
        count = floyd(n);
        fprintf(fptr, "%d\t%d\n", n, count);
        count = 0;
    }
    fclose(fptr);
}