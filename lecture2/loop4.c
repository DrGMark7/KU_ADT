#include <stdio.h>

int main(void){
    char c = '\0';
    printf("Enter a character: ");
    do{
        c = getchar();
        if((c >= 'a') && (c <= 'z')){
            printf("%c", c - 'a' + 'A'); //. c - 'a' + 'A' is the uppercase version of c
            fflush(stdout); //. Clear the buffer 
                            //. The Performace will drop because of the fflush function can make overhead
        }
        else{
            printf("%c", c);
        }
    }
    while (c != '\n');{
        printf("\n");
    }
    
    return 0;
}