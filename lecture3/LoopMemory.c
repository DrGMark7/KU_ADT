#include <stdio.h>

int main(void){
    int a[10] = {1}; //. Variable stay in Stack

    for(int i = -10000; i < 10000; i++){
        printf("a[%d] = %d\n", i, a[i]);  //. Accessing out of bound
    }                                     //. Maybe Core dump: Segmectation fault
}

//! zsh: segmentation fault  "/Users/drgmark7/Desktop/Code/KU_ADT/lecture3/"LoopMemory
//! The program will crash because it tries to access memory that is not allocated to it.