CC = gcc
CFLAGS = -Wall -std=c99 -pedantic

all: konsument producent p5

konsument: konsument.c
	$(CC) $(CFLAGS) -o konsument.x konsument.c
producent: producent.c
	$(CC) $(CFLAGS) -o producent.x producent.c
p5: p5.c
	$(CC) $(CFLAGS) -o p5.x p5.c


diff:
	diff -s in.txt out.txt


.PHONY: clean
clean:
	rm -f *.o