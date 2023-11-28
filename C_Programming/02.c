#include <stdio.h>

int main()
{
  double t = 30;
  double g = 9.81;

  printf("At time t=%.1lf seconds, the velocity is %.2lf m/s", t, t*g);

  return 0;
}