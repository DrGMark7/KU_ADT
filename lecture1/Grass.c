#include <stdio.h>
#include <math.h>
#define FOOT_TO_METRE 3.28084
#define SPEED 2 

int main(){
    int length, width;
    printf("length(m.): ");
    scanf("%d", &length);

    printf("width(m.): ");
    scanf("%d", &width);

    double time;

    double area = length * width* FOOT_TO_METRE * FOOT_TO_METRE;
    area = round(area * 100000) / 100000.0;
    time = area / SPEED;
    printf("Use %.5f seconds.", round(time * 100000) / 100000.0);
    return 0;
}