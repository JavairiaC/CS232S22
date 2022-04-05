#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>

struct snode *snode_create(char *s) 
{
  struct snode *node;
 //TODO: implement snode_create, change the prototype to
 //match with header file
  node = (struct snode*)malloc(sizeof(struct snode));
  node->str = (char *)malloc(sizeof(char)*strlen(s) + 1);
  strcpy(node->str, s);
  node->next = NULL;
  return node;
}
void snode_destroy(struct snode * s) 
{
  //s->str = NULL;
  //s = NULL;
  free(s->str);
  free(s);
 //TODO: implement snode_destroy
 
};
 
