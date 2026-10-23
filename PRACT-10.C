#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int value) {
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node* createTree() {
    int value;

    printf("Enter data (-1 for no node): ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid input!\n");
        exit(1);
    }

    if (value == -1)
        return NULL;

    struct node *newNode = createNode(value);

    printf("Left child of %d:\n", value);
    newNode->left = createTree();

    printf("Right child of %d:\n", value);
    newNode->right = createTree();

    return newNode;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void freeTree(struct node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct node *root;

    printf("--- CREATE BINARY TREE ---\n");
    root = createTree();

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n");

    freeTree(root);

    return 0;
}
