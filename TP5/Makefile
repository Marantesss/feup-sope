CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic
TARGET=p1a p1b p1c

all: p1 p2

p1: p1a.c p1b.c p1c.c
	$(CC) $(CFLAGS) -o p1a.o p1a.c
	$(CC) $(CFLAGS) -o p1b.o p1b.c
	$(CC) $(CFLAGS) -o p1c.o p1c.c

p2: p2.c
	$(CC) $(CFLAGS) -o p2.o p2.c

clean:
	rm -f $(TARGET) *.o *.d