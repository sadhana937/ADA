//heapsort using iteration

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int a[100], count = 0;

void heapify(int *a, int n,int i)
{
    int pi, pv, heap, ci;
        pi = i;
        pv = a[i];
        heap = 0;

        while (!heap && 2 * pi <= n)
        {   
            ci = 2 * pi;
            if (ci < n)
            {   
                count++;
                if (a[ci + 1] > a[ci])
                    ci++;
            }
            count++;
            if (pv > a[ci])
                heap = 1;
            else
            {
                a[pi] = a[ci];
                pi = ci;
            }
        }
        a[pi] = pv;
}

void heapsort(int *a,int n){
    for(int i=n/2;i>=1;i--){
        heapify(a,n,i);
    }
    //deleting the root at each iteration
    int size=n,temp;
    for(int i=0;i<n;i++){
        temp=a[1];
        a[1]=a[size];
        a[size]=temp;
        size--;
        heapify(a,size,1);

    }
}

void main()
{   
    FILE *fp;
    fp=fopen("heapcount.txt","a");
    srand(time(NULL));
    for(int n=10;n<101;n+=10){
        // best case
        for (int i = 1; i <= n; i++)
                a[i] = n-i;
        heapsort(a, n);
        fprintf(fp, "%d\t%d\t", n,count);
        count = 0;

        // worst case
        for (int i = 1; i <= n; i++)
                a[i] = rand()%100;
        heapsort(a, n);
        fprintf(fp, "%d\t", count);
        count = 0;

        //worst case
        for (int i = 1; i <= n; i++)
            a[i] = i;
        heapsort(a, n);
        fprintf(fp,"%d\n",count);
        count=0;
    }
    fclose(fp);
}
