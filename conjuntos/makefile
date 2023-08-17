CFLAGS = -Wall -std=c17 -g -Wextra

CC = gcc

	objects = main.o conjuntos.o

all: main.o conjuntos.o
	$(CC) -o conjuntos main.o conjuntos.o

main.o: main.c
	$(CC) -c $(CFLAGS) main.c

conjuntos.o: conjuntos.c
	$(CC) -c $(CFLAGS) conjuntos.c

clean: 
	rm -f $(objects) conjuntos
