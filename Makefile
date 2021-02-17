CC = g++
CFLAGS = -g -Wall

BoggleSolve: main.o Solver.o Board.o Dictionary.o
	$(CC) $(CFLAGS) -o BoggleSolve main.o Solver.o Board.o Dictionary.o

main.o: main.cpp Board.h Dictionary.h Solver.h
	$(CC) $(CFLAGS) -c main.cpp

Solver.o: Solver.cpp Solver.h Dictionary.h
	$(CC) $(CFLAGS) -c Solver.cpp

Board.o: Board.cpp Board.h Dictionary.h
	$(CC) $(CFLAGS) -c Board.cpp

Dictionary.o: Dictionary.cpp Dictionary.h
	$(CC) $(CFLAGS) -c Dictionary.cpp

clean:
	rm -f BoggleSolve main.o Solver.o Dictionary.o Board.o Dictionary.o

format:
	clang-format -i *.cpp *.h
