#include <stdio.h>
#include <math.h>


double function(double x, double A, double B){
    // Asin(πx/B)
    return A*sin((M_PI*x)/B);
}

double area_by_dx(double y1, double y2, double dx){
    return (y1+y2)*dx/2.0;
}

int main(){
    double a=0, b=0, A=0, B=0;
    double n;

    double sum = 0;
    printf("Enter a, b, A, B, n: ");
    scanf("%f %f %f %f %f",&a,&b,&A,&B,&n);

    double dx = (b-a)/(n);
    double temp = 0;
    for (int i = 1; i < n+1; i++){
        temp = area_by_dx(function(a+i*dx,A,B),function(a+(i-1)*dx,A,B),dx);
        sum += temp;
    }
    printf("sum = %.5f\n",sum);
}