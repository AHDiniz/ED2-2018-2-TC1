// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// tspio.h: input and output declarations

#ifndef MSTIO_H_

#define MSTIO_H_

#include "../include/point.h"

int TSPIO_ReadEntry(char *filename, char *name, Point *p[]);

void TSPIO_DestroyVector(Point *p[], int n);

#endif
