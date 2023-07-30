#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define INF 999
int a[20][20], count = 0;

int min(int a,int b){
    return (a<b)?a:b;
}

void floyd(int n)
{
    int t=0;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            t=a[i][k];
            for (int j = 0; j < n; j++)
            {
                count++;
                if(a[i][j]>t)
                a[i][j] =min(a[i][j],t+a[k][j]);
            }
            
        }
    }
}

void main()
{
    int n;
    srand(time(NULL));
    printf("enter the number of vertices\n");
    scanf("%d", &n);
    //manual input
    // printf("enter the matrix(enter 999 for infinity)\n");
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         scanf("%d", &a[i][j]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                a[i][j] = 0;
            else if (i==j+2)
                a[i][j] =INF;
            else
                a[i][j] = rand() % 2;
        }
    }
    floyd(n);
    printf("the output matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d  ", a[i][j]);
        printf("\n");
    }
    printf("count= %d\n", count);
}