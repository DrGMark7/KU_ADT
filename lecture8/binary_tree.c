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
// Write your code here
// ** Note that the attach() function has
// been implemented already and included
// in the week8.h header
// ...

void print_tree(tree_t *root){
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    print_tree(root->left);
    print_tree(root->right);
}

//. Is Full : Tree has lead only two children or no children
int is_full(tree_t *root) {
    if (root == NULL) {  //. If the tree is empty, it is perfect
        return 1;
    }
    if (root->left == NULL && root->right == NULL) { //. If the tree has no children, it is perfect
        return 1;
    }
    if (root->left != NULL && root->right != NULL) {  //. If the tree has two children, it is perfect
        return is_full(root->left) && is_full(root->right);
    }
    return 0;
}


//. Is Perfect : Tree has all levels filled
int depth(struct node *node) {
    if (node == NULL) {
        return 0;
    }
    int leftDepth = depth(node->left);
    int rightDepth = depth(node->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// check if the tree is perfect
int is_Perfect(struct node *root, int d, int level) {
    // Check if the tree is empty
    if (root == NULL)
        return 1;

    // check the presence of children
    if (root->left == NULL && root->right == NULL)
        return (d == level + 1);

    if (root->left == NULL || root->right == NULL)
        return 0;

    return is_Perfect(root->left, d, level + 1) &&
           is_Perfect(root->right, d, level + 1);
}

// wrapper function
int is_perfect(struct node *root) {
    int d = depth(root);
    return is_Perfect(root, d, 0);
}

//. Is Complete : Tree has all levels filled except the last level
int countNumNodes(tree_t *root) {
    if (root == NULL)
        return (0);
    return (1 + countNumNodes(root->left) + countNumNodes(root->right));
}

// Check if the tree is a complete binary tree
int checkComplete(tree_t *root, int index, int numberNodes) {
  // Check if the tree is complete
    if (root == NULL)
        return 1;

    if (index >= numberNodes)
        return 0;

    return (checkComplete(root->left, 2 * index + 1, numberNodes) && checkComplete(root->right, 2 * index + 2, numberNodes));
}

int is_complete(tree_t *root) {
    int numberNodes = countNumNodes(root);
    return checkComplete(root, 0, numberNodes);
}

//. Is Degenerate : Tree has only one child
int is_degenerate(tree_t *root) {
    if (root == NULL) {  //. If the tree is empty, it is perfect
        return 1;
    }
    if (root->left == NULL && root->right == NULL) { //. If the tree has no children, it is perfect
        return 1;
    }
    if (root->left != NULL && root->right == NULL) {  
        return is_degenerate(root->left);
    }
    if (root->left == NULL && root->right != NULL) {  
        return is_degenerate(root->right);
    }
    return 0;
}

//. Is Skewed : Tree has only one child but just one side
int is_skewed(tree_t *root) {
    if (root == NULL) {
        return 1; // Tree is empty, considered skewed
    }

    if (root->left == NULL && root->right == NULL) {
        return 1; // Tree has no children, considered skewed
    }
    if (is_degenerate(root)){
        while (root->left != NULL) {
            root = root->left;
            if (root->right != NULL) {
                return 0;
            }
        }

        while (root->right != NULL) {
            root = root->right;
            if (root->left != NULL) {
                return 0;
            }
        }
        return 1;
    }else{
        return 0;
    }
}


//. Perfect Bin Tree        degenerate Bin Tree
//.      10                    1                  
//.     /  \                    \
//.    6    18                   2
//.   / \   / \                 /
//.  4   8 15  21              3

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
    // print_tree(t);
    // printf("\nFull : %d\n", is_full(t));
    // printf("Perf : %d\n", is_perfect(t));
    // printf("Comp : %d\n", is_complete(t));
    printf("%d %d %d %d %d\n", is_full(t),
            is_perfect(t), is_complete(t),
            is_degenerate(t), is_skewed(t));
    return 0;
}