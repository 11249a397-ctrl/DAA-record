#include <stdio.h>

#define N 4

void display(int graph[N][N]) {
    printf("\nAdjacency Matrix:\n");
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[N][N];

    printf("Enter adjacency matrix for network topology:\n");
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    display(graph);

    printf("\nConnections:\n");
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(graph[i][j] == 1) {
                printf("Node %d is connected to Node %d\n", i, j);
            }
        }
    }

    return 0;
}