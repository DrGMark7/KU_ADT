#include <stdbool.h>
#include <stdio.h>

bool is_leap_year(int year){
    if (year % 4 == 0){
        if (year % 100 == 0){
            if (year % 400 == 0){
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

int start_day_in_month(int year, int month){
    int days = 0;
    for (int i = 1900; i < year; i++){
        days += is_leap_year(i) ? 366 : 365;
    }
    for (int i = 1; i < month; i++){
        switch (i){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                days += 31;
                break;
            case 4: case 6: case 9: case 11:
                days += 30;
                break;
            case 2:
                days += is_leap_year(year) ? 29 : 28;
                break;
            default:
                printf("Invalid month\n");
                return -1;
        }
    }
    return days % 7;
}

int get_day_in_month(int month, int year){
    switch (month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return is_leap_year(year) ? 29 : 28;
        default:
            printf("Invalid month\n");
            return -1;
    }
}

void print_calendar(int year, int month){
    int start_day = start_day_in_month(year, month)+1;
    if (start_day == -1){
        return;
    }
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    for (int i = 0; i < start_day; i++){
        printf("    ");
    }
    for (int i = 1; i <= get_day_in_month(month, year); i++){
        printf("%3d ", i);
        if ((start_day + i) % 7 == 0){
            printf("\n");
        }
    }
    printf("\n");
}

void format_month(int month){
    switch (month){
        case 1:
            printf("January");
            break;
        case 2:
            printf("February");
            break;
        case 3:
            printf("March");
            break;
        case 4:
            printf("April");
            break;
        case 5:
            printf("May");
            break;
        case 6:
            printf("June");
            break;
        case 7:
            printf("July");
            break;
        case 8:
            printf("August");
            break;
        case 9:
            printf("September");
            break;
        case 10:
            printf("October");
            break;
        case 11:
            printf("November");
            break;
        case 12:
            printf("December");
            break;
        default:
            printf("Invalid month\n");
    }
}

int main(){
    int year, month;
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month: ");
    scanf("%d", &month);
    printf("====================\n");

    format_month(month);
    printf(" %d\n", year);
    print_calendar(year, month);
    return 0;
}