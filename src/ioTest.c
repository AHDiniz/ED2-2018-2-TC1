// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// main.c: program's entry point

#include <stdio.h>

#include "../include/tspio.h"
#include "../include/point.h"

int main(int argc, char *argv[])
{
    char name[20];
    int dimension;
    Point **p;

    dimension = TSPIO_ReadEntry(argv[1], name, p);

    printf("name = %s\n", name);
    printf("dim = %d\n", dimension);

    return 0;
}
