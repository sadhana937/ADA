#include <stdio.h>
#include <stdlib.h>
int count=0;
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionsort(int a[],int n){
    int min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            count++;
            if(a[min]>a[j])
                min=j;
        }
        if(min!=i)  
        swap(a[min],a[i]);
    }
}

void main()
{
    FILE *fptr;
    fptr = fopen("selectiondata.txt", "a");
    for (int n = 10; n <= 100; n += 10)
    {
        int *a = malloc(n * sizeof(int));
        //count remains same for different inputs of same size
        for (int i = 0; i < n; i++)
            a[i] = i + 1;
        selectionsort(a, n);
        fprintf(fptr, "%d\t%d\n", n, count);
        count = 0;
        }
    fclose(fptr);
}