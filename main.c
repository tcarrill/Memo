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

#define BLUE 0;
#define YELLOW 1;
#define GREEN 2;
#define PINK 3;
#define PURPLE 4;
#define GREY 5;

const int COLORS[6][3] = {
    {173, 244, 255},
    {254, 244, 156},
    {177, 253, 160},
    {252, 197, 197},
    {182, 202, 255},
    {238, 238, 238}
};

void print_menu() 
{
    printf("\nChoose an option\n");
    printf("[c] Create a new note\n");
    printf("[p] Print all notes\n");
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

struct Note* random_note(char *text) 
{
    int x = rand_lim(1920);
    int y = rand_lim(1080);
    int h = rand_lim(300);
    int w = rand_lim(500);

    int index = rand_lim(5);
      
    return note_new(text, x, y, h, w, COLORS[index][0], COLORS[index][1], COLORS[index][2]);
}

void list_print(struct List *list) 
{
    struct Element *curr = list->head;
    while(curr != NULL) 
    {
        printf("\n%p\n", curr);
        note_print(curr->data);
        printf("\n");
        curr = curr->next;
    }
}

void write_notes(struct List *list) 
{
    FILE *file= fopen("notes.memo", "wb");
    if (file != NULL) 
    {
        struct Element *curr = list->head;
        while(curr != NULL) 
        {    
            struct Note *note = curr->data;
            fwrite(note, note_size(), 1, file);
            curr = curr->next;
        }
        
        fclose(file);
    }
}

void read_notes(struct List *list) 
{
    FILE *file= fopen("notes.memo", "rb");
    
    if (file != NULL) {
        struct Note *note = malloc(note_size());
        while(fread(note, note_size(), 1, file))
        {
            list_add(note, list);
        }
        
        fclose(file);
    }
}

int main(int argc, char **argv) {
    struct List *list = list_new();
    read_notes(list);
    char input;
    while (input != 'q') 
    {
        print_menu();
        printf("> ");
        scanf(" %c",&input);
        if (input == 'c') {
            struct Note *note = random_note(NULL);
            list_add(note, list);
        } else if (input == 'p') {
            list_print(list);
        } else if (input == 'w') {
            write_notes(list);
        } else if (input == 'q') {
            list_destroy(list);
        }
    }
  
    return (EXIT_SUCCESS);
}