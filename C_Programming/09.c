#include <stdio.h>

#define IS_VALID(x)  ((50<=x) && (x<=200))
#define VALID_MSG    "Good value.\n"
#define INVALID_MSG  "Bad value.\n"

//- use gcc -E -o prog.i prog.c

int main()
{
  int val;

  printf("Enter a value: ");
  scanf("%d", &val);
  if (IS_VALID(val))
    printf(VALID_MSG);
  else
    printf(INVALID_MSG);

  return 0;
}