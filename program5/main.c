#include <stdio.h>

// Global variables
int a[10][10], indegree[10], v[10], stack[10], n, k = 0, top = -1;

// Function prototypes
void readadj();
void topological();

int main() {
    int i;

    printf("=================================================\n");
    printf(" To find the topological ordering of the vertices\n");
    printf("=================================================\n");

    readadj();
    topological();

    if (k == n) {
        printf("\nTopological sequence is:");
        for (i = 0; i < n; i++)
            printf("\t%d", v[i] + 1);  // Adjust for 1-based indexing
    } else {
        printf("\nTopological sequence does not exist");
    }

    return 0;
}

// Function to read the adjacency matrix
void readadj() {
    int i, j;

    while (1) {
        printf("\nEnter the number of vertices of a graph (1-10):\n");
        scanf("%d", &n);
        if (n > 0 && n <= 10) {
            break;
        } else {
            printf("Enter a valid number of vertices.\n");
        }
    }

    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

// Function to perform topological sorting
void topological() {
    int i, j, R;

    // Initialize indegree of each vertex
    for (i = 0; i < n; i++)
        indegree[i] = 0;

    // Calculate indegree of each vertex
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] == 1)
                indegree[j]++;
        }
    }

    // Push all vertices with indegree 0 to the stack
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0)
            stack[++top] = i;
    }

    // Perform topological sort
    while (top != -1) {
        R = stack[top--];
        v[k++] = R;
        for (i = 0; i < n; i++) {
            if (a[R][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0)
                    stack[++top] = i;
            }
        }
    }
}
