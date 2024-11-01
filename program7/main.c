#include <stdio.h>
#define MAX 50

int profit[MAX], weight[MAX], selected[MAX];
double maxprofit;
int n, capacity;

void greedy(int n, int weight[], int profit[], int capacity)
{
    double ratio[MAX];
    int i, j;

    for(i=0; i<n; i++){
        ratio[i] = (double)profit[i]/ weight[i];
    }

    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(ratio[i] < ratio[j]){
                double temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                int tempWeight = weight[i];
                weight[i] = weight[j];
                weight[j] = tempWeight;

                int tempProfit = profit[i];
                profit[i] = profit[j];
                profit[j] = tempProfit;
            }
        }
    }

    int currentWeight = 0;
    maxprofit = 0.0;

    for(i=0; i<n; i++){
        if(currentWeight+weight[i] <= capacity){
            selected[i] = 1;
            currentWeight += weight[i];
            maxprofit += profit[i];
        }
        else{
            selected[i] = (capacity - currentWeight)/(double)weight[i];
            currentWeight += weight[i];
            maxprofit += profit[i] * selected[i];
            break;
        }
    }
    printf("Maximum Profit %.1f\n", maxprofit);
    printf("Selected vector: ");
    for(int i=0; i<n; i++){
        printf("%d  ", selected[i]);
    }
    printf("\n");
}

int main()
{
    printf("\nEnter the number of items: ");
    scanf("%d", &n);

    printf("\nEnter the weights of each items:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &weight[i]);
    }

    printf("\nEnter the profits of each items:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &profit[i]);
    }

    printf("\nEnter the capacity of knapsack: ");
    scanf("%d", &capacity);

    greedy(n, weight, profit, capacity);

    return 0;
}
