#include <stdio.h>
#define N 4
#define INF 9999

int visited[N] = {0};

int main() {
    int cost[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int i, j, count = 1;
    int current = 0, next;
    int totalCost = 0;

    visited[current] = 1;
    printf("Path: %d ", current);

    while (count < N) {
        int min = INF;
        next = -1;

        for (i = 0; i < N; i++) {
            if (!visited[i] && cost[current][i] < min) {
                min = cost[current][i];
                next = i;
            }
        }

        visited[next] = 1;
        printf("-> %d ", next);

        totalCost += min;
        current = next;
        count++;
    }

    totalCost += cost[current][0];
    printf("-> %d", 0);

    printf("\nTotal Cost: %d\n", totalCost);

    return 0;
}