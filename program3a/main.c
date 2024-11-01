#include <stdio.h>
#include <time.h>

int min(int a, int b) {
    return a < b ? a : b;
}

void floyd(int w[10][10], int n) {
    int i, j, k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
            }
        }
    }
}

int main() {
    int a[10][10], n, i, j;
    clock_t startTime, endTime;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix, 0-self loop and 999-no edge:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    startTime = clock();
    floyd(a, n);
    endTime = clock();

    printf("\nShortest path matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    double timeTaken = ((double) (endTime - startTime)) / CLOCKS_PER_SEC;
    printf("Time taken is %10.9f seconds\n", timeTaken);

    return 0;
}
