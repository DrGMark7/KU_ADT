#include <stdio.h>

int main(void)
{
	char input;
	printf("Input A Character : ");
	scanf("%c", &input);
	input = tolower(input);
	switch(input){
		case 'b':
			printf("Battleship\n");
			break;
		case 'c':
			printf("\n");
			break;
		case 'd':
			printf("\n");
			break;
		case 'f':
			printf("\n");
			break;
		default:
			printf("Don't Know Input");			
	}

	return 0;
}