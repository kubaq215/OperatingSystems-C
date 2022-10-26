CC=gcc
CFLAGS=-ansi -O
LDFLAGS=-lm -o er

all: rekordy.o norm.o
	$(CC) $(CFLAGS) rekordy.o norm.o $(LDFLAGS) 

rekordy.o: rekordy.c norm.h
	$(CC) $(CFLAGS) -c rekordy.c

norm.o: norm.c
	$(CC) $(CFLAGS) -c norm.c

