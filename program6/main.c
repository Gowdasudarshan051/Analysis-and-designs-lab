#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int w[], int v[], int n, int c, int a[10][10], int t[10]) {
    // Initialize the matrix and set the first row and column to 0
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            if (i == 0 || j == 0)
                a[i][j] = 0;
            else if (w[i] <= j)
                a[i][j] = max(a[i-1][j], v[i] + a[i-1][j-w[i]]);
            else
                a[i][j] = a[i-1][j];
        }
    }

    // Determine which items to include in the knapsack
    for (int i = 0; i <= n; i++) {
        t[i] = 0;
    }

    int j = c;
    for (int i = n; i > 0 && j > 0; i--) {
        if (a[i][j] != a[i-1][j]) {
            t[i] = 1;
            j -= w[i];
        }
    }
}

void read_input(int *c, int *n, int w[], int v[]) {
    printf("Enter the capacity of the bag: ");
    scanf("%d", c);
    printf("Enter the number of items: ");
    scanf("%d", n);
    printf("Enter the corresponding weights: ");
    for (int i = 1; i <= *n; i++) {
        scanf("%d", &w[i]);
    }
    printf("Enter the corresponding values: ");
    for (int i = 1; i <= *n; i++) {
        scanf("%d", &v[i]);
    }
}

int main() {
    int w[10], v[10], a[10][10], t[10], c, n;
    char choice;

    do {
        read_input(&c, &n, w, v);
        knapsack(w, v, n, c, a, t);

        // Print the resultant matrix
        printf("\nResultant matrix:\n");
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= c; j++) {
                printf("%d\t", a[i][j]);
            }
            printf("\n");
        }

        // Print the optimal solution and selected items
        printf("\nOptimal solution: %d\n", a[n][c]);
        printf("Items selected:\n");
        for (int i = 1; i <= n; i++) {
            if (t[i]) {
                printf("%d ", i);
            }
        }
        printf("\n");

        // Ask the user if they want to continue
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);  // Note the space before %c to consume any leftover newline character

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
