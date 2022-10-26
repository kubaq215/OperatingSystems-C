CC = gcc
CFLAGS = -Wall -std=c99 -pedantic

all: a b c

a: a.c
	$(CC) $(CFLAGS) -o a.x a.c
b: b.c
	$(CC) $(CFLAGS) -o b.x b.c
c: c.c
	$(CC) $(CFLAGS) -o c.x c.c


.PHONY: clean
clean:
	rm -f *.o