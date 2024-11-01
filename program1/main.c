#include <stdio.h>

int parent[20];

int find(int m)
{
    while(parent[m] != -1){
        m = parent[m];
    }
    return m;
}

void union_ij(int i, int j)
{
    parent[j] = i;
}

void kruskal(int a[10][10], int n)
{
    int u, v, min, k=0, i, j, sum=0;

    for(i=0; i<n; i++){
        parent[i] = -1;
    }

    while(k<n-1){
        min =999;
        u=v=-1;

        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(a[i][j] < min && i!=j){
                    min = a[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        int pu = find(u);
        int pv = find(v);

        if(pu != pv){
            union_ij(pu, pv);
            printf("Edge (%d %d) with cost %d\n", u+1, v+1, a[u][v]);
            sum += a[u][v];
            k++;
            a[u][v] = a[v][u] = 999;
        }
    }
    printf("\nThe minimum cost spanning tree is: %d", sum);
}
int main() {
    int a[10][10], n, i, j;
    printf("=========================================================\n");
    printf("Find minimum cost spanning tree using Kruskal's algorithm\n");
    printf("=========================================================\n");
    printf("\nEnter the number of vertices of the graph: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    kruskal(a, n);
    return 0;
}
