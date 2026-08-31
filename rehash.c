#include <stdio.h>
#include <stdlib.h>

int SIZE = 10, count = 0;

struct Node {
    int data;
    struct Node *next;
};

struct Node **table;

// polynomial hash
// example: 123 = 1*31^2 + 2*31 + 3
int hash(int key) {
    int h = 0, p = 31, power = 1;
    int n = key;

    if(n < 0) n = -n;
    if(n == 0) return 0;

    while(n > 0) {
        int digit = n % 10;        // last digit
        h = h + digit * power;
        power = power * p;
        n = n / 10;
    }
    return h % SIZE;               // fit into table
}

void put(int key) {
    int i = hash(key);
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = key;
    n->next = table[i];
    table[i] = n;
}

void rehash() {
    int old = SIZE, i;
    struct Node **oldT = table, *t, *n;

    SIZE = SIZE * 2;
    table = (struct Node**)malloc(SIZE * sizeof(struct Node*));
    for(i = 0; i < SIZE; i++) table[i] = NULL;

    printf("50%% full, size now %d. Rehashing...\n", SIZE);

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
    if(count > SIZE / 2)
        rehash();
}

void display() {
    int i;
    struct Node *t;
    printf("\nSize=%d Count=%d\n", SIZE, count);
    for(i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        t = table[i];
        if(t == NULL) printf("empty");
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
    for(i = 0; i < SIZE; i++) table[i] = NULL;

    while(1) {
        printf("\n1.Insert 2.Display 3.Exit\nChoice: ");
        scanf("%d", &ch);
        if(ch == 1) {
            printf("Value: "); scanf("%d", &key);
            insert(key);
        }
        else if(ch == 2) display();
        else if(ch == 3) break;
        else printf("Invalid\n");
    }
    return 0;
}