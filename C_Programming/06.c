#include <stdio.h>

// การประกาศฟังก์ชันสามารถละชื่อพารามิเตอร์เอาไว้ได้
int max_of_three(int,int,int);

int main()
{
  int a,b,c;
  printf("Enter three integers: ");
  scanf("%d %d %d", &a, &b, &c);  //. Input 3 ค่า
  printf("The maximum value is %d\n", max_of_three(a,b,c));
}

int max_of_three(int a,int b,int c)
{
  if(a>b && a>c)
  {
     return a;
   }
  else {
    if(b>c){
       return b;
    }
    else{
       return c;
    }
 }
}