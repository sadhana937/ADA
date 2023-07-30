#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[20][20],opt[20],count=0,i=0,j=0;

typedef struct table{
    int item,value,weight;
}T;


int max(int a,int b){
    return (a>b)?a:b;
}

void knapsack(T *t,int w,int n){
    for(i=0;i<=n;i++){
        for(j=0;j<=w;j++){
            //count++;
            if(i==0 || j==0)
                a[i][j]=0;
            else{
                count++;
                if(j<t[i].weight)
                    a[i][j]=a[i-1][j];
                else
                    a[i][j]=max(a[i-1][j],(t[i].value+a[i-1][j-t[i].weight]));
                }

        }
    }
}

void composition(T *t,int w,int n){
    int rc=w;
    j=1;
    for(i=n;i>=0;i--){
        if(a[i][rc]!=a[i-1][rc]){
            opt[j++]=i;
            rc=rc-t[i].weight;
        }
        if(rc==0) break;
    }
}


void main(){
    int n=4,w=5;
    srand(time(NULL));
    T *t=(T*)malloc(sizeof(T)*(n+1));
    for(i=1;i<=n;i++){
        t[i].item=i;
        t[i].value=rand()%100;
        t[i].weight=(rand()%5)+1;
        printf("%d ", t[i].item);
        printf("%d ",t[i].weight);
        printf("%d\n ", t[i].value);

       // scanf("%d%d",&t[i].value,&t[i].weight);
    }
    knapsack(t,w,n);
    composition(t,w,n);
    printf("optimal value= %d\n",a[n][w]);
    printf("count= %d\n",count);
    printf("the optimal set:");
    for(i=1;i<j;i++)
        printf(" %d ",opt[i]);
    printf("\n");


    
}