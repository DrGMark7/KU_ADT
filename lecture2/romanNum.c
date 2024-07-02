#include <stdio.h>
#include <string.h>

int integer_to_roman(int num, char *roman){
    char *roman_numeral[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int roman_value[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    int i = 12;
    int count = 0;
    while (num > 0){

        //. Example: 3542
        //. 3542 / 1000 = 3 -> 3*M
        //. 3542 % 1000 = 542
        //. 542 / 900 = 0 -> 0*CM
        //. 542 / 500 = 1 -> 1*D
        //. 542 % 500 = 42 
        //. 42 / 40 = 1 -> 1*L
        //. 42 % 40 = 2
        //. 2 / 1 = 2 -> 2*I
        //. 2 % 1 = 0

        count = num / roman_value[i]; //. หารเพื่อหาจำนวนตัวอักษร
        num = num % roman_value[i];   //. หารเพื่อหาเศษ
        while (count > 0){            //. วนลูปเพื่อเพิ่มตัวอักษรโรมัน
            strcat(roman, roman_numeral[i]);  //. ต่อ string
            count--;
        }
        i--;
    }
    return 0;
}

int main(){
    int num = 0;
    char roman[100] = ""; //. สร้าง string สำหรับเก็บตัวอักษรโรมัน

    int round = 0;
    scanf("%d", &round);

    for (int i = 0; i < round; i++){
        scanf("%d", &num);
        integer_to_roman(num, roman);
        printf("%s\n", roman);
        memset(roman, 0, sizeof(roman));
    }

    return 0;
}