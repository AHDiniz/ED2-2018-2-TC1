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
typedef struct edge Edge;

/**
 * Declaring the function that allocates and returns a new edge:
 * Inputs: the points to be conected and ther number
 * Output: the pointer to the edge structure
 * Conditions: none
 * Side effects: the structure is DYNAMICALLY allocated, remember to destroy it later
*/
Edge *Edge_Create(int numVertex1, Point *node1, int numVertex2, Point *node2);

/**
 * Declaring the function that destroys a given edge:
 * Input: pointer to the edge
 * Output: none
 * Conditions: existent and allocated edge
 * Side effects: the pointer will point to NULL
*/
void Edge_Destroy(void *edge);

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
int Edge_CompareWeight(void *edgeA, void *edgeB);

/**
 * Declaring the function that compares two edges:
 * Inputs: pointers to the edges
 * Output: boolean that tells if the edges are equal
 * Coditions: existent and allocated edges
 * Side effects: none
*/
bool Edge_Compare(void *edgeA, void *edgeB);

/**
 * Declaring the function that gets the 1º node of the edge:
 * Input: pointer to the edge
 * Output: 1º node of the edge
 * Conditions: existent and allocated edge
 * Side effects: none
*/
int Edge_GetVertex_1(Edge *e);

/**
 * Declaring the function that gets the 2º node of the edge:
 * Input: pointer to the edge
 * Output: 2º node of the edge
 * Conditions: existent and allocated edge
 * Side effects: none
*/
int Edge_GetVertex_2(Edge *e);

/**
 * Declaring the function that gets the weight of the edge:
 * Input: pointer to the edge
 * Output: weight of the edge
 * Conditions: existent and allocated edge
 * Side effects: none
*/
int Edge_GetWeight(Edge *e);

#endif
