#include <stdio.h>

int main() {
    double a, b, h;
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("h: ");
    scanf("%lf", &h);
    double area = (a + b) * h / 2;
    printf("Area is %.1lf\n", area);
    return 0;
}