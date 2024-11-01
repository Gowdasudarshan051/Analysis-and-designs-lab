#include <stdio.h>
#include <stdlib.h>

int w[10], x[10], d;

void sum_subset(int s, int k, int r) {
    int i;
    static int b = 1;  // Number of subsets found

    x[k] = 1;  // Include the k-th element in the subset

    // If a subset with the required sum is found
    if (s + w[k] == d) {
        printf("\nSubset %d: ", b++);
        for (i = 1; i <= k; i++) {
            if (x[i] == 1) {
                printf("%d ", w[i]);
            }
        }
        printf("\n");
    } else if (s + w[k] + w[k + 1] <= d) {
        // Try including the next element
        sum_subset(s + w[k], k + 1, r - w[k]);
    }

    // Backtrack: Exclude the k-th element and try the next possibilities
    if ((s + r - w[k] >= d) && (s + w[k + 1] <= d)) {
        x[k] = 0;
        sum_subset(s, k + 1, r - w[k]);
    }
}

int main() {
    int n, i, sum = 0;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements in increasing order: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
        sum += w[i];
    }

    printf("Enter the maximum value of the subset sum: ");
    scanf("%d", &d);

    // Check if there's a feasible solution
    if (sum < d || w[1] > d) {
        printf("No subset found.\n");
        exit(0);
    }

    // Call the subset sum function starting with an empty subset
    sum_subset(0, 1, sum);

    return 0;
}
