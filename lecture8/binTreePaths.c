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

int countPathsWithSumFromNode(tree_t *node, int targetSum, int currentSum){
    if (node == NULL) {
        return 0;
    }
    currentSum += node->data;
    int totalPaths = 0;
    if (currentSum == targetSum) {
        totalPaths++;
    }
    totalPaths += countPathsWithSumFromNode(node->left, targetSum, currentSum);
    totalPaths += countPathsWithSumFromNode(node->right, targetSum, currentSum);
    return totalPaths;

}

int countPathsWithSum(tree_t *root, int sum){
    if (root == NULL) {
        return 0;
    }
    int pathsFromRoot = countPathsWithSumFromNode(root, sum, 0);
    int pathsOnLeft = countPathsWithSum(root->left, sum);
    int pathsOnRight = countPathsWithSum(root->right, sum);
    return pathsFromRoot + pathsOnLeft + pathsOnRight;
}



int main(void) {
    tree_t *t = NULL;
    int n, s, i;
    int parent, child;
    int branch; // 0 root, 1 left, 2 right
    scanf("%d %d", &n, &s);
    for (i=0; i<n; i++) {
        scanf("%d %d %d", &parent, &child,
                          &branch);
        t = attach(t, parent, child, branch);
    }
    
    printf("%d\n", countPathsWithSum(t, s));
    return 0;
}