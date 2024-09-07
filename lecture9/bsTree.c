#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t bst_t;

bst_t *insert(bst_t *t, int data) {
    if (t == NULL) {
        t = (bst_t*)malloc(sizeof(bst_t));
        t->data = data;
        t->left = t->right = NULL;
    } else if (data < t->data) {
        t->left = insert(t->left, data);
    } else if (data > t->data) {
        t->right = insert(t->right, data);
    }
    return t;
}

bst_t *delete(bst_t *t, int data) {
    if (t == NULL) {
        return NULL;
    }
    if (data < t->data) {
        t->left = delete(t->left, data);
    } else if (data > t->data) {
        t->right = delete(t->right, data);
    } else {
        if (t->left == NULL) {
            bst_t *tmp = t->right;
            free(t);
            return tmp;
        } else if (t->right == NULL) {
            bst_t *tmp = t->left;
            free(t);
            return tmp;
        } else {
            bst_t *tmp = t->right;
            while (tmp->left != NULL) {
                tmp = tmp->left;
            }
            t->data = tmp->data;
            t->right = delete(t->right, tmp->data);
        }
    }
    return t;
}

int find(bst_t *t, int data) {
    if (t == NULL) {
        return 0;
    }
    if (data < t->data) {
        return find(t->left, data);
    } else if (data > t->data) {
        return find(t->right, data);
    } else {
        return 1;
    }
}

int find_min(bst_t *t) {
    if (t == NULL) {
        return -1;
    }
    while (t->left != NULL) {
        t = t->left;
    }
    return t->data;
}

int find_max(bst_t *t) {
    if (t == NULL) {
        return -1;
    }
    while (t->right != NULL) {
        t = t->right;
    }
    return t->data;
}

int count_nodes(bst_t *t) {
    if (t == NULL) {
        return 0;
    }
    return 1 + count_nodes(t->left) + count_nodes(t->right);
}

int find_k_th(bst_t *t, int k) {
    if (t == NULL) {
        return -1; // If tree is empty or k is invalid
    }

    // Find the number of nodes in the left subtree
    int left_count = count_nodes(t->left);

    // If k is smaller, the k-th element is in the left subtree
    if (k <= left_count) {
        return find_k_th(t->left, k);
    }
    // If k is exactly the number of nodes in the left subtree + 1, it's the root
    else if (k == left_count + 1) {
        return t->data;
    }
    // If k is larger, the k-th element is in the right subtree
    else {
        return find_k_th(t->right, k - left_count - 1);
    }
}


int main(void) {
    bst_t *t = NULL;
    int n, i;
    int command, data, k;

    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &command);
        switch (command) {
            case 1:
                scanf("%d", &data);
                t = insert(t, data);
                break;
            case 2:
                scanf("%d", &data);
                t = delete(t, data);
                break;
            case 3:
                scanf("%d", &data);
                printf("%d\n", find(t, data));
                break;
            case 4:
                printf("%d\n", find_min(t));
                break;
            case 5:
                printf("%d\n", find_max(t));
                break;
            case 6:
                scanf("%d", &k);
                printf("%d\n", find_k_th(t, k));
            break;
        }
    }
    return 0;
}