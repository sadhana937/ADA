#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int count=0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[],int l,int r){
    int p=a[l],i=l+1,j=r;
    while(i<=j){
        count++;
        while(i<=r && p> a[i]){
            i++; count++;
        }
        count++;
        while(j>=i && p<a[j]){
            j--; count++;
        }
        if(i<=j){
            swap(&a[j],&a[l]);
            i++; j--;
        }
    }
    swap(&a[j],&a[l]);
    return j;
}

void quicksort(int a[],int l,int r){
    int split=0;
    if(l<r){
        split=partition(a,l,r);
        quicksort(a,l,split-1);
        quicksort(a,split+1,r);
    }
}

void main()
{
    FILE *fptr;
    int n=0;
    float p=2;
    fptr = fopen("quicksortdata.txt", "a");
    while(p<11)
    {   
        n=pow(2.0,p++);
        int *a = malloc(n * sizeof(int));
        // best case
        count=0;
        for(int i=0;i<n;i++)
            a[i]=n;
        quicksort(a,0,n-1);
        fprintf(fptr, "%d\t%d\t", n, count);
        count = 0;
        // worst case
        for (int i = 0; i < n; i++)
            a[i] = i + 1;
        quicksort(a,0, n-1);
        fprintf(fptr, "%d\n", count);
    }
    fclose(fptr);
}