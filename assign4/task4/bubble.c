/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */
#include <stdlib.h>

#define NUM 30   /* number of strings */
#define LEN 1200  /* max length of each string */

void swap(char **x, char **y);
void bubbleSort(char *strs[], int size);
int myStrCmp(char * one, char * two);

int main()
{
  char * Strings[NUM];
  char *str;
  //printf("Please enter %d strings, one per line:\n", NUM);

  //gets strings
  for (int i = 0; i < NUM; i++)
    {
      Strings[i] = (char *)malloc(LEN * sizeof(char));
      fgets (Strings[i], LEN, stdin);
      str = Strings[i];
      long length = strlen(str) + 1;
      Strings[i] = (char *)realloc(Strings[i], length * sizeof(char));
    }

  /*
  puts("\nHere are the strings in the order you entered:");

  
  //prints strings out
  for (int i = 0; i < NUM; i++)
    {
      printf("%s", Strings[i]);
    }
  
  puts("\nIn alphabetical order, the strings are:"); 
  */

  
  //sorts array
bubbleSort(Strings, NUM);
  //print sorted list
  for (int i = 0; i < NUM; i++)
    {
      printf("%s", Strings[i]);
    }

  //frees memory
  for(int i = 0; i < NUM; i++)
    free(Strings[i]);
}


//swapping the strings
void swap(char **x, char **y){
    char * temp = *x;
    *x = *y;
    *y = temp;
}


//making my own comparison function
int myStrCmp(char * one, char * two){
  long len1, len2, shorter;

  len1 = strlen(one);
  len2 = strlen(two);

  if(len1 >= len2) 
    shorter = len2;
  else 
    shorter = len1;
  
  for (int i = 0; i < shorter; i++){
    if (one[i] > two[i]){
      //returns 1 if str2 comes first alphabetically
      return 1;
    }
    else if(one[i] < two[i]){
      //returns -1 if str1 comes first alphabetically
      return -1;
    }
  }
  return 1;
}


//myStrCmp(str1, str2) if its 1, then swap
void bubbleSort(char * strs[], int size) {
   for (int i = 0; i < size-1; i++){
       // Last i elements are already in place   
       for (int j = 0; j < size-i-1; j++) {
          if (myStrCmp(strs[j], strs[j+1]) == 1){
             swap(&strs[j], &strs[j+1]);
           }
       }   
  }
}
