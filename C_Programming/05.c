#include <stdio.h>

int main()
{
  int x;

  printf("Enter a number: ");
  scanf("%d", &x);
  if (x%2)  //. if สามารถเขียนแบบไม่มีปีกกาได้
    printf("This is an odd number.");
  else
    printf("This is an even number.");

}