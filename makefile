CC = g++
CFLAGS = -g -Wall -O0


main.o: main.cpp solver.h dictionary.h
	$(CC) $(CFLAGS) -c main.cpp

solver.o: solver.cpp dictionary.h
	$(CC) $(CFLAGS) -c solver.cpp

dictionary.o: dictionary.cpp dictionary.h
	$(CC) $(CFLAGS) -c dictionary.cpp

BoggleSolve: main.o solver.o dictionary.o
	$(CC) $(CFLAGS) -o BoggleSolve main.o solver.o dictionary.o

all: BoggleSolve

clean:
	rm -f BoggleSolve main.o solver.o dictionary.o
