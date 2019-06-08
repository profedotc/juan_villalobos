CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -std=c99

.PHONY: all test clean

all: juegodelavida

juegodelavida: main.o juegodelavida.o
	$(CC) main.o juegodelavida.o -o juegodelavida

main.o: main.c juegodelavida.h
	$(CC) -c main.c

juegodelavida.o: juegodelavida.c juegodelavida.h
	$(CC) -c juegodelavida.c

clean:
	rm *.o
rm juegodelavida