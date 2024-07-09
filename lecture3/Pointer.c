#include <stdio.h>

void func(int *a) {
    *(a+3) *= 2;
}

int main() {
    int a[5] = {0};
    int *p = a;
    p[2] = 5;
    *(p + 3) = 8; // *(p + 3) is equivalent to p[3]
    printf("a[2] = %d\n", a[2]); 
    printf("a[3] = %d\n", a[3]);

    func(a);
    printf("a[3] = %d\n", a[3]);
}