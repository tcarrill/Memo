/* 
 * File:   note.h
 * Author: thomas
 *
 * Created on February 23, 2015, 8:46 PM
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef NOTE_H
#define	NOTE_H

extern char *note_colors[];

typedef struct Note {
  char text[2048];
  int x, y, h, w;
  char color[7];
} Note;

size_t note_size(void);
Note* note_new(char *text, int x, int y, int h, int w, const char *color);
void note_print(Note *note);

#endif	/* NOTE_H */

