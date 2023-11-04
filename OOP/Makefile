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
