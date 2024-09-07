#include <stdio.h>
#include <stdlib.h>
#define __bin_tree__
#include <week9.h>
#ifndef __bin_tree__
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
    } node_t;
typedef node_t tree_t;
#endif

int is_bst(tree_t *t) {
    if (t == NULL) {
        return 1;
    }
    int leftValid = 0;
    int rightValid = 0;

    if (t->left != NULL) {
        if ((t->left)->data < t->data) {
            leftValid = is_bst(t->left);
        }
    } else {
        leftValid = is_bst(t->left);
    }

    if (t->right != NULL) {
        if (t->right->data > t->data) {
            rightValid = is_bst(t->right);
        }
    } else {
        rightValid = is_bst(t->right);
    }

    return leftValid && rightValid;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int findHeight(tree_t *t) {
    if (t == NULL) {
        return 0;
    }
    return 1 + max(findHeight(t->left), findHeight(t->right));
}

int balance(tree_t *t) {
    if (t == NULL) {
        return -1;
    }
    return findHeight(t->left) - findHeight(t->right);
}

int is_avl(tree_t *t) {
    if (t == NULL) {
        return 1;
    }
    int leftValid = 0;
    int rightValid = 0;
    int balancing = balance(t);

    if (balancing < -1 || balancing > 1) {
        return 0;
    }

    if (t->left != NULL) {
        if ((t->left)->data < t->data) {
            leftValid = is_avl(t->left);
        }
    } else {
        leftValid = is_avl(t->left);
    }

    if (t->right != NULL) {
        if (t->right->data > t->data) {
            rightValid = is_avl(t->right);
        }
    } else {
        rightValid = is_avl(t->right);
    }

    return leftValid && rightValid;
}

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
    printf("%d %d\n", is_bst(t), is_avl(t));
    return 0;
}