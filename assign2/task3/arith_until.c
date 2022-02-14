/*  Example: C program to find area of a circle */

#include <stdio.h>
#define PI 3.14159


int main()
{

  float r, a, b;
  

  while (r != 0) {
    printf("Enter radius (in mm):\n");
    scanf("%f", &r);

    if(r == 0){
      printf("Exit\n");
      break;
    }

    r = r/25.4;
    a = PI * r * r;
    b = 2 * PI * r;
    printf("Circle's area is %3.2f (sq in).\n", a);
    printf("Its circumference is %3.2f (in).\n", b);
    
    
  }
  

  

}