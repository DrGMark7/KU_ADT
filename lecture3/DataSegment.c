#include <stdio.h>
#define SIZE 10

int a[SIZE] = {1}; //. Variable stay in Data Segment
int b[SIZE];       //. Variable stay in BSS Segment

int main(void){
    int c[SIZE] = {1}; //. Variable stay in Stack
    int d[SIZE];       //. Variable stay in Stack

    return 0;
}