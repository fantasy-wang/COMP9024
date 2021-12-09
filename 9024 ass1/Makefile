

CC=dcc
CFLAGS=-c
all: puzzle

puzzle: boardADT.o puzzle.o

boardADT.o: boardADT.c boardADT.h
	$(CC) $(CFLAGS) boardADT.c

puzzle.o: puzzle.c boardADT.h
	$(CC) $(CFLAGS) puzzle.c

clean:
	rm -f puzzle *.o core *.gch