CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -O -fPIC

p2: p2.o
	$(CC) $(CFLAGS) -o p2.x p2.o
wypisz: wypisz.o
	$(CC) $(CFLAGS) -o wypisz.x wypisz.o 

p2.o: p2.c
	$(CC) $(CFLAGS) -c p2.c
wypisz.o: wypisz.c 
	$(CC) $(CFLAGS) -c wypisz.c

.PHONY: run1

run1: p2.x
	./p2.x ./wypisz.x wypisz

.PHONY: clean
clean:
	rm -f *.o