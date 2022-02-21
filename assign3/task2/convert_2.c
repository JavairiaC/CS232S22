#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Program to convert a 32-bit Decimal numbers to Binary
//1) Do not change the signature of convert_2, or your task receives zero
//2) No globals allowed.

char* convert_2(int dec)
{

  int d, inc;
  char *res;

  inc = 2;
  res = (char*)malloc(40+1);
  *(res) = '0';
  *(res+1) = 'b';
  for (int i = 31 ; i >= 0 ; i--)
  {
    d = dec >> i;

    if (d & 1)
      *(res+inc) = 1 + '0';
    else
      *(res+inc) = 0 + '0';

    inc++;
  }
  *(res+inc) = '\0';

  return res;

  }

int main() {
	int n;
	char * bin;
	printf("Enter the Decimal Number\n");
	scanf("%d",&n);
	bin = convert_2(n);
	printf("The Binary Notation of %d is\t %s\n", n, bin);
	//TODO: do we need to release the memory of bin?
  free(bin);
}
