#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    //TODO:copy setup func from previous task
  //TODO:head declared for you
    //Allocate three more pointers
    //head for the first Node, and temporary pointers node1, node2 and node3
  //Allocate three node pointees and store references to them in the three pointers
  //Dereference each pointer to store the appropriate number and string into the length and str fields in its pointee.
  //Dereference each pointer to access the .next field in its pointee, 
    //and use pointer assignment to set the .next field to point to the appropriate Node.
   node_t * head ;
    
  node_t* node1;
  node_t* node2;
   
  head = malloc(sizeof(struct snode));
  node1 = malloc(sizeof(struct snode));
  node2 = malloc(sizeof(struct snode));
    
  strcpy(head->str, "hello");
  head->length = 5;

  strcpy(node1->str, "there");
  head->length = 5;

  strcpy(node2->str, "prof");
  head->length = 4;
  
    
  head->next = node1;
  node1->next = node2;
  node2->next = NULL;
    
   return head;
}

void teardown(node_t *head) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
   node_t *n;
  while(NULL != head){
    n = head->next;
    free(head);
    head = n;
  }
}

void add(node_t ** head, char * str, int length){
    //TODO: implement add to add a new node to front, pointed by head
  node_t* newNode = malloc(sizeof(struct snode));
  strcpy(newNode->str, str);
  newNode->length = length;
  newNode->next = *head;
  *head = newNode;
}

void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    dump_all(head);
    teardown(head);
    return 0;
}

void dump_all(node_t * head) {
    printf("head -> ");
    node_t * cur = head;
    while(cur != NULL) {
        printf("%s ", cur->str);
	cur = cur->next;
    }
    printf("\ndone\n ");
}
