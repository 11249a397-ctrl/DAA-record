#include <stdio.h>

#define MAX 10
#define INF 9999

int n; // Number of cities
int dist[MAX][MAX]; // Distance matrix
int visited[MAX];
int bestCost = INF;
int bestPath[MAX];

// Function to find TSP using simple backtracking
void tsp(int currentCity, int count, int cost, int path[]) {
    if (count == n && dist[currentCity][0] > 0) { // Return to start
        int totalCost = cost + dist[currentCity][0];
        if (totalCost < bestCost) {
            bestCost = totalCost;
            for (int i = 0; i < n; i++)
                bestPath[i] = path[i];
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[currentCity][i] > 0) {
            visited[i] = 1;
            path[count] = i;
            tsp(i, count + 1, cost + dist[currentCity][i], path);
            visited[i] = 0; // Backtrack
        }
    }
}

int main() {
    printf("Enter number of cities (<=10): ");
    scanf("%d", &n);

    printf("Enter distance matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int path[MAX];
    path[0] = 0; // Start from city 0
    visited[0] = 1;

    tsp(0, 1, 0, path);

    printf("\nShortest path: 0 ");
    for (int i = 1; i < n; i++)
        printf("-> %d ", bestPath[i]);
    printf("-> 0\n");

    printf("Minimum cost: %d\n", bestCost);

    return 0;
}
