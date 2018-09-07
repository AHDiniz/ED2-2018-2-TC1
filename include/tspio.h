// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// tspio.h: input and output header file

#ifndef MSTIO_H_

#define MSTIO_H_

#include "../include/point.h"

/**
 * Declaring the function that reads the input file:
 * Inputs: the file's name, a string and a integer pointer
 * Output: arrey of pointers to the cartisian points
 * Conditions: string allocated, file of type TSP
 * Side effects: the arrey is dynamically alocated, name receive the problem's name and dimension receive the problem's dimension
*/
Point **TSPIO_ReadEntry(char *filename, char *name, int *dimension);

/**
 * Declaring the function that destroy the arrey criated in TSPIO_ReadEntry:
 * Inputs: pointer to the arrey and it's size
 * Outputs: none
 * Conditions: arrey exist
 * Side effects: arrey is destroied
*/
void TSPIO_DestroyArrey(Point **p, int n);

#endif
