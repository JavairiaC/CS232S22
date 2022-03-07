
#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {
  
  /* Zero out the array */
  int letter_frequency[26] = {0};
  int len, i, a;
  char buf[MAX_BUF];
  char temp[MAX_BUF];

  //GETS ALL THE LINES IN THE FILE
  fgets(buf,MAX_BUF, stdin);
  while(fgets(temp, MAX_BUF, stdin) != NULL){
      strcat(buf, temp);
      fgets(temp, MAX_BUF, stdin);
      strcat(buf, temp);
    }
  len = strlen(buf);

  do {
    i = 0;
    a = 97;
    while(a <= 122){
            if(buf[len] == a || buf[len] == (a-32)){
                letter_frequency[i]++;
              }
            a++;
            i++;
          }
    len--;
  } while (len >= 0);
  
  
  printf("Distribution of letters in corpus:\n");
  for (i = 0; i < 26; i++) {
    // 'A' is ASCII code 65
    printf("%c: %d\n", 65+i, letter_frequency[i]);
  }
  
}  