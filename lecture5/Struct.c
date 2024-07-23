#include <stdio.h>
#include <stdbool.h>

struct Kim{
    char name[10];
    float IELTS;
    int TPAT;
    int TGAT;
    bool SmarterThanMe;
} Kim;



int main(){

    struct Kim Kim1 = {"Kim", 9.0, 100, 100, true};
    
    printf("Name: %s\n", Kim1.name);
    printf("IELTS: %.1f\n", Kim1.IELTS);
    printf("TPAT: %d\n", Kim1.TPAT);
    printf("TGAT: %d\n", Kim1.TGAT);
    printf("Smarter than me: %s\n", Kim1.SmarterThanMe ? "true" : "false");
    return 0;
}

