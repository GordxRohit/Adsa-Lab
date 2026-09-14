#include <stdio.h>
#include <stdlib.h>
#define V 5

struct Node {
    int data;
    struct Node *next;
};

struct Node *list[V];   // array of lists

void addEdge(int u, int v) {
    // add v in u's list
    struct Node *n1 = (struct Node*)malloc(sizeof(struct Node));
    n1->data = v;
    n1->next = list[u];
    list[u] = n1;

    // add u in v's list (undirected)
    struct Node *n2 = (struct Node*)malloc(sizeof(struct Node));
    n2->data = u;
    n2->next = list[v];
    list[v] = n2;
}

void display() {
    int i;
    struct Node *t;
    printf("\nAdjacency List:\n");
    for(i = 0; i < V; i++) {
        printf("%d -> ", i);
        t = list[i];
        while(t != NULL) {
            printf("%d ", t->data);
            t = t->next;
        }
        printf("\n");
    }
}

int main() {
    int i, edges, u, v;

    for(i = 0; i < V; i++)
        list[i] = NULL;     // empty lists

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v) between 0 to 4:\n");
    for(i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    display();
    return 0;
}