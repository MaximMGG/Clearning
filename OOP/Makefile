# TRGET = string
# CC = gcc
#
# SRC = $(wildcard *.c)
# OBJ = $(patsubst %.c, %.o, $(SRC))
#
# $(TARGET) : $(OBJ)
# 	$(CC) $(OBJ) -o $(TARGET)
#
# $(OBJ) : $(SRC)
# 	$(CC) -c $<  -o
#
# clean :
# 	rm *.o $(TARGET)

run: testString.o my_string.o
	gcc testString.o my_string.o -o run

debug.out: testString.o my_string.o
	gcc testString.o my_string.o -g

testString.o: testString.c
	gcc -c testString.c 

my_string.o: my_string.c my_string.h
	gcc -c my_string.c 

clean: 
	rm *.o run
