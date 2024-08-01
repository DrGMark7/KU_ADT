#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100000

typedef struct node {
    char data;
    struct node *next;
} node_t;

typedef node_t stack_ts;

stack_ts *push(stack_ts *s, int value) {
    stack_ts *newNode = (stack_ts *)malloc(sizeof(stack_ts));
    newNode->data = value;
    newNode->next = s;
    return newNode;
}

stack_ts *pop(stack_ts *s) {
    if (s == NULL) {
        return NULL;
    }
    stack_ts *temp = s;
    s = s->next;
    free(temp);
    return s;
}

char top(stack_ts *s) {
    if (s == NULL) {
        return -1;
    }
    return s->data;
}

void show(stack_ts *s) {
    stack_ts *temp = s;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int compareTwoString(char a[],char b[])  
{  
    int flag=0,i=0;  // integer variables declaration  
    while(a[i]!='\0' &&b[i]!='\0')  // while loop  
    {  
       if(a[i]!=b[i])  
       {  
           flag=1;  
           break;  
       }  
       i++;  
    } 
    if(a[i]!='\0'||b[i]!='\0')
       return 1;
    if(flag==0)  
    return 0;  
    else  
    return 1;  
} 

int main(){
    stack_ts *s = NULL;
    char input[MAX_LEN];

    char temp1[MAX_LEN];
    int length1 = 0;
    char temp2[MAX_LEN];
    int length2 = 0;
    char temp3[MAX_LEN];
    
    fgets(input, MAX_LEN, stdin);
    int len = strlen(input) - 2;

    //. If Push data to stack equal to Output from pop function
    //. Then, print "Yes"
    //. Else, print "No"

    int index = 0;
    int index2 = 0;
    while(1){
        if(input[index] == 'x'){
            break;
        }
        temp1[index] = input[index];
        s = push(s, input[index]);
        index++;
    }
    //show(s);
    length1 = index;
    index++; //! skip 'x'
    //printf("index: %d\n", index);
    
    while(1){
        if(input[index] == 'y'){
            break;
        }
        temp2[index2] = top(s);
        s = pop(s);
        temp3[index2] = input[index];
        //printf("temp3: %p\n", temp3);
    
        index2++;
        index++;
    }
    length2 = index2;


    if (length1 != length2) {
        printf("0\n");
        return 0;
    }

    for (int i = 0; i < length1; i++) {
        if (temp1[i] != temp2[length1 - i - 1]) {
            printf("0\n");
            return 0;
        }
    }
    //printf("temp2: %s\n", temp2);
    char com2[9] = "1q2w3e4r";
    //printf("com: %s\n", com);
    // printf("temp1: %s\n", temp1);
    // printf("temp2: %s\n", temp2);
    // printf("temp3: %s\n", temp3);
    // printf("com2: %s\n", com2);
    if(compareTwoString(temp3, com2) == 0){
        printf("0\n");
        return 0;
    }

    printf("1\n");
    return 0;
}