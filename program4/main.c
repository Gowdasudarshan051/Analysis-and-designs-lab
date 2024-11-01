#include <stdio.h>
#define INFINITY 9999
#define MAX 10

void printPath(int pred[], int j) {
    if (pred[j] == -1) {
        printf("%d", j);
        return;
    }
    printPath(pred, pred[j]);
    printf(" -> %d", j);
}

void dijkstra(int Graph[MAX][MAX], int n, int start)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(Graph[i][j] == 0 && i != j) {
                cost[i][j] = INFINITY;
            } else {
                cost[i][j] = Graph[i][j];
            }
        }
    }

    for(i = 0; i < n; i++) {
        distance[i] = cost[start][i];
        pred[i] = -1;  // Initialize with -1 to indicate no predecessor initially
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while(count < n - 1) {
        mindistance = INFINITY;

        for(i = 0; i < n; i++) {
            if(distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;

        for(i = 0; i < n; i++) {
            if(!visited[i]) {
                if(mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }
        count++;
    }

    // Print distances and paths
    for(i = 0; i < n; i++) {
        if(i != start) {
            printf("\nDistance from source to %d: %d", i, distance[i]);
            printf("\nPath: %d -> ", start);
            printPath(pred, i);
            printf("\n");
        }
    }
    for(i=0; i<n; i++){
        printf("%d  ", pred[i]);
    }
}

int main() {
    int  n, u;
    n = 6;

    int Graph[MAX][MAX] = { {0, 1, 3, 99, 99, 2},
                            {1, 0, 5, 1, 99, 99},
                            {3, 5, 0, 2, 1, 99},
                            {99, 1, 2, 0, 4, 99},
                            {99, 99, 1, 4, 0, 5},
                            {2, 99, 99, 99, 5, 0} };

    u = 1; // Start node
    dijkstra(Graph, n, u);

    return 0;
}
