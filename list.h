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

struct Element                 
{
  void *data;                    
  struct Element *next;       
};

struct List                    
{
  struct Element *head;
  struct Element *tail;
  int size;
};

size_t list_size(void);
int list_count(void);
struct List* list_new(void);          
void list_add(void *data, struct List *list);    
void list_remove(void *data, struct List *list); 
void list_destroy(struct List *list);
void list_print(struct List *list);

#endif	/* LIST_H */

