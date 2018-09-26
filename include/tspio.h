// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// tspio.h: input and output header file

#ifndef MSTIO_H_

#define MSTIO_H_

#include "../include/point.h"
#include "../include/edge.h"

/**
 * Declaring the function that reads the input file:
 * Inputs: the filename, the name of the problem and a pointer to the dimension of the problem
 * Output: array of pointers to the cartisian points
 * Conditions: the file must be an existent .tsp file
 * Side effects: the array is DYNAMICALLY alocated, REMEMBER TO DESTROY IT LATER!!!
*/
Point *TSPIO_ReadEntry(char *filename, char *name, int *dimension);

/**
 * Declaring the function that prints the MST file:
 * Inputs: array of edges, the problem's name and the problem's dimension
 * Outputs: none
 * Conditions: existent and allocated array, the name and the dimension must be valid
 * Side effects: a .mst file is created
*/
void TSPIO_PrintMST(Edge **edges, char *name, int dimension);

/**
 * Declaring the function that prints the tour file:
 * Inputs: array of nodes(integers), the problem's name and the problem's dimension
 * Outputs: none
 * Conditions: all inputs exist
 * Side effects: a .tour file is created
*/
void TSPIO_PrintTour(int *nodes, char *name, int dimension);

#endif
