#include <stdio.h>

int main(void){
    char c = '\0';
    printf("Enter a character: ");
    // while ((c = getchar()) != '\n')
    // {
    //     printf("%c", (c>='a') && (c <= 'z') ? c - 'a'+'A':c); //. If c is a lowercase letter, print the uppercase version of c
    // }

    while ((c = getchar()) != '\n') //. C have a buffer of input characters, so we can read characters one by one 
    {
        if((c >= 'a') && (c <= 'z')){
            printf("%c", c - 'a' + 'A'); //. c - 'a' + 'A' is the uppercase version of c
            fflush(stdout); //. Clear the buffer 
                            //. The Performace will drop because of the fflush function can make overhead
        }
        else{
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}