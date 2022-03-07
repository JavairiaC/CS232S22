#include <stdio.h>

int main(int argc, char *argv[]) {

   char str[1000];
   int ch, n = 0;

   while ((ch = getchar()) != EOF && n < 1000) {
      str[n] = ch;
      ++n;
   }
   
   for (int i = 0; i < n; ++i){
    if (str[i] <= 122 && str[i] >= 97)
      putchar(str[i]-32);
    else
      putchar(str[i]);
     
   }
      
  
   
   //putchar('\n'); /* trailing '\n' needed in Standard C */

    return 0;


}

