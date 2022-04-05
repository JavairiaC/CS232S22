#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main (){
  int len, i, uppercase = 0, lowercase = 0, digit = 0, whitespace = 
 0, word = 0, line = 0, character = 0;
  char buf[MAX_BUF];


  
  do{

    
    while(fgets(buf, MAX_BUF, stdin) != NULL){
      len = strlen(buf) - 1;
      for(i = 0; i < len + 1; i++){
        
        if(buf[i]>='A' && buf[i]<='Z'){
          uppercase++;
          character++;
        }

        else if(buf[i]>='a' && buf[i]<='z'){
          lowercase++;
          character++;
        }

        else if(buf[i]>='0' && buf[i]<='9'){
          digit++;
          character++;
        }

        else if(buf[i] == '\t'){
          whitespace++;
          character++;
        }
        
        else if(buf[i] == ' '){
          whitespace++;
          word++;
          character++;
        }

        else if(buf[i] == '\n'){
          line++;
          word++;
          character++;
        }
      }
    }



    
    character++;
    len=0;


    
  }



    
  while (len > 0);



  
  printf("%d %d %d %d %d %d %d\n", character, word, line, 
 whitespace, uppercase, lowercase, digit);
}
