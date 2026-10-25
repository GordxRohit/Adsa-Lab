#include <stdio.h>
#define V 5

int main() {
    int matrix[V][V];
    int i, j, edges, u, v;

    // Part 1: Initialize matrix to 0
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            matrix[i][j] = 0;

    // Part 2: Input edges
    printf("Enter the no of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u, v) [vertices 0 to 4]:\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    // Part 3: Print adjacency matrix
    printf("\nAdjacency Matrix:\n\n");
    printf("  ");
    for (i = 0; i < V; i++)
        printf("\n");
    for (i = 0; i < V; i++) {
        printf("%d ", i);
        for (j = 0; j < V; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    return 0;
}