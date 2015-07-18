all: pipes


pipes: pipes2.o
	gcc -o pipes pipes2.o

pipes1.o: pipes2.c
	gcc -c pipes2.c
clean:
	rm -rf *.o pipes
