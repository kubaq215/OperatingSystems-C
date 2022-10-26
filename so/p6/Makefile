CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -pthread

%.o: %.c
	$(CC) $(CFLAGS) -c $< 

.PHONY: all, run

all: p6.x procesy.x

p6.x: p6.o biblioteka.c
	$(CC) -o $@ $(CFLAGS) $^
procesy.x: procesy.o biblioteka.c
	$(CC) -o $@ $(CFLAGS) $^


run: p6.x procesy.x
	./p6.x


.PHONY: clean
clean:
	rm -f *.o *.x