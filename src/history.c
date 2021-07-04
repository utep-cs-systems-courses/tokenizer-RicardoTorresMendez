#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/* Initialize the linked list to keep the history. */

List* init_history(){
  List *history = malloc( sizeof(List) );

  history->root = NULL;

  return history;
}



/* Add a history item to the end of the list.

   List* list - the linked list

   char* str - the string to store

*/

void add_history(List *list, char *str){
  //create the new item to contain the string
  Item *item = (Item*) malloc( sizeof( Item ) );
  item->str = str;
  item->next = NULL;

  if( list->root == NULL ){//special case for adding the first ellement
    item->id = 0;
    list->root = item;
    return;
  }
  
  Item *temp = list->root;
  int id = 1;
  while( temp->next != NULL ){//get to the end of the list
    temp = temp->next;
    id++;
  }
  item->id = id;
  temp->next = item;
}



/* Retrieve the string stored in the node where Item->id == id.

   List* list - the linked list

   int id - the id of the Item to find */

char *get_history(List *list, int id){
  Item *temp = list->root;
  while( temp != NULL ){
    if( temp->id == id ){ return temp->str; }
    temp = temp->next;
  }
  return NULL;
}



/* Print the entire contents of the list. */

void print_history(List *list){
  Item *temp = list->root;
  while( temp != NULL ){
    printf("%d ", temp->id );
    printf("%s", temp->str );
    printf("%s", "\n"); 
    temp = temp->next;
  }
}



/* Free the history list and the strings it references. */

void free_history(List *list){
  Item *temp;
  while( list->root != NULL ){
    temp = list->root;
    list->root = list->root->next;
    free(temp);
  }
}

