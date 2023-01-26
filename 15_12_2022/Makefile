all: main.out rooms.out

main.out: main.c quadraticRoots.o
	gcc main.c quadraticRoots.o -lm -o main.out

quadraticRoots.o: quadraticRoots.c quadraticRoots.h
	gcc -c quadraticRoots.c -o quadraticRoots.o

rooms.out: rooms.c
	gcc rooms.c -o rooms.out

clean:
	rm -f *.out *.o