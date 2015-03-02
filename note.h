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

struct Note;

size_t note_size(void);
struct Note* note_new(char *text, int x, int y, int h, int w, int r, int g, int b);
void note_print(struct Note *note);

#endif	/* NOTE_H */

