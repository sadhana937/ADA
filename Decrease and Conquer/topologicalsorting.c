#include<stdio.h>
#include<stdlib.h>

int a[20][20],stack[20],top=-1,count=0,visited[20],path[20];

void dfs(int n,int start){
    visited[start]=1;
    path[start]=1;
    for(int i=0;i<n;i++){
        if(a[start][i] && visited[i] && path[i]){
            printf("Cycle exists! terminating...\n");
            exit(1);
        }
        if(a[start][i] && !visited[i])
            dfs(n,i);
    }
    path[start]=0;
    stack[++top]=start;
}



void main(){
    int n;
    printf("enter the number of vertices\n");
    scanf("%d",&n);
    printf("enter the adjacency matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
        visited[i]=0;
    }
    printf("Topological sorting..\n");
    for(int i=0;i<n;i++){
        if(!visited[i])
            dfs(n,i);
    }
    for(int i=n-1;i>=0;i--)
        printf(" ->%c ",stack[i]+65);
}
