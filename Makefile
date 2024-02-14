SRC = $(wildcard *.c)

all:
	gcc -o bin $(SRC)
