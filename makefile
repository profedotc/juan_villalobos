CC = gcc $(CFLAGS)
CCWVAL = gcc $(VALGRINDFLAGS)
CFLAGS = -Wall -Wextra -std=c99
VALGRINDFLAGS = -leak-check=full

.PHONY: all test debug release clean run

all: exec

release : CFLAGS += -O3
release : gol

valgrind:
        valgrind ./mem_test

test: mem_test.o
	$(CCWVAL) mem_test.o
	valgrind ./mem_test

debug : CFLAGS += -g -O0
debug : gol

exec: main.o gol.o
	$(CC) main.o gol.o -o exec
main.o: main.c
	$(CC) -c main.c
gol.o: gol.h gol.c
	$(CC) -c gol.c
run: exec
	./exec
clean: clean
	rm main.o gol.o exec 
