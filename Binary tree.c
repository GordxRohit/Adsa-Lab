#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create(int val) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

// insert left to right (simple way)
struct Node* insert(struct Node *root, int val) {
    if(root == NULL)
        return create(val);

    if(root->left == NULL)
        root->left = create(val);
    else if(root->right == NULL)
        root->right = create(val);
    else
        insert(root->left, val);   // go deeper on left

    return root;
}

void inorder(struct Node *r) {
    if(r) {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

void preorder(struct Node *r) {
    if(r) {
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(struct Node *r) {
    if(r) {
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->data);
    }
}

int main() {
    struct Node *root = NULL;
    int n, val, i;

    printf("How many values: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    return 0;
}