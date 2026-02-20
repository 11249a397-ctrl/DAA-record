#include <stdio.h>
#include <limits.h>

#define MAX 10

int n;
int cost[MAX][MAX];
int visited[MAX];
int minCost = INT_MAX;

// Function to calculate total cost of current path
void calculateCost(int path[]) {
    int total = 0;
    
    for(int i = 0; i < n - 1; i++) {
        total += cost[path[i]][path[i+1]];
    }
    
    // Add cost to return to starting city
    total += cost[path[n-1]][path[0]];
    
    if(total < minCost) {
        minCost = total;
    }
}

// Generate permutations using recursion
void tsp(int path[], int level) {
    if(level == n) {
        calculateCost(path);
        return;
    }

    for(int i = 1; i < n; i++) {
        if(!visited[i]) {
            visited[i] = 1;
            path[level] = i;
            tsp(path, level + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    int path[MAX];
    
    // Start from city 0
    path[0] = 0;
    visited[0] = 1;

    tsp(path, 1);

    printf("Minimum Travelling Cost: %d\n", minCost);

    return 0;
}