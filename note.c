#include <stdlib.h>
#include <string.h>
#include "note.h"

char *note_colors[] = {
  "#FFFF9C",
  "#9CFFCE",
  "#9C9CFF",
  "#FF9CCE"
};

size_t note_size(void)
{
    return sizeof(Note);
}

Note* note_new(char *text, int x, int y, int h, int w, const char *color)
{
    Note *note = malloc(sizeof(Note));
    strncpy(note->text, text, strlen(text));
    strncpy(note->color, color, strlen(color));
    note->x = x;
    note->y = y;
    note->h = h;
    note->w = w;
    return note;
}

void note_print(Note *note) 
{
    printf("%s\n", note->text);
    printf("(%d, %d, %dx%d)\n", note->x, note->y, note->h, note->w);
    printf("%s", note->color);
}
