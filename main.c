/* 
 * File:   main.c
 * Author: thomas
 *
 * Created on February 23, 2015, 8:42 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "note.h"

void print_menu() 
{
    printf("\nChoose an option\n");
    printf("[c] Create a new note\n");
    printf("[p] Print all notes\n");
    printf("[o] Pop a note\n");
    printf("[w] Write to file\n");
    printf("[q] Quit\n");
}

int rand_lim(int limit) {
    int divisor = RAND_MAX/(limit+1);
    int retval;

    do { 
        retval = rand() / divisor;
    } while (retval > limit);

    return retval;
}

Note* random_note(char *text) 
{
    int x = rand_lim(1920);
    int y = rand_lim(1080);
    int h = rand_lim(300);
    int w = rand_lim(500);
    return note_new(text, x, y, h, w, note_colors[rand() % 4]);
}

void list_print(List *list) 
{
    Element *curr = list->head;
    while(curr != NULL) 
    {
        printf("\n%p\n", curr);
        note_print(curr->data);
        printf("\n");
        curr = curr->next;
    }
}

void write_notes(List *list) 
{
    FILE *file= fopen("notes.memo", "wb");
    if (file != NULL) 
    {
        Element *curr = list->head;
        while(curr != NULL) 
        {    
            Note *note = curr->data;
            fwrite(note, sizeof(Note), 1, file);
            curr = curr->next;
        }
        
        fclose(file);
    }
}

void read_notes(List *list) 
{
    FILE *file = fopen("notes.memo", "rb");
    
    if (file != NULL) {
        while(!feof(file))
        {
	    Note *note = malloc(sizeof(Note));
            int read = fread(note, sizeof(Note), 1, file);
	    if (read == 1) {
	        list_add(note, list);
	    }
        }
        
        fclose(file);
    }
}

int main(int argc, char **argv) {
    List *list = list_new();
    read_notes(list);
    char input;
    while (input != 'q') 
    {
        print_menu();
        printf("> ");
        scanf(" %c",&input);
        if (input == 'c') {
            Note *note = random_note("Test");
            list_add(note, list);
        } else if (input == 'p') {
            list_print(list);
	} else if (input == 'o') {
	    Element *element = list_pop(list);
	    note_print(element->data);
	    printf("\n");
	    free(element->data);
	    free(element);
        } else if (input == 'w') {
            write_notes(list);
        } else if (input == 'q') {
            list_destroy(list);
        }
    }
  
    return (EXIT_SUCCESS);
}
