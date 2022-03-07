#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int value; //this is the value the node stores
    struct node* next;//this is the node the current node points to. this is how the nodes link
} node_t;

node_t * construct_3() {
  //Allocate three pointers:  
  //x for the first Node, and temporary pointers y and z for the other two Nodes.
   node_t *x;
   node_t *y;
   node_t *z;

    //Allocate three Node pointees and store     references to them in the three pointers.
    x = malloc(sizeof(struct node));
    y = malloc(sizeof(struct node));
    z = malloc(sizeof(struct node));
  
   //Dereference each pointer to store the appropriate number into the value field in its pointee.

    //Dereference each pointer to access the .next field in its pointee, 
  
    //and use pointer assignment to set the .next field to point to the appropriate Node. 

   x -> value = 1;
   y -> value = 2;
   z -> value = 3;
  
   x -> next = y;
   y -> next = z;
   z -> next = x;

   return x;

  
    
    
    

  
  

   

}

//You can ignore the following code for testing
int dump_all(node_t*);
int main (int argc, char ** argv) {

    node_t * x = construct_3();
    return dump_all(x);

}

int dump_all(node_t * x) {
    printf("x -> %d\n", x->value);
    node_t * y = x->next;
    printf("%d -> %d\n", x->value, y->value);
    node_t * z = y->next;
    printf("%d -> %d\n", y->value, z->value);
    if(z->next != x) {
    	printf("failed");
      free(x);
      free(y);
      free(z);
      
	return -1;
    } else {
        printf("%d -> %d\n", z->value, x->value);
      free(x);
      free(y);
      free(z);
        return 0;
    }
}
