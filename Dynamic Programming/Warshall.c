#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int a[20][20], count = 0;

int warshall(int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                count++;
                a[i][j] = (a[i][j] || (a[i][k] && a[k][j]));
            }
            
        }
    }
    return count;
}

void main()
{
    FILE *fptr;
    fptr=fopen("warshall.txt","a");
    for(int n=4;n<11;n++){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j]=rand()%2;
    count=warshall(n);
    fprintf(fptr,"%d\t%d\n",n,count);
    count=0;
    printf("the output matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d  ", a[i][j]);
        printf("\n");
    }
    printf("count= %d\n", count);
    

    }
    fclose(fptr);
}
