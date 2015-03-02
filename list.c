#include<stdlib.h>
#include<stdio.h>
#include "list.h"

size_t list_size(void)
{
    return sizeof(struct List);
}

struct List* list_new(void)
{
    struct List *list = malloc(list_size());

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    
    return list;
}

void list_add(void *data, struct List *list)
{
    struct Element *element = malloc(sizeof(struct Element));
    element->data = data;
    
    if (list->head == NULL) {
        list->head = element;
    } else {
        list->tail->next = element;
    }
    
    element->next = NULL;  
    list->tail = element;
    list->size++;
}

void list_remove(void *data, struct List *list) 
{
    
}

void list_destroy(struct List *list)
{
    struct Element *curr = list->head;
    while(curr != NULL) 
    {
        printf("Freeing %p\n", curr);
        struct Element *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(list);
}