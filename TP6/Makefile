CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic

all: p1 p2 p3 p4

p1: p1.c
	$(CC) $(CFLAGS) -o p1.o p1.c -lpthread

p2: p2.c
	$(CC) $(CFLAGS) -o p2.o p2.c -lpthread

p3: p3.c
	$(CC) $(CFLAGS) -o p3.o p3.c -lpthread

p4: p4.c
	$(CC) $(CFLAGS) -o p4.o p4.c -lpthread

clean:
	rm -f *.o *.d