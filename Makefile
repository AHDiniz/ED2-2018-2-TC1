# Project's makefile
#
# Alan Herculano Diniz
# Rafael Belmock Pedruzzi
#
# Project's makefile

CC = gcc

CFLAGS = -Wall -Wextra -O2 -lm

SRC = src/

BIN = bin/

all: $(BIN)trab1

$(BIN)trab1: main.o edge.o point.o tspio.o
	$(CC) -o $@ $^ $(CFLAGS)

main.o: $(SRC)main.c
	$(CC) -c $^ $(CFLAGS)

edge.o: $(SRC)edge.c
	$(CC) -c $^ $(CFLAGS)

point.o: $(SRC)point.c
	$(CC) -c $^ $(CFLAGS)

tspio.o: $(SRC)tspio.c
	$(CC) -c $^ $(CFLAGS)

clean:
	rm *.o
