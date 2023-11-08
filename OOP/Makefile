TARGET = string
CC = gcc

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(OBJ) : $(SRC)
	$(CC) -c $< -o $@

clean :
	rm *.o $(TARGET)

test: testString.o my_string.o
	$(CC) testString.o my_string.o -o test

testString.o: testString.c
	$(CC) -c testString.c -o testString.o


