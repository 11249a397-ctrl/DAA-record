#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

int parent[100];

int find(int i) {
    while(parent[i])
        i = parent[i];
    return i;
}

int unionSet(int i, int j) {
    if(i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int compare(const void *a, const void *b) {
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

int main() {
    int n, e, i, j, cost = 0;
    struct Edge edge[100];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    printf("Enter edges (u v weight):\n");
    for(i = 0; i < e; i++) {
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
    }

    qsort(edge, e, sizeof(edge[0]), compare);

    for(i = 0; i < e; i++) {
        int u = find(edge[i].u);
        int v = find(edge[i].v);

        if(unionSet(u, v)) {
            printf("Edge %d:(%d - %d) cost:%d\n", i, edge[i].u, edge[i].v, edge[i].w);
            cost += edge[i].w;
        }
    }

    printf("Minimum cost = %d\n", cost);
    return 0;
}