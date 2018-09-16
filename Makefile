# Project's makefile
#
# Alan Herculano Diniz
# Rafael Belmock Pedruzzi
#
# Project's makefile

CC = gcc

CFLAGS = -Wall -Wextra -O2

SRC = src/

BIN = bin/

all: trab1

$(BIN)trab1: main.o edge.o point.o tspio.o
	$(CC) -o $@ $^ $(CFLAGS)

$(BIN)main.o: $(SRC)main.c
	$(CC) -c $^

$(BIN)edge.o: $(SRC)edge.c
	$(CC) -c $^

$(BIN)point.o: $(SRC)point.c
	$(CC) -c $^

$(BIN)tspio.o: $(SRC)tspio.c
	$(CC) -c $^

clean:
	rm *.o
