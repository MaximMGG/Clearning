prog: oop.o my_string.o
	gcc oop.c my_string.c
oop.o: oop.c my_string.c
	gcc -c oop.c
my_string.o: my_string.c my_string.h
	gcc -c my_string.c
