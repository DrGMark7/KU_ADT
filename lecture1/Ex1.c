#include <stdio.h>

int main()
{
    int r;
    float pi = 3.14159;
    printf("Enter the radius of the circle: ");
    scanf("%d", &r);
    float area = pi * r * r;
    printf("Area of Circle is %f" ,area);
    return 0;
}