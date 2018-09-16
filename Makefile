# Project's makefile
#
# Alan Herculano Diniz
# Rafael Belmock Pedruzzi
#
# Project's makefile

CC = gcc

CFLAGS = -Wall -Wextra -O2 -lm -g

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

debug: $(BIN)trab1
	gdb --args $(BIN)trab1 ../assets/in/berlin52.tsp

memcheck: $(BIN)trab1
	valgrind $(BIN)trab1 ../assets/in/berlin52.tsp
