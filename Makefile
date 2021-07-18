CC = g++
CFLAGS = -g -Wall

srcdir = src

boggle: main.o Solver.o Board.o Dictionary.o
	$(CC) $(CFLAGS) -o boggle main.o Solver.o Board.o Dictionary.o

main.o: $(srcdir)/main.cpp $(srcdir)/Board.h $(srcdir)/Dictionary.h $(srcdir)/Solver.h
	$(CC) $(CFLAGS) -c $(srcdir)/main.cpp

Solver.o: $(srcdir)/Solver.cpp $(srcdir)/Solver.h $(srcdir)/Dictionary.h
	$(CC) $(CFLAGS) -c $(srcdir)/Solver.cpp

Board.o: $(srcdir)/Board.cpp $(srcdir)/Board.h $(srcdir)/Dictionary.h
	$(CC) $(CFLAGS) -c $(srcdir)/Board.cpp

Dictionary.o: $(srcdir)/Dictionary.cpp $(srcdir)/Dictionary.h
	$(CC) $(CFLAGS) -c $(srcdir)/Dictionary.cpp

clean:
	rm boggle *.o

format:
	clang-format -i $(srcdir)/*.cpp $(srcdir)/*.h

valgrind: boggle
	valgrind --leak-check=full --show-leak-kinds=all ./boggle
