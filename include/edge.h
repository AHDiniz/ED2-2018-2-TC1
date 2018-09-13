// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// edge.c: graphs edges declaration file


#ifndef EDGE_H_

#define EDGE_H_

#include "point.h"

/**
 * Declaring a new edge type based on a struct containing:
 * int node1, node2 => identification of the nodes that the edge connects
 * int weight => euclidian distance between both nodes;
*/
typedef struct {
    int node1, node2;
    int weight;
} Edge;

/**
 * Declaring the function that prints a given edge: (structured for a callback that won't be needed)
 * Inputs: pointer to the edge and a NULL pointer
 * Output: false
 * Conditions: existent and allocated edge
 * Side effects: none
*/
bool Edge_Print(void *edge, void *placeholder);

/**
 * Declaring the function that prints a given edge on a given file: (structured for a callback that won't be needed)
 * Inputs: pointer to the edge and a FILE pointer
 * Output: false
 * Conditions: existent and allocated edge and FILE enable to whrite
 * Side effects: none
*/
bool Edge_PrintFile(void *edge, void *file);

/**
 * Declaring the function that compares two edges's weights:
 * Inputs: pointers to the edges
 * Output: an integer that is:
 *      a) equal to 0 if the weights are equal;
 *      b) positive if A's weight is bigger then B's weight;
 *      c) negative if A's weight is smaller then B's weight
 * Coditions: existent and allocated edges
 * Side effects: none
*/
int Edge_CompareWeight(const void *edgeA, const void *edgeB);

/**
 * Declaring the function that compares two edges:
 * Inputs: pointers to the edges
 * Output: boolean that tells if the edges are equal
 * Coditions: existent and allocated edges
 * Side effects: none
*/
bool Edge_Compare(const void *edgeA, const void *edgeB);

#endif
