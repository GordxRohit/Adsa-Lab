#include <stdio.h>      // for printf and scanf
#include <stdlib.h>     // for malloc and free
#include <conio.h>     

// Structure of a single node
struct Node {
    int data;               // stores the value
    struct Node *next;      // pointer to the next node
};

struct Node *head = NULL;   // head points to the first node (initially empty)

// Function to insert a value at the end of the list
void insert(int val) {
    struct Node *n;                             // create a new node pointer
    n = (struct Node*)malloc(sizeof(struct Node)); // allocate memory for new node
    n->data = val;                              // store the value in the node
    n->next = NULL;                             // new node will be the last, so next is NULL

    if(head == NULL)                            // if list is empty
        head = n;                               // make new node the head
    else {
        struct Node *t = head;                  // temporary pointer to traverse
        while(t->next != NULL)                  // go to the last node
            t = t->next;
        t->next = n;                            // link last node to new node
    }
    printf("Inserted\n");
}

// Function to delete a given value from the list
void deleteNode(int val) {
    struct Node *t = head, *p = NULL;           // t = current, p = previous

    if(head == NULL) {                          // if list is empty
        printf("Empty\n");
        return;
    }

    if(head->data == val) {                     // if value is in the first node
        head = head->next;                      // move head to next node
        free(t);                                // free the old head
        printf("Deleted\n");
        return;
    }

    while(t != NULL && t->data != val) {        // search for the value
        p = t;                                  // keep track of previous node
        t = t->next;                            // move to next node
    }

    if(t == NULL) {                             // value not found
        printf("Not found\n");
        return;
    }

    p->next = t->next;                          // skip the node to be deleted
    free(t);                                    // free the memory of deleted node
    printf("Deleted\n");
}

// Function to display the entire linked list
void display() {
    struct Node *t = head;                      // start from head

    if(t == NULL) {                             // if list is empty
        printf("Empty\n");
        return;
    }

    while(t != NULL) {                          // traverse till last node
        printf("%d -> ", t->data);              // print current node data
        t = t->next;                            // move to next node
    }
    printf("NULL\n");                           // end of list
}

int main() {
    int ch, val;                                // ch = choice, val = value

    while(1) {                                  // infinite loop for menu
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);                       // take user choice

        if(ch == 1) {                           // Insert
            printf("Value: ");
            scanf("%d", &val);
            insert(val);
        }
        else if(ch == 2) {                      // Delete
            printf("Value: ");
            scanf("%d", &val);
            deleteNode(val);
        }
        else if(ch == 3)                        // Display
            display();
        else if(ch == 4)                        // Exit
            break;
        else
            printf("Invalid\n");
    }
    return 0;
}