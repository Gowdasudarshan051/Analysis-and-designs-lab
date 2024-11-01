#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int a[], int n)
{
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        if(min != i){
            swap(&a[i], &a[min]);
        }
    }
}

int main()
{
    int n;
    double startTime, endTime;
    FILE *fp = fopen("Selection.csv", "w");
    if(!fp){
        printf("Error\n");
        return 1;
    }
    else{
        fprintf(fp, "n,Timetaken\n");
    }

    for(n=5000; n<=50000; n+=5000){
        int *a = (int *)malloc(n * sizeof(int));
        if(!a){
            printf("\error");
            exit(1);
        }
        srand(time(0));
        for(int i=0; i<n; i++){
            a[i] = rand() % 10000;
        }

        startTime = (double)clock() / CLOCKS_PER_SEC;
        selection_sort(a, n);
        endTime = (double)clock() / CLOCKS_PER_SEC;

        printf("n = %d, Timetaken = %10.9f\n", n, (endTime-startTime));
        fprintf(fp, "%d,%10.9f\n", n, (endTime-startTime));

        free(a);
    }
    fclose(fp);

    return 0;
}
