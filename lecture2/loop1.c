#include <stdio.h>

int main() {
    float money_safe = 1000;  
    float yield = 0.05;  //. 5% yield
    int years = 10;

    for (int i = 0; i < years; i++) {
        money_safe = money_safe + money_safe * yield;
    }

    printf("After %d years, you will have %.2f dollars\n", years, money_safe);
}