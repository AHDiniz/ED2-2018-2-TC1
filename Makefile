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

PROBLEM = berlin52

IN = ../assets/in

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
	cd $(BIN) && gdb --args trab1 $(IN)/$(PROBLEM).tsp && cd ..

memcheck: $(BIN)trab1
	cd $(BIN) && valgrind ./trab1 $(IN)/$(PROBLEM).tsp && cd ..

run: $(BIN)trab1
	cd $(BIN) && ./trab1 $(IN)/$(PROBLEM).tsp && cd ..
