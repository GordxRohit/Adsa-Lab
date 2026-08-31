#include <stdio.h>
#include <stdlib.h>
#define SIZE 10                 // hash table size is 10

struct Node {
    int data;                   // value stored in node
    struct Node *next;          // pointer to next node
};

struct Node *table[SIZE];       // hash table, each index can have a list

// this function finds the index
int hash(int key) {
    return key % SIZE;          // example: 22 % 10 = 2
}

void insert(int key) {
    int index = hash(key);      // find where this value should go

    // create a new node
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = key;
    n->next = NULL;

    // if that index is empty, put the node there
    if(table[index] == NULL) {
        table[index] = n;
    }
    else {
        // index already has a value, so collision happened
        // now we add this new value at the end of the list
        struct Node *t = table[index];
        while(t->next != NULL)
            t = t->next;
        t->next = n;
    }

    printf("Inserted %d at index %d\n", key, index);
}

void display() {
    int i;
    struct Node *t;

    printf("\nHash Table:\n");

    for(i = 0; i < SIZE; i++) {
        printf("%d : ", i);
        t = table[i];

        if(t == NULL)
            printf("empty");    // nothing stored at this index
        else {
            // print all values in this chain
            while(t != NULL) {
                printf("%d -> ", t->data);
                t = t->next;
            }
            printf("NULL");
        }
        printf("\n");
    }
}

int main() {
    int ch, key, i;

    // first make every index empty
    for(i = 0; i < SIZE; i++)
        table[i] = NULL;

    while(1) {
        printf("\n1.Insert 2.Display 3.Exit\nChoice: ");
        scanf("%d", &ch);

        if(ch == 1) {
            printf("Enter value: ");
            scanf("%d", &key);
            insert(key);
        }
        else if(ch == 2)
            display();
        else if(ch == 3)
            break;
        else
            printf("Invalid\n");
    }
    return 0;
}