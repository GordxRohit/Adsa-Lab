#include <stdio.h>
#include <stdlib.h>

int SIZE = 10;     // hash table starts with 10 places
int count = 0;     // how many values are stored now

struct Node {
    int data;
    struct Node *next;
};

struct Node **table;   // the hash table

int hash(int key) {
    return key % SIZE; // find locker number
}

// put one value in the table
void put(int key) {
    int i = hash(key);
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = key;
    n->next = table[i];   // add in front of the chain
    table[i] = n;
}

// when table is half full, make it double
void rehash() {
    int old = SIZE, i;
    struct Node **oldT = table, *t, *n;

    SIZE = SIZE * 2;      // 10 becomes 20
    table = (struct Node**)malloc(SIZE * sizeof(struct Node*));

    for(i = 0; i < SIZE; i++)
        table[i] = NULL;  // new table is empty first

    printf("50%% full, size now %d. Rehashing...\n", SIZE);

    // take old values and insert them again
    for(i = 0; i < old; i++) {
        t = oldT[i];
        while(t != NULL) {
            n = t->next;
            put(t->data);
            free(t);
            t = n;
        }
    }
    free(oldT);
}

void insert(int key) {
    put(key);
    count++;
    printf("Inserted %d at index %d\n", key, hash(key));

    if(count > SIZE / 2)  // more than half filled
        rehash();
}

void display() {
    int i;
    struct Node *t;

    printf("\nSize=%d Count=%d\n", SIZE, count);
    for(i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        t = table[i];
        if(t == NULL)
            printf("empty");
        while(t != NULL) {
            printf("%d -> ", t->data);
            t = t->next;
        }
        printf("\n");
    }
}

int main() {
    int ch, key, i;

    table = (struct Node**)malloc(SIZE * sizeof(struct Node*));
    for(i = 0; i < SIZE; i++)
        table[i] = NULL;   // all lockers empty in start

    while(1) {
        printf("\n1.Insert 2.Display 3.Exit\nChoice: ");
        scanf("%d", &ch);

        if(ch == 1) {
            printf("Value: ");
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