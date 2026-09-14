#include <stdio.h>
#define V 5

int main() {
    int matrix[V][V] = {0};   // 5x5 matrix, start with 0
    int i, j, edges, u, v;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v) between 0 to 4:\n");
    for(i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        matrix[u][v] = 1;     // undirected, so both sides
        matrix[v][u] = 1;
    }

    printf("\nAdjacency Matrix:\n");
    printf("  ");
    for(i = 0; i < V; i++)
        printf("%d ", i);
    printf("\n");

    for(i = 0; i < V; i++) {
        printf("%d ", i);
        for(j = 0; j < V; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    return 0;
}