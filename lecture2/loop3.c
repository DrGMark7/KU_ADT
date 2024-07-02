#include <stdio.h>

int main(void){
    char c = '\0';
    printf("Enter a character: ");
    while ((c = getchar()) != '\n')
    {
        printf("%c", (c>='a') && (c <= 'z') ? c - 'a'+'A':c);
    }
    printf("\n");
}