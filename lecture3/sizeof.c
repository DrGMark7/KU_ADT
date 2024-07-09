#include <stdio.h>

int main(void){
    int a = 1;
    int b = 2;

    printf("Size of a            : %ld\n", sizeof(a));          //. 4
    printf("Size of a+b          : %ld\n", sizeof(a+b));        //. 4
    printf("Size of char a       : %ld\n", sizeof(char));       //. 1
    printf("Size of int a        : %ld\n", sizeof(int));        //. 4
    printf("Size of float a      : %ld\n", sizeof(float));      //. 4
    printf("Size of double a     : %ld\n", sizeof(double));     //. 8
    printf("Size of long a       : %ld\n", sizeof(long));       //. 8
    printf("Size of long long a  : %ld\n", sizeof(long long));  //. 8
    printf("Size of long double a: %ld\n", sizeof(long double));//. 8 but it should be 16 Becuase Compiler Verision
                                                                //. if you use Mac (C17) Compiler you will get 8 Bytes
                                                                //.  else you use C99 Compiler you will get 16 Bytes
    printf("Size of size_t       : %ld\n", sizeof(size_t));     //. 8
}