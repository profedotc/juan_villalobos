CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -std=c99

.PHONY: all test debug release clean

all: debug

release : CFLAGS += -O3
release : juegodelavida

debug : CFLAGS += -g -O0
debug : juegodelavida

juegodelavida: main.o juegodelavida.o
	$(CC) main.o juegodelavida.o -o juegodelavida

main.o: main.c juegodelavida.h
	$(CC) -c main.c

juegodelavida.o: gol.c juegodelavida.h
	$(CC) -c juegodelavida.c

clean:
	rm *.o
rm juegodelavida