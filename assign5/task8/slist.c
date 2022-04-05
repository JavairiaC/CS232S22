#include <stdio.h>
#include "snode.h"
#include "slist.h"
#include <string.h>
#include <stdlib.h>




/**
 * Allocates new slist dynamically.
 * 
 * @return pointer to the list
 */
struct slist *slist_create(){
  struct slist *list;
  list = (struct slist*)malloc(sizeof(struct slist));
  list->front = NULL;
  list->back = NULL;
  return list;
}

/** 
 * Inserts new node in slist after the last node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_back(struct slist *l, char *str){
  struct snode *node = snode_create(str);
  if (l->front == NULL){
    l->front = node;
    l->back = node;
    return node;
  } 

  l->back->next = node;
  l->back = node;
  return node;
}

/** 
 * Inserts new node in slist before the first node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_front(struct slist *l, char *str){
  struct snode *node = snode_create(str);
  if (l->front == NULL){
    l->front = node;
    l->back = node;
    return node;
  } 
  node->next = l->front;
  l->front = node;
  return node;
}

/**
 * Returns the first snode with the given string.
 *  
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 * @return struct snode* or NULL if no match
 */
struct snode* slist_find(struct slist *l, char *str){
  struct snode *front = l->front;
  while(front != NULL){
    if(strcmp(front->str, str) == 0){
      return front;
    } 
    front = front->next;
  }
  return NULL;
}

/**
 * Deallocate a list and all snodes
 *
 * @param l pointer tot he list
 */
void slist_destroy(struct slist *l){

  struct snode *front = l->front;
  while(front->next != NULL){
    snode_destroy(front);
    front = front->next;
    }
  free(l);
  
}
/**
 * Traverse the list and print the content of each node.
 *
 * @param l pointer to the list (non-NULL)
 */
void slist_traverse(struct slist *l){

  struct snode *front = l->front;
  while(front != NULL){
    printf("%s\n", front->str);
    front = front->next;
    }
  
}

/**
 * Returns the number of elements in the list (nodes).
 *
 * @param l pointer to the list (non-NULL)
 */
uint32_t slist_length(struct slist *l){
  uint32_t count = 0;
  struct snode *front = l->front;
  while(front != NULL){
      count++;
      front = front->next;
    }
  return count;
}
/**
 * Deletes the first snode with the given string.
 *  
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 */
void slist_delete(struct slist *l, char *str){
  struct snode *node = l->front;
  struct snode *previous;
  if (node != NULL && strcmp(node->str, str) == 0) {
        l->front = node->next; 
        snode_destroy(node); 
    }
  while (node != NULL && strcmp(node->str, str) != 0) {
        previous = node;
        node = node->next;
    }
  previous->next = node->next;
  snode_destroy(node);
}
