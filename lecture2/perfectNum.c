#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_perfect(int num){
    int sum = 0;
    for (int i = 1; i < num; i++){
        if (num % i == 0){
            sum += i;
        }
    }
    return sum == num;
}

bool is_perfect2(int num){
    int sum = 1; // 1 เป็นตัวประกอบของทุกตัวเลข
    int sqrt_num = (int)sqrt(num);

    for (int i = 2; i <= sqrt_num; i++){
        if (num % i == 0){
            if (i == (num / i)) {
                sum += i; // ถ้าตัวประกอบเป็นเลขเดียวกัน
            } else {
                sum += i + (num / i); // บวกทั้ง i และ num/i
            }
        }
    }
    return (sum == num) && (num != 1); // 1 ไม่ใช่จำนวนที่สมบูรณ์
}

int main(){
    int num = 0;
    int sum = 1;
    int temp_perfect = 0;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++){
        if (is_perfect2(i)){
            temp_perfect = i;
        }
    }
    if (num == 2){
        temp_perfect = 1;
    }
    printf("%d\n", temp_perfect);
}