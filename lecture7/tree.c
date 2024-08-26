#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node *nextSibling;
    struct Node *firstChild;
} tree_t;

typedef struct Queue {
    tree_t *pointNum;
    struct Queue *next;
} QueueNode;

typedef struct Stack {
    int data;
    struct Stack *next;
} StackNode;

StackNode *push(StackNode *stack, int value) {
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    temp->data = value;
    temp->next = NULL;
    if (stack == NULL) {
        return temp;
    }
    temp->next = stack;
    stack = temp;
    return stack;
}

int pop(StackNode **stack) {
    int number = (*stack)->data;
    StackNode *temp1 = *stack;
    *stack = temp1->next;
    free(temp1);
    return number;
}

QueueNode *enqueue(QueueNode *queue, tree_t *value) {
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    temp->pointNum = value;
    temp->next = NULL;
    QueueNode *temp1 = queue;
    if (queue == NULL) {
        return temp;
    }
    while (temp1->next != NULL) {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    return queue;
}

tree_t *dequeue(QueueNode **queue) {
    QueueNode *temp = *queue;
    tree_t *number = temp->pointNum;
    *queue = temp->next;
    free(temp);
    return number;
}

void bfs(tree_t *t) {
    QueueNode *queueTemp = NULL;
    queueTemp = enqueue(queueTemp, t);
    while (queueTemp != NULL) {
        tree_t *pointTemp = dequeue(&queueTemp);
        printf("%d ", pointTemp->number);
        pointTemp = pointTemp->firstChild;
        while (pointTemp != NULL) {
            queueTemp = enqueue(queueTemp, pointTemp);
            pointTemp = pointTemp->nextSibling;
        }
    }
    printf("\n");
}

void tvr(QueueNode *queue) {
    while (queue != NULL) {
        printf("%d ", (queue->pointNum)->number);
        queue = queue->next;
    }
    printf("\n");
}

tree_t *searchT(tree_t *t, int value) {
    if (t == NULL) {
        return NULL;
    }
    if (t->number == value) {
        return t;
    }
    tree_t *pos = searchT(t->firstChild, value);
    if (pos != NULL) {
        return pos;
    } else {
        return searchT(t->nextSibling, value);
    }
}

int search(tree_t *t, int value) {
    if (t == NULL) {
        return 0;
    }
    if (t->number == value) {
        return 1;
    }
    if (search(t->firstChild, value)) {
        return 1;
    }
    return search(t->nextSibling, value);
}

void dfs(tree_t *t) {
    tree_t *nodeT = t;
    if (t == NULL);
    else {
        printf("%d ", nodeT->number);
        dfs(nodeT->firstChild);
        dfs(nodeT->nextSibling);
    }
}

int degree(tree_t *t, int value) {
    int n = 0;
    tree_t *nodeValue = searchT(t, value);
    if (nodeValue->firstChild == NULL) return n;
    nodeValue = nodeValue->firstChild;
    while (nodeValue != NULL) {
        nodeValue = nodeValue->nextSibling;
        n++;
    }
    return n;
}

int is_root(tree_t *t, int value) {
    if (t->number == value) return 1;
    return 0;
}

int is_leaf(tree_t *t, int value) {
    tree_t *nodeL = searchT(t, value);
    if (nodeL->firstChild == NULL) {
        return 1;
    }
    return 0;
}

tree_t *searchTV(tree_t *root, int siblingNumber) {
    if (root == NULL) {
        return NULL;
    }
    tree_t *child = root->firstChild;
    while (child != NULL) {
        if (child->number == siblingNumber) {
            return root;
        }
        child = child->nextSibling;
    }

    child = root->firstChild;
    while (child != NULL) {
        tree_t *parent = searchTV(child, siblingNumber);
        if (parent != NULL) {
            return parent;
        }
        child = child->nextSibling;
    }

    return NULL;
}

void print_path(tree_t *t, int start, int end) {
    StackNode *stack = NULL;
    stack = push(stack, end);
    while (stack->data != start) {
        int valueF = searchTV(t, stack->data)->number;
        stack = push(stack, valueF);
    }
    while (stack != NULL) {
        printf("%d ",
        pop(&stack));
    }
    printf("\n");
}

int path_length(tree_t *t, int start, int end) {
    int length = 0;
    StackNode *stack = NULL;
    stack = push(stack, end);
    while (stack->data != start) {
        int valueF = searchTV(t, stack->data)->number;
        stack = push(stack, valueF);
    }
    while (stack != NULL) {
        length++;
        pop(&stack);
    }
    return length;
}

void ancestor(tree_t *t, int value) {
    StackNode *stack = NULL;
    stack = push(stack, value);
    while (stack->data != 1) {
        int valueF = searchTV(t, stack->data)->number;
        stack = push(stack, valueF);
    }
    while (stack != NULL) {
        printf("%d ", pop(&stack));
    }
    printf("\n");
}

void descendant(tree_t *t, int value) {
    tree_t *pos = searchT(t, value);
    bfs(pos);
}

void siblings(tree_t *t, int value) {
    tree_t *nodeS = searchT(t, value);
    if (is_root(t, value)) {
        printf("\n");
        return;
    }
    nodeS = searchTV(t, value);
    nodeS = nodeS->firstChild;
    while (nodeS != NULL) {
        if (nodeS->number != value) printf("%d ", nodeS->number);
        nodeS = nodeS->nextSibling;
    }
    printf("\n");
}

int depth(tree_t *t, int value) {
    int n = 0;
    tree_t *nodeD = searchT(t, value);
    while (!is_root(t, nodeD->number)) {
        n++;
        nodeD = searchTV(t, nodeD->number);
    }
    return n;
}

tree_t *attach(tree_t *t, int parent, int child) {
    tree_t *temp = (tree_t *)malloc(sizeof(tree_t));
    temp->number = child;
    temp->firstChild = NULL;
    temp->nextSibling = NULL;
    if (parent == -1) return temp;
    tree_t *parentNode = searchT(t, parent);
    if (parentNode->firstChild == NULL) {
        parentNode->firstChild = temp;
    } else {
        tree_t *siblingNode = parentNode->firstChild;
        while (siblingNode->nextSibling != NULL) {
            siblingNode = siblingNode->nextSibling;
        }
        siblingNode->nextSibling = temp;
    }
    return t;
}

void clean(tree_t*t){
    if (t == NULL){
        return;
    }
    clean(t->firstChild);
    clean(t->nextSibling);
    free(t);
}

tree_t* detach(tree_t*t,int value){
    tree_t*search_th = searchTV(t,value);
    tree_t*temp = search_th->firstChild;
    tree_t*temp1 = temp;
    if (temp->number == value){
        search_th->firstChild = temp->nextSibling;
        temp->nextSibling = NULL;
        clean(temp);
        return t;
    }else{
        while((temp->nextSibling)->number != value){
            temp = temp->nextSibling;
        }
        temp1 = temp->nextSibling;
        temp->nextSibling = temp1->nextSibling;
        temp1->nextSibling = NULL;
        clean(temp1);
        return t;
    }
}


void print_tree_recursive(tree_t *node, int level) {
    if (node == NULL) return;
    for (int i = 0; i < level; i++) {
        printf(" ");
    }
    printf("%d\n", node->number);
    print_tree_recursive(node->firstChild, level + 4);
    print_tree_recursive(node->nextSibling, level);
}

void print_tree(tree_t *t) {
    print_tree_recursive(t, 0);
}


int main(void) {
    tree_t *t = NULL;
    int n, i, command;
    int parent, child, node, start, end;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &command);
        switch(command) {
            case 1:
                scanf("%d %d", &parent, &child);
                t = attach(t, parent, child);
                break;
            case 2:
                scanf("%d", &node);
                t = detach(t, node);
                break;
            case 3:
                scanf("%d", &node);
                printf("%d\n", search(t, node));
                break;
            case 4:
                scanf("%d", &node);
                printf("%d\n", degree(t, node));
                break;
            case 5:
                scanf("%d", &node);
                printf("%d\n", is_root(t, node));
                break;
            case 6:
                scanf("%d", &node);
                printf("%d\n", is_leaf(t, node));
                break;
            case 7:
                scanf("%d", &node);
                siblings(t, node);
                break;
            case 8:
                scanf("%d", &node);
                printf("%d\n", depth(t, node));
                break;
            case 9:
                scanf("%d %d", &start, &end);
                print_path(t, start, end);
                break;
            case 10:
                scanf("%d %d", &start, &end);
                printf("%d\n",path_length(t, start, end));
                break;
            case 11:
                scanf("%d", &node);
                ancestor(t, node);
                break;
            case 12:
                scanf("%d", &node);
                descendant(t, node);
                break;
            case 13:
                bfs(t);
                break;
            case 14:
                dfs(t);
                break;
            case 15:
                print_tree(t);
                break;
            }
        }
    return 0;
}