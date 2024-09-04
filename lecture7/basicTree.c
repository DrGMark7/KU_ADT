#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *next_sibling;
    struct node *first_child;
}tree_t;


typedef struct list{
    struct node* point_num;
    struct list *next;
}queue_tp;

typedef struct st{
    int data;
    struct st *next;
}stack_tp;

stack_tp *push(stack_tp*stack,int value){
    stack_tp *temp = (stack_tp*)malloc(sizeof(stack_tp));
    temp->data = value;
    temp->next = NULL;
    if (stack == NULL){
        return temp;
    }
    temp->next = stack;
    stack = temp;
    return stack;
}

int pop(stack_tp**stack){
    int number = (*stack)->data;
    stack_tp *temp1 = *stack;
    *stack = temp1->next;
    free(temp1);
    return number;
}

queue_tp *enqueue(queue_tp*q,tree_t* value){
    queue_tp*temp = (queue_tp*)malloc(sizeof(queue_tp));
    temp->point_num = value;
    temp->next = NULL;
    queue_tp*temp1 = q;
    if (q == NULL){
        return temp;
    }
    while(temp1->next != NULL){
        temp1 = temp1->next;
    }
    temp1->next = temp;
    return q;
}

tree_t* dequeue(queue_tp **q){
    queue_tp *temp = *q;
    tree_t* number = temp->point_num;
    *q = temp->next;
    free(temp);
    return number;
}

void bfs(tree_t*t){
    queue_tp*q_temp = NULL;
    q_temp = enqueue(q_temp,t);
    while(q_temp != NULL){
        // printf("%d ",dequeue(&q_temp)->number);
        tree_t*point_temp = dequeue(&q_temp);
        printf("%d ",point_temp->number);
        point_temp = point_temp->first_child;
        while(point_temp != NULL){
            q_temp = enqueue(q_temp,point_temp);
            point_temp = point_temp->next_sibling;
        }
    }
    printf("\n");
}
void tvr(queue_tp*q){
    while (q != NULL){
        printf("%d ",(q->point_num)->number);
        q = q->next;
    }
    printf("\n");
}
tree_t* search_t(tree_t *t, int value) {
    if (t == NULL) {
        return NULL;
    }
    if (t->number == value) {
        return t;
    }
    tree_t *pos = search_t(t->first_child, value);
    if (pos != NULL) {
        return pos;
    } else {
        return search_t(t->next_sibling, value);
    }
}


int search(tree_t *t, int value){
    if (t == NULL){
        return 0;
    }
    if (t->number == value){
        return 1;
    }
    if (search(t->first_child,value)){
        return 1;
    }
    return search(t->next_sibling,value);
}

void dfs(tree_t*t){
    tree_t* node_t = t;
    if (t == NULL);
    else{
    printf("%d ",node_t->number);
    dfs(node_t->first_child);
    dfs(node_t->next_sibling);
    }
}

int degree(tree_t*t,int value){
    int n = 0;
    tree_t*node_value = search_t(t,value);
    if (node_value->first_child == NULL) return n;
    node_value = node_value->first_child;
    while(node_value != NULL){
        node_value = node_value->next_sibling;
        n++;
    }
    return n;
}

int is_root(tree_t*t,int value){
    if (t->number == value) return 1;
    return 0;
}
int is_leaf(tree_t*t,int value){
    tree_t*node_l = search_t(t,value);
    if(node_l->first_child == NULL){
        return 1;
    }
    return 0;
}

tree_t* search_tv(tree_t *root, int sibling_number) {
    if (root == NULL) {
        return NULL;
    }
    tree_t *child = root->first_child;
    while (child != NULL) {
        if (child->number == sibling_number) {
            return root;
        }
        child = child->next_sibling;
    }

    child = root->first_child;
    while (child != NULL) {
        tree_t *parent = search_tv(child, sibling_number);
        if (parent != NULL) {
            return parent;
        }
        child = child->next_sibling;
    }

    return NULL;
}

void print_path(tree_t*t,int start, int end){
    stack_tp *st_stack = NULL;
    st_stack = push(st_stack,end);
    while(st_stack->data != start){
        int value_f = search_tv(t,st_stack->data)->number;
        st_stack = push(st_stack,value_f);
    }
    while (st_stack != NULL){
        printf("%d ",pop(&st_stack));
    }
    printf("\n");
}

int path_length(tree_t*t,int start, int end){
    int number = 0;
    stack_tp *st_stack = NULL;
    st_stack = push(st_stack,end);
    while(st_stack->data != start){
        int value_f = search_tv(t,st_stack->data)->number;
        st_stack = push(st_stack,value_f);
    }
    while (st_stack != NULL){
        number++;
        pop(&st_stack);
    }
    return number;
}

void ancestor(tree_t*t, int value){
    int start = 1,end = value;
    stack_tp *st_stack = NULL;
    st_stack = push(st_stack,end);
    while(st_stack->data != start){
        int value_f = search_tv(t,st_stack->data)->number;
        st_stack = push(st_stack,value_f);
    }
    while (st_stack != NULL){
        printf("%d ",pop(&st_stack));
    }
    printf("\n");
}

void descendant(tree_t*t, int value){
    tree_t*first_st = search_t(t,value);
    bfs(first_st);
}
void siblings(tree_t*t, int value){
    if (t->number == value){
        printf("\n");
    }else{
    tree_t*s_p = search_tv(t, value);
    s_p = s_p->first_child;
    while (s_p != NULL){
        if (s_p->number != value){
            printf("%d ",s_p->number);
        }
        s_p = s_p->next_sibling;
    }
    printf("\n");
    }
}

int find_depth(tree_t*t,int target, int point){
    if (t == NULL){
        return -1;
    }
    if (t->number == target){
        return point;
    }
    tree_t *t_point = t->first_child;
    while(t_point != NULL){
        int depth = find_depth(t_point,target,point+1);
        if (depth != -1){
            return depth;
        }
        t_point = t_point->next_sibling;
    }
    return -1;
}

int depth(tree_t*t,int value){
    return find_depth(t,value,0);
}
tree_t *attach(tree_t*t,int parent, int child){
    tree_t *temp =  (tree_t*)malloc(sizeof(tree_t));
    temp->number = child;
    if (parent == -1){
        return temp;
    }
    tree_t *pos = search_t(t,parent);
    if (pos->first_child == NULL){
        pos->first_child = temp;
    }else{
        pos = pos->first_child;
        while(pos->next_sibling != NULL){
            pos = pos->next_sibling;
        }
        pos->next_sibling = temp;
    }
    return t;
}

void clean(tree_t*t){
    if (t == NULL){
        return;
    }
    clean(t->first_child);
    clean(t->next_sibling);
    free(t);
}

tree_t* detach(tree_t*t,int value){
    tree_t*search_th = search_tv(t,value);
    tree_t*temp = search_th->first_child;
    tree_t*temp1 = temp;
    if (temp->number == value){
        search_th->first_child = temp->next_sibling;
        temp->next_sibling = NULL;
        clean(temp);
        return t;
    }else{
        while((temp->next_sibling)->number != value){
            temp = temp->next_sibling;
        }
        temp1 = temp->next_sibling;
        temp->next_sibling = temp1->next_sibling;
        temp1->next_sibling = NULL;
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
    print_tree_recursive(node->first_child, level + 4);
    print_tree_recursive(node->next_sibling, level);
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