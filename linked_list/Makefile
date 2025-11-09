CC=gcc
CFLAGS=-Wall -ggdb

list.o: list.c
	$(CC) $(CFLAGS) -c $< -o $@

example: list.o
	$(CC) $< example.c -o $@

clean:
	rm -rf list.o example
