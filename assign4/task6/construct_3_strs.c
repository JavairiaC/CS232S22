#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node {
    char * value; //must use dynamic allocation 
    struct node* next;
} node_t;

node_t * construct_3_strs() {
  node_t *x;
  node_t *y;
  node_t *z;

  
  
  x = malloc(sizeof(struct node));
  y = malloc(sizeof(struct node));
  z = malloc(sizeof(struct node));

  
  char * str1 = "CS232";
  char * str2 = "is";
  char * str3 = "awesome";
  
  x->value = malloc(sizeof(char) * strlen(str1));
  y->value = malloc(sizeof(char) * strlen(str2));
  z->value = malloc(sizeof(char) * strlen(str3));
  
  x->value = str1;
  y->value = str2;
  z->value = str3;
  
  
  
  x->next = y;
  y->next = z;
  z->next = x;

  //free(x->value);
  //free(y->value);
  //free(z->value);
 
   return x;//just to pass compiler, please edit as needed.
}

//You can ignore the following code for testing
int dump_all(node_t*);

int main (int argc, char ** argv) {
    node_t * x = construct_3_strs();
    return dump_all(x);

}

int dump_all(node_t * x) {
    printf("x -> %s", x->value);
    node_t * y = x->next;
    printf(" %s", y->value);
    node_t * z = y->next;
    printf(" %s\n", z->value);
    if(z->next != x) {
    	printf("failed");
      free(x);
      free(y);
      free(z);
      //free(x->value);
      //free(y->value);
      //free(z->value);

	return -1;
    } else {
      free(x);
     free(y);
     free(z);
     //free(x->value);
     //free(y->value);
     //free(z->value);
      
        return 0;
    }
}
