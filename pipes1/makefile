all: pipes


pipes: pipes1.o
	gcc -o pipes pipes1.o

pipes1.o: pipes1.c
	gcc -c pipes1.c
clean:
	rm -rf *.o pipes
