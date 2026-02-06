#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int firstFitDecreasing(int items[], int n, int capacity)
{
    int bins[n];
    int binCount = 0;

    for (int i = 0; i < n; i++)
        bins[i] = capacity;

    qsort(items, n, sizeof(int), compare);

    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < binCount; j++)
        {
            if (bins[j] >= items[i])
            {
                bins[j] -= items[i];
                break;
            }
        }

        if (j == binCount)
        {
            bins[binCount] -= items[i];
            binCount++;
        }
    }

    return binCount;
}

int main()
{
    int items[] = {4, 8, 1, 4, 2, 1};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 10;

    int result = firstFitDecreasing(items, n, capacity);
    printf("%d\n", result);

    return 0;
}
