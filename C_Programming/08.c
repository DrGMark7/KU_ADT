#include <stdio.h>

int main()
{
  int max_weight;
  int counter_weight = 0;
  int temp_weight = 0,counter = 0;

  printf("Enter the maximum weight in kg: ");
  scanf("%d", &max_weight);

  while (1)
  {
    printf("Enter passenger's weight in kg: ");
    scanf("%d" , &temp_weight);
    counter_weight += temp_weight;
    temp_weight = 0;
    if(counter_weight > max_weight) break;
    counter++;
    if(counter_weight == max_weight) break;
  }
  printf("The elevator can carry %d passenger(s)", counter);
}