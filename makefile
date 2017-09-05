CC = g++
CFLAGS = -g -Wall

all: BoggleSolve

BoggleSolve: main.o boggle.o dictionary.o
	$(CC) $(CFLAGS) -o BoggleSolve main.o boggle.o dictionary.o
	
main.o: main.cpp boggle.h dictionary.h
	$(CC) $(CFLAGS) -c main.cpp

boggle.o: boggle.cpp dictionary.h
	$(CC) $(CFLAGS) -c boggle.cpp

dictionary.o: dictionary.cpp dictionary.h
	$(CC) $(CFLAGS) -c dictionary.cpp

clean:
	rm -f BoggleSolve main.o boggle.o dictionary.o
