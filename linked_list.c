#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;   // Head pointer

// Insert at end
void insert(int val) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->next = NULL;

    if(head == NULL) {
        head = n;               // First node
    } else {
        struct Node *t = head;
        while(t->next != NULL)
            t = t->next;
        t->next = n;            // Add at end
    }
    printf("Inserted\n");
}

// Delete a node by value
void delete(int val) {
    struct Node *t = head, *p = NULL;

    if(head == NULL) {
        printf("Empty\n");
        return;
    }

    // If head node is to be deleted
    if(head->data == val) {
        head = head->next;
        free(t);
        printf("Deleted\n");
        return;
    }

    // Search the node
    while(t != NULL && t->data != val) {
        p = t;
        t = t->next;
    }

    if(t == NULL) {
        printf("Not found\n");
        return;
    }

    p->next = t->next;          // Unlink the node
    free(t);
    printf("Deleted\n");
}

// Display the list
void display() {
    struct Node *t = head;
    if(t == NULL) {
        printf("Empty\n");
        return;
    }
    while(t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int main() {
    int ch, val;
    while(1) {
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);

        if(ch == 1) {
            printf("Value: ");
            scanf("%d", &val);
            insert(val);
        }
        else if(ch == 2) {
            printf("Value: ");
            scanf("%d", &val);
            delete(val);
        }
        else if(ch == 3)
            display();
        else if(ch == 4)
            break;
        else
            printf("Invalid\n");
    }
    return 0;
}