#include<stdlib.h>
#include<stdio.h>
#include "list.h"

size_t list_size(void)
{
    return sizeof(List);
}

List* list_new(void)
{
    List *list = malloc(list_size());

    list->size = 0;
    list->head = NULL;
    
    return list;
}

void list_add(void *data, List *list)
{
    Element *element = malloc(sizeof(Element));
    element->data = data;
    
    element->next = list->head;
    list->head = element;  
    list->size++;
}

Element* list_pop(List *list) 
{
    if (list->head == NULL) {
	return NULL;
    } 
    
    Element *cur = list->head;
    list->head = cur->next;
    list->size--;
    return cur;	
}

Element* list_peek(List *list) 
{
    return list->head;
}

void list_destroy(List *list)
{
    Element *curr = list->head;
    while(curr != NULL) 
    {
        Element *temp = curr;
        curr = curr->next;
	printf("Freeing data %p\n", temp->data);
	free(temp->data);
	printf("Freeing %p\n", temp);
        free(temp);
    }
    free(list);
}
