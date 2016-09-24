CC=gcc
CFLAGS=-I.
DEPS = list.h note.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

memo: note.o list.o main.o
	gcc -o memo list.o note.o main.o -I.

clean:
	rm -f *.o
