CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -std=c99

.PHONY: all test clean

all: main

main: main.o juegodelavida.o
	$(CC) main.o main.o -o main

main.o: main.c juegodelavida.h
	$(CC) -c main.c

juegodelavida.o: juegodelavida.c juegodelavida.h
	$(CC) -c juegodelavida.c

clean:
	rm *.o
rm main