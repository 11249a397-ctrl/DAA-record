#include <stdio.h>

struct Item
{
    int value;
    int weight;
};

float fractionalKnapsack(int capacity, struct Item items[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            float r1 = (float)items[i].value / items[i].weight;
            float r2 = (float)items[j].value / items[j].weight;

            if (r1 < r2)
            {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    float totalValue = 0.0f;

    for (int i = 0; i < n; i++)
    {
        if (capacity >= items[i].weight)
        {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        }
        else
        {
            totalValue += (float)items[i].value * capacity / items[i].weight;
            break;
        }
    }

    return totalValue;
}

int main()
{
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;
    int n = sizeof(items) / sizeof(items[0]);

    float result = fractionalKnapsack(capacity, items, n);
    printf("%.2f\n", result);

    return 0;
}
