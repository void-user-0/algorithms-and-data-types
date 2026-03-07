#CC=x86_64-w64-mingw32-gcc
CC=gcc # default compiler linux, change the compiler to mingw if you need a windows file! 
# [example compiler mingw from linux -> x86_64-w64-mingw32-gcc, mingw from windows -> path to mingw compiler]

linked_list.o: linked_list.c
	$(CC) -c $< -o $@

example: linked_list.o
	$(CC) $< example.c -o $@

clean:
	rm -rf linked_list.o example
