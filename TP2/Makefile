all: p1

p1: p1.c
	gcc -Wall -o p1 p1.c

p2a: p2a.c
	gcc -Wall -o copy p2a.c

# same as p2a but with system calls
p2b: p2b.c
	gcc -Wall -o copy_sc p2b.c

p3a: p3a.c
	gcc -Wall -o p3a p3a.c

clean:
	rm -f p1
	rm -f copy
	rm -f copy_sc
	rm -f p3a

