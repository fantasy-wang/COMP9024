matcher : matcher.o quack.o
	gcc -o matcher matcher.o quack.o

matcher.o : matcher.c quack.h
	gcc -Wall -Werror -std=c11 -c matcher.c

quack.o : quack.c quack.h
	gcc -Wall -Werror -std=c11 -c quack.c