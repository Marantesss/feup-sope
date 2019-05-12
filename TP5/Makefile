CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic
TARGET=p1a p1b p1c

all: p1 p2 p6 p7

p1: p1a.c p1b.c p1c.c
	$(CC) $(CFLAGS) -o p1a.o p1a.c
	$(CC) $(CFLAGS) -o p1b.o p1b.c
	$(CC) $(CFLAGS) -o p1c.o p1c.c

p2: p2.c
	$(CC) $(CFLAGS) -o p2.o p2.c

p6: p6_reader.c p6_writer.c
	$(CC) $(CFLAGS) -o p6_reader.o p6_reader.c
	$(CC) $(CFLAGS) -o p6_writer.o p6_writer.c

p7: p7_client.c p7_server.c
	$(CC) $(CFLAGS) -o p7_client.o p7_client.c
	$(CC) $(CFLAGS) -o p7_server.o p7_server.c

clean:
	rm -f $(TARGET) *.o *.d