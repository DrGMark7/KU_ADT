#include <stdio.h>

int main()
{
    double width,height,length;
    printf("Enter width, length, and height: ");
    scanf("%lf %lf %lf", &width, &height, &length);
    printf("The volume of the box is %.2lf\n",width*length*height);
    return 0;
}