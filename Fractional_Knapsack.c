#include<stdio.h>

void knapSack(int n, float weight[], float profit[], float capacity)
{
    float x[20], total_profit = 0;
    int i, j, u;
    u = capacity;

    for(i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }

    for(i = 0; i < n; i++)
    {
        if(weight[i] > u)
        {
            break;
        }
        else
        {
            x[i] = 1.0;
            total_profit = total_profit + profit[i];
            u = u - weight[i];
        }
    }
    if(i < n)
    {
        x[i] = u / weight[i];
    }
    total_profit = total_profit + (x[i] * profit[i]);

    printf("The propotions in which the items are chosen so as to maximize the profit are \n");
    for(i = 0; i < n; i++)
    {
        printf("%f ", x[i]);
    }

    printf("The maximum profit is : %f\n", total_profit);

}
int main(){
    float weight[20], profit[20], ratio[20], temp, capacity;
    int i, j, items;

    printf("Enter the number of items : ");
    scanf("%d", &items);

    printf("Enter the weight and profit of the items : ");
    for(i = 0; i < items; i++)
    {  
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("Enter the capacity of the knapsack : ");
    scanf("%d", &capacity);


    for (i = 0; i < items; i++)
    {
        ratio[i] = (profit[i] / weight[i]);
    }
    
    for(i = 0; i < items;  i++)
    {
        for(j = i+1; j < items; j++)
        {
            if(ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    knapSack(items, weight, profit, capacity);
    return 0;
}


