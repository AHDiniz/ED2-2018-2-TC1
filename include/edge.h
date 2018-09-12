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
 * int node1 => number of one node;
 * int node2 => number of the other node;
 * int weight => euclidian distance between both;
*/
typedef struct {
    int node1, node2;
    int weight;
} Edge;

/**
 * Declaring the function that prints a given edge:
 * Inputs: pointer to the edge and a NULL pointer (allows callback to the list RunThrough function)
 * Output: false
 * Conditions: existent and allocated edge
 * Side effects: none
*/
bool Edge_Print(void *edge, void *placeholder);

/**
 * Declaring the function that prints a given edge on a given file:
 * Inputs: pointer to the edge and a FILE pointer (allows callback to the list RunThrough function)
 * Output: false
 * Conditions: existent and allocated edge and FILE enable to whrite
 * Side effects: none
*/
bool Edge_PrintFile(void *edge, void *file);

/**
 * Declaring the function that compares two edges's weights:
 * Inputs: pointers to the edges
 * Output: integer that is a) =0 if the weights are equal b) >0 if A's weight > B's weight c) <0 if A's weight < B's weight
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
