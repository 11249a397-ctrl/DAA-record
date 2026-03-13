#include <stdio.h>
#define MAX 10
#define INF 999

int main() {
    int cost[MAX][MAX], distance[MAX], visited[MAX];
    int n, i, j, count, min, nextnode, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter the source node: ");
    scanf("%d", &source);

    for(i = 0; i < n; i++) {
        distance[i] = cost[source][i];
        visited[i] = 0;
    }

    distance[source] = 0;
    visited[source] = 1;
    count = 1;

    while(count < n-1) {
        min = INF;

        for(i = 0; i < n; i++) {
            if(distance[i] < min && !visited[i]) {
                min = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;

        for(i = 0; i < n; i++) {
            if(!visited[i]) {
                if(min + cost[nextnode][i] < distance[i]) {
                    distance[i] = min + cost[nextnode][i];
                }
            }
        }
        count++;
    }

    printf("Shortest distances from source node:\n");
    for(i = 0; i < n; i++)
        printf("Distance to node %d = %d\n", i, distance[i]);

    return 0;
}