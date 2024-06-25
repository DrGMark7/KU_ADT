#include <stdio.h>

int main() {
    float weight, height;
    
    scanf("%f %f", &weight , &height);
    height = height / 100;
    float bmi = weight / (height * height);

    if(bmi < 18.6) {
        printf("BMI: %.4f and you are underweight", bmi);
    } else if(bmi < 25) {
        printf("BMI: %.4f and you are healthy", bmi);
    } else if(bmi < 30) {
        printf("BMI: %.4f and you are overweight" ,bmi);
    } else {
        printf("BMI: %.4f and you are obese", bmi);
    }
}