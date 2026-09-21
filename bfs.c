#include <stdio.h>
#define V 5

int g[V][V];      // graph matrix
int vis[V];       // visited array
int q[V];         // queue
int f = -1, r = -1;

void bfs(int s) {
    int i;

    // mark all vertices as not visited
    for(i = 0; i < V; i++)
        vis[i] = 0;

    // put starting vertex in queue
    q[++r] = s;
    f = 0;
    vis[s] = 1;

    printf("BFS: ");

    // run till queue becomes empty
    while(f <= r) {
        int n = q[f++];       // take one vertex from front
        printf("%d ", n);

        // check its all neighbours
        for(i = 0; i < V; i++) {
            if(g[n][i] == 1 && vis[i] == 0) {
                q[++r] = i;   // put neighbour in queue
                vis[i] = 1;   // mark as visited
            }
        }
    }
}

int main() {
    int e, u, v, s, i, j;

    // make graph empty
    for(i = 0; i < V; i++)
        for(j = 0; j < V; j++)
            g[i][j] = 0;

    printf("Edges: ");
    scanf("%d", &e);

    printf("Enter edges:\n");
    for(i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);
        g[u][v] = 1;          // undirected edge
        g[v][u] = 1;
    }

    printf("Start: ");
    scanf("%d", &s);

    bfs(s);
    return 0;
}