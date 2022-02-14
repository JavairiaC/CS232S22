/*  Example: C program to find area of a circle */

#include <stdio.h>
#define PI 3.14159

int main()
{
  float r, a, b;

  printf("Enter radius (in mm):\n");
  scanf("%f", &r);

  a = PI * (r/25.4) * (r/25.4);
  b = 2 * PI * (r/25.4);
  printf("Circle's area is %3.2f (sq in).\n", a);
  printf("Its circumference is %3.2f (in).\n", b);
}
