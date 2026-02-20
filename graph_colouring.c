#include <stdio.h>
#define MAX 20

int graph[MAX][MAX], color[MAX];
int n, m;

int isSafe(int k, int c) {
    for(int i = 0; i < n; i++) {
        if(graph[k][i] && color[i] == c)
            return 0;
    }
    return 1;
}

int graphColoring(int k) {
    if(k == n)
        return 1;

    for(int c = 1; c <= m; c++) {
        if(isSafe(k, c)) {
            color[k] = c;
            if(graphColoring(k + 1))
                return 1;
            color[k] = 0;
        }
    }
    return 0;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter number of colors: ");
    scanf("%d", &m);

    if(graphColoring(0)) {
        printf("Solution Exists:\n");
        for(int i = 0; i < n; i++)
            printf("Vertex %d -> Color %d\n", i, color[i]);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
