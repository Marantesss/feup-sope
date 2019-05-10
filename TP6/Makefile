CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic

all: p1 p2

p1: p1.c
	$(CC) $(CFLAGS) -o p1.o p1.c -lpthread

p2: p2.c
	$(CC) $(CFLAGS) -o p2.o p2.c -lpthread

clean:
	rm -f *.o *.d