#include <stdio.h>

int main(){
    int input = 0, lastdigit = 0, reverse = 0;
    printf("Enter a number: ");
    scanf("%d", &input);

    while (input > 0)
    {
        lastdigit = input % 10;
        reverse = reverse * 10 + lastdigit;
        input = input / 10;
    }
    
    printf("The reverse of the number is %d\n", reverse);
}