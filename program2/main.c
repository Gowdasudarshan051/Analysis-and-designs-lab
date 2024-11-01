#include <stdio.h>

void prims(int n, int a[10][10], int source)
{
    int s[10], i, j, min, sum=0, u, v, k;

    for(i=0; i<n; i++){
        s[i] = 0; // Initialize all vertices as not included in MST
    }

    s[source] = 1; // Include the source vertex in MST

    for(k=0; k<n-1; k++){
        min = 999; // Initialize min to a large number

        for(i=0; i<n; i++){
            if(s[i] == 1){ // If vertex i is included in MST
                for(j=0; j<n; j++){
                    if(s[j] == 0 && a[i][j] < min){ // If vertex j is not in MST and edge (i, j) is the smallest
                        min = a[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if(min == 999) break; // If no edge found, MST is not possible

        s[v] = 1; // Include vertex v in MST
        sum += min; // Add the weight of the edge to the total cost
        printf("\n(%d, %d) = %d", u+1, v+1, min); // Print the selected edge
    }

    printf("\nCost of minimum spanning tree is %d\n", sum);
}

int main()
{
    int a[10][10], n, i, j, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Cost Matrix:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nSource Vertex: ");
    scanf("%d", &source);

    prims(n, a, source);

    return 0;
}
