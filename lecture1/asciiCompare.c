#include <stdio.h>

int main() {
    char c1, c2;
    scanf("%c %c", &c1, &c2);
    int diff;
    if(c1 > c2) {
        diff = c1 - c2;
    } else {
        diff = c2 - c1;
    }
    printf("%d\n", diff);
}