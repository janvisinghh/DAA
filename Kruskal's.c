#include <stdio.h>

#define MAX 100

struct Edge {
    int u;
    int v;
    int weight;
};

int parent[MAX];

int find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void unionSets(int a, int b) {
    a = find(a);
    b = find(b);

    parent[b] = a;
}

void sortEdges(struct Edge edges[], int E) {
    int i, j;
    struct Edge temp;

    for (i = 0; i < E - 1; i++) {
        for (j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Edge edges[MAX];
    int V, E;
    int i, count = 0;
    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v weight):\n");

    for (i = 0; i < E; i++) {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].weight);
    }

    for (i = 0; i < V; i++)
        parent[i] = i;

    sortEdges(edges, E);

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (i = 0; i < E && count < V - 1; i++) {

        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {

            printf("%d -- %d = %d\n",
                   u, v, edges[i].weight);

            totalCost += edges[i].weight;

            unionSets(u, v);

            count++;
        }
    }

    printf("Minimum cost = %d\n", totalCost);

    return 0;
}
