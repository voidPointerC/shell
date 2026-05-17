CC = clang -std=c17

SRC = main.c inputHandler.c

all:
	$(CC) $(SRC) -o main
