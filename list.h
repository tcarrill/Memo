/* 
 * File:   note_list.h
 * Author: thomas
 *
 * Created on February 26, 2015, 10:25 PM
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef LIST_H
#define	LIST_H

typedef struct Element                 
{
  void *data;                    
  struct Element *next;       
} Element;

typedef struct List                    
{
  Element *head;
  int size;
} List;

size_t list_size(void);
int list_count(void);
List* list_new(void);          
void list_add(void *data, List *list);    
Element* list_pop(List *list); 
Element* list_peek(List *list);
void list_destroy(List *list);
void list_print(List *list);

#endif	/* LIST_H */

