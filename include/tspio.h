// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// tspio.h: input and output declarations

#ifndef MSTIO_H_

#define MSTIO_H_

#include "../include/point.h"

Point* TSPIO_ReadEntry(char* filename, char* name, int* dimension);

#endif
