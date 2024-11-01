#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    while(start < end){
        while(a[start] <= pivot){
            start++;
        }
        while(a[end] > pivot){
            end--;
        }
        if(start<end){
            swap(&a[start], &a[end]);
        }
    }
    swap(&a[lb], &a[end]);
    return end;
}

void quicksort(int a[], int lb, int ub)
{
    if(lb<ub){
        int loc = partition(a, lb, ub);
        quicksort(a, lb, loc-1);
        quicksort(a, loc+1, ub);
    }
}

int main()
{
    int n;
    double startTime, endTime;
    FILE *fp = fopen("quick.csv", "w");
    if(!fp){
        printf("Error\n");
        return 1;
    }

    fprintf(fp, "n,Timetaken\n");

    for(n=5000; n<=50000; n+=5000){
        int *a = (int *)malloc(n * sizeof(int));
        if(!a){
            printf("Error\n");
            return 1;
        }

        srand(time(0));
        for(int i=0; i<n; i++){
            a[i] = rand() % 10000;
        }

        startTime = (double)clock()/CLOCKS_PER_SEC;
        quicksort(a, 0, n-1);
        endTime = (double)clock()/ CLOCKS_PER_SEC;

        printf("n = %d, Timetaken = %10.9f\n", n, (endTime-startTime));
        fprintf(fp, "%d,%10.9f\n", n, (endTime-startTime));

        free(a);
    }
    fclose(fp);
    return 0 ;

}
