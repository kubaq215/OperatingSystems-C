CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -O -fPIC
LDFLAGS = -lm

b: b.o a.o
	$(CC) $(CFLAGS) -o b b.o a.o $(LDFLAGS)
c: c.o a.o
	$(CC) $(CFLAGS) -o c c.o a.o $(LDFLAGS)
d: d.o a.o
	$(CC) $(CFLAGS) -o d d.o a.o $(LDFLAGS)
e: e.o a.o
	$(CC) $(CFLAGS) -o e e.o a.o $(LDFLAGS)

a.o: a.c
	$(CC) $(CFLAGS) -c a.c
b.o: b.c a.h
	$(CC) $(CFLAGS) -c b.c
c.o: c.c a.h
	$(CC) $(CFLAGS) -c c.c
d.o: d.c a.h
	$(CC) $(CFLAGS) -c d.c
e.o: e.c a.h
	$(CC) $(CFLAGS) -c e.c

.PHONY: clean
clean:
	rm -f *.o