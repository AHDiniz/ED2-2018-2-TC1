# Project's makefile
#
# Alan Herculano Diniz
# Rafael Belmock Pedruzzi
#
# Project's makefile

CC = gcc

CFLAGS = -Wall -Wextra -O3

SRC = src/

clean:
	rm *.o

listTest: $(SRC)list.c $(SRC)listTest.c
	$(CC) -o $@ $^ $(CFLAGS)
