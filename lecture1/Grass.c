#include <stdio.h>
#include <math.h>
#define FOOT_TO_METRE 3.28084
#define SPEED 2 

int main(){
    int length, width;
    length = 3;
    width = 7;
    printf("length(m.): ");
    // scanf("%d", &length);

    printf("width(m.): ");
    // scanf("%d", &width);

    float time;
    // float length_foot = length  FOOT_TO_METRE;
    // float width_foot = width * FOOT_TO_METRE;
    float area = length * width* FOOT_TO_METRE * FOOT_TO_METRE;
    time = area / SPEED;
    float rounded_time = round(time * 1000000) / 1000000;
    
    printf("time: %f\n", rounded_time);
    printf("Use %f seconds.", round(time * 100000) / 100000);
    printf("%f\n", round(0.54 * 10) / 10);    
}