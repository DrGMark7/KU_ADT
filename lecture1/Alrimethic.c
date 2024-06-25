#include <stdio.h>
int main(void)
{
    int x = 2, y = 5;
    x += ++y;  // x = x + (++y)บวกก่อนเพิ่ม
    printf("%d %d\n", x, y);

    x += y++;
    printf("%d %d\n", x, y);  // x = x + y บวกหลังเพิ่ม
    return 0;
}