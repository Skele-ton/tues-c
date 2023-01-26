taskManager.out: taskManager.c processes.o
	gcc taskManager.c processes.o -o taskManager.out

processes.o: processes.c processes.h
	gcc -c processes.c -o processes.o

clean:
	rm -f *.out *.o