#include <stdio.h>

int main(void)
{
    char input;
    printf("Input A Character : ");
    scanf("%c", &input);

    if (input == 'b' || input == 'B'){
        printf("Battleship");
    }else if (input == 'c' || input == 'C'){
        printf("Cruiser");
    }else if (input == 'd' || input == 'D'){
        printf("Destroyer");
    }else if (input == 'f' || input == 'F'){
        printf("Frigate");
    }
    return 0;
}