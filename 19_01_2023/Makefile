robot.out: robot.c bitState.o
	gcc robot.c bitState.o -o robot.out

bitState.o: bitState.c bitState.h
	gcc -c bitState.c -o bitState.o

clean:
	rm -f *.o *.out