all: p1 p2 p3 p4 p5 p6 p7 p8

p1: p1a.c p1b.c p1c.c
	gcc -Wall -o p1a p1a.c
	gcc -Wall -o p1b p1b.c
	gcc -Wall -o p1c p1c.c


p2: p2.c
	gcc -Wall -o p2 p2.c

p3: p3.c
	gcc -Wall -o p3 p3.c

clean:
	rm -f p1a
	rm -f p1b
	rm -f p1c
	rm -f p2
	rm -f p3

