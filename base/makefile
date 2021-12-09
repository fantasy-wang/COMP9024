base2 : base2.o quack.o
	gcc -o base2 base2.o quack.o

base2.o : base2.c quack.h
	gcc -Wall -Werror -std=c11 -c base2.c

quack.o : quack.c quack.h
	gcc -Wall -Werror -std=c11 -c quack.c