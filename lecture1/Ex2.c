#include <stdio.h>

int main(void)
{
    char input_type;
    char s = 's';
    char t = 't';
    printf("Enter the type S(Square) or T(Triangle) ");
    scanf("%c", &input_type);
    
    if(input_type == s){
        int side;
        printf("Enter the side of the square: ");
        scanf("%d", &side);
        int area = side * side;
        printf("Area of Square is %d" ,area);
    }
    else if(input_type == t)
    {
        int base, height;
        printf("Enter the base of the triangle: ");
        scanf("%d", &base);
        printf("Enter the height of the triangle: ");
        scanf("%d", &height);
        int area = 0.5 * base * height;
        printf("Area of Triangle is %d" ,area);
    }

    return 0;
}