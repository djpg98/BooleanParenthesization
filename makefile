COMPILAR = gcc -c

LINKEAR = gcc

MAIN = main

OBJETOS = main.o booleanPar.o

.PHONY = all clean

all: $(MAIN)

clean:
	rm $(OBJETOS)
	rm $(MAIN)

booleanPar.o: booleanPar.c booleanPar.h
	$(COMPILAR) booleanPar.c -o booleanPar.o

$(MAIN): main.c $(OBJETOS)
	$(COMPILAR) main.c -o main.o
	$(LINKEAR) $(OBJETOS) -o $(MAIN)