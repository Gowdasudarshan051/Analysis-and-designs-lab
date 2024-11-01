#include <stdio.h>

void warshal(int path[10][10], int n)
{
    int i,j, k;
    for(k=0; k<n; k++){
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                path[i][j] = path[i][j] || path[i][k] && path[k][j];
             }
        }
    }
    printf("\n The transitive closure is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d\t",path[i][j]);
        printf("\n");
    }

}

int main()
{
    int a[10][10], i, j, n;
    printf("=======================================\n");
    printf(" Compute transitive closure using Warshalls Algorithm \n");
    printf("=======================================\n");
    I:printf("\n Enter the number of vertices of the graph:\n");
    scanf("%d",&n);
    if(n>0 && n <90)
    {
        printf("\n Enter the adjacency matrix:\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        warshal(a,n);
    }
    else
    {
        printf("Enter the valid number of vertices\n");
        goto I;
    }
}

