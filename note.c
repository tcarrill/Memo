#include <stdlib.h>
#include<string.h>
#include "note.h"
 
struct Note {
    char text[2048];
    int x, y, h, w;
    int r, g, b;
};
 
size_t note_size(void)
{
    return sizeof(struct Note);
}

struct Note* note_new(char *text, int x, int y, int h, int w, int r, int g, int b)
{
    struct Note *note = malloc(note_size());
    strcpy(note->text, "Sample Text");
    note->x = x;
    note->y = y;
    note->h = h;
    note->w = w;
    note->r = r;
    note->g = g;
    note->b = b;
    
    return note;
}

void note_print(struct Note *note) 
{
    printf("%s\n", note->text);
    printf("(%d, %d, %dx%d)\n", note->x, note->y, note->h, note->w);
    printf("[%d, %d, %d]", note->r, note->g, note->b);
}
