# Project's makefile
#
# Alan Herculano Diniz
# Rafael Belmock Pedruzzi
#
# Project's makefile

CC = gcc

CFLAGS = -Wall -Wextra -O2 -lm -g

CFLAGS_OPT = -Wall -Wextra -O3 -lm -g

SRC = src/

BIN = bin/

PROBLEM = tsp225

IN = ../assets/in

PLOT = ./tsp_plot.py

MST = out/mst

TOUR = out/tour

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

opt: $(SRC)main.c $(SRC)edge.c $(SRC)point.c $(SRC)tspio.c
	$(CC) -o $(BIN)trab1_opt $^ $(CFLAGS_OPT)

clean:
	rm *.o

debug: $(BIN)trab1
	cd $(BIN) && gdb --args trab1 $(IN)/$(PROBLEM).tsp && cd ..

memcheck: $(BIN)trab1
	cd $(BIN) && valgrind ./trab1 $(IN)/$(PROBLEM).tsp && cd ..

memcheckopt: opt
	cd $(BIN) && valgrind ./trab1_opt $(IN)/$(PROBLEM).tsp && cd ..

run: $(BIN)trab1
	cd $(BIN) && ./trab1 $(IN)/$(PROBLEM).tsp && cd ..

runopt: 
	cd $(BIN) && ./trab1_opt $(IN)/$(PROBLEM).tsp && cd ..

visualize: $(BIN)trab1
	$(PLOT) assets/in/$(PROBLEM).tsp $(MST)/$(PROBLEM).mst $(TOUR)/$(PROBLEM).tour

visualizeopt: $(BIN)trab1
	$(PLOT) assets/in/$(PROBLEM).tsp $(MST)/$(PROBLEM).mst assets/opt/$(PROBLEM).opt.tour
