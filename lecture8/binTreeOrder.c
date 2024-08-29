#include <stdio.h>
#include <stdlib.h>
#include "week8.h"

#ifndef __bin_tree__
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t tree_t;
#endif

void print_preorder(tree_t *root);
void print_postorder(tree_t *root);
void print_inorder(tree_t *root);

int main(void) {
    tree_t *t = NULL;
    int n, i;
    int parent, child;
    int branch; // 0 root, 1 left, 2 right
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d %d %d", &parent, &child,
                          &branch);
        t = attach(t, parent, child, branch);
    }
    
    print_preorder(t);
    print_postorder(t);
    print_inorder(t);
    return 0;
}

void _print_preorder(tree_t *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    _print_preorder(root->left);
    _print_preorder(root->right);
}

void print_preorder(tree_t *root) {
    _print_preorder(root);
    printf("\n");
}

void _print_postorder(tree_t *root) {
    if (root == NULL) {
        return;
    }
    _print_postorder(root->left);
    _print_postorder(root->right);
    printf("%d ", root->data);
}

void print_postorder(tree_t *root) {
    _print_postorder(root);
    printf("\n");
}

void _print_inorder(tree_t *root) {
    if (root == NULL) {
        return;
    }
    _print_inorder(root->left);
    printf("%d ", root->data);
    _print_inorder(root->right);
}

void print_inorder(tree_t *root) {
    _print_inorder(root);
    printf("\n");
}