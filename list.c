#include <stdio.h>
#include <stdlib.h>
#define V 5

struct Node {
    int vertex;
    struct Node *next;
};

struct Node *adj[V];   // each vertex has its own list

void addEdge(int u, int v) {
    // add v to u's list
    struct Node *new1 = (struct Node*)malloc(sizeof(struct Node));
    new1->vertex = v;
    new1->next = adj[u];
    adj[u] = new1;

    // undirected → also add u to v's list
    struct Node *new2 = (struct Node*)malloc(sizeof(struct Node));
    new2->vertex = u;
    new2->next = adj[v];
    adj[v] = new2;
}

void display() {
    int i;
    struct Node *temp;

    printf("\nAdjacency List:\n\n");
    for(i = 0; i < V; i++) {
        printf("%d : ", i);
        temp = adj[i];
        while(temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int i, edges, u, v;

    // start with empty lists
    for(i = 0; i < V; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v)  [vertices 0 to 4]:\n");
    for(i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    display();
    return 0;
}