CC = gcc
CFLAGS = -Wall -std=gnu99 -pedantic -pthread
LFLAGS = -lrt

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< 
%.o: %.c
	$(CC) $(CFLAGS) -c $< 

.PHONY: all

all: p7s.x producents.x konsuments.x p7d1.x producentd1.x konsumentd1.x p7d2.x producentd2.x konsumentd2.x

SNEAKY = biblioteka.o biblioteka2.o
LIB = ./lib

MojeFunkcje.so: $(SNEAKY)
	$(CC) -shared -o $@ $(CFLAGS) $(SNEAKY) $(LFLAGS)
	mkdir -p $(LIB)
	mv MojeFunkcje.so $(LIB)

MojeFunkcje.a: $(SNEAKY)
	ar rsv $@ $?
	mkdir -p $(LIB)
	mv MojeFunkcje.a $(LIB)



# Statyczna
p7s.x: p7.o MojeFunkcje.a
	$(CC) -o $@ $(CFLAGS) p7.o $(SNEAKY) -L$(LIB) $(LFLAGS)
producents.x: producent.o MojeFunkcje.a
	$(CC) -o $@ $(CFLAGS) producent.o $(SNEAKY) -L$(LIB) $(LFLAGS)
konsuments.x: konsument.o MojeFunkcje.a
	$(CC) -o $@ $(CFLAGS) konsument.o $(SNEAKY) -L$(LIB) $(LFLAGS)

# Ta druga
p7d1.x: p7.o MojeFunkcje.so
	$(CC) -o $@ $(CFLAGS) p7.o -L$(LIB) $(SNEAKY) $(LFLAGS) -Wl,-R  $(LIB)

producentd1.x: producent.o MojeFunkcje.so
	$(CC) -o $@ $(CFLAGS) producent.o  -L$(LIB) $(SNEAKY) $(LFLAGS) -Wl,-R  $(LIB)

konsumentd1.x: konsument.o MojeFunkcje.so
	$(CC) -o $@ $(CFLAGS) konsument.o  -L$(LIB) $(SNEAKY) $(LFLAGS) -Wl,-R  $(LIB)

p7d2.x: p7.o MojeFunkcje.so
	$(CC) -o $@ $(CFLAGS) p7.o -L$(LIB) $(SNEAKY) $(LFLAGS)

producentd2.x: producent.o MojeFunkcje.so
	$(CC) -o $@ $(CFLAGS) producent.o  -L$(LIB) $(SNEAKY) $(LFLAGS)

konsumentd2.x: konsument.o MojeFunkcje.so
	$(CC) -o $@ $(CFLAGS) konsument.o  -L$(LIB) $(SNEAKY) $(LFLAGS)

main.o: biblioteka.h biblioteka2.h
producent.o: biblioteka.h biblioteka2.h
konsument.o: biblioteka.h biblioteka2.h


.PHONY: run1 run2 run3


run1: p7s.x producents.x konsuments.x
	./p7s.x producents.x konsuments.x in.txt
run2: p7d1.x producentd1.x konsumentd1.x
	./p7d1.x producentd1.x konsumentd1.x in.txt
run3: p7d2.x producentd2.x konsumentd2.x
	./p7d2.x producentd2.x konsumentd2.x in.txt



.PHONY: clean compare
clean:
	rm -f *.o *.x *.a *.so; rm -rf ${LIB}

compare:
	diff -s in.txt out.txt







