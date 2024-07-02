#include <stdio.h>
#include <math.h>


float function(float x, float A, float B){
    // Asin(πx/B)
    return A*sin((M_PI*x)/B);
}

float area_by_dx(float y1, float y2, float dx){
    return (y1+y2)*dx/2.0;
}

int main(){
    float a=0, b=0, A=0, B=0;
    float n;

    float sum = 0;
    printf("Enter a, b, A, B, n: ");
    scanf("%f %f %f %f %f",&a,&b,&A,&B,&n);

    float dx = (b-a)/(n);
    float temp = 0;
    for (int i = 1; i < n+1; i++){
        temp = area_by_dx(function(a+i*dx,A,B),function(a+(i-1)*dx,A,B),dx);
        sum += temp;
    }
    printf("sum = %.5f\n",sum);
}