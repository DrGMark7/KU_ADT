#include <stdio.h>
int main()
{
    int m ,n;
    int s1, s2 ,hypotenuse;
    scanf("%d %d", &m, &n);
    
    s1 = m * m - n * n;
    s2 = 2 * m * n;
    hypotenuse = m * m + n * n;

    printf("%d %d %d", s1 ,s2 ,hypotenuse);
}