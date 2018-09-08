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
 * int vertex1 => number of one vertex;
 * int vertex2 => number of the other vertex;
 * int dist => euclidian distance between both;
*/
typedef struct edge Edge;

/**
 * Declaring the function that allocates and returns a new edge:
 * Inputs: the points to be conected and ther number
 * Output: the pointer to the edge structure
 * Conditions: none
 * Side effects: the structure is DYNAMICALLY allocated, remember to destroy it later
*/
Edge *Edge_Create(int numVertex1, Point *vertex1, int numVertex2, Point *vertex2);

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
 * Declaring the function that compares two edges:
 * Inputs: pointers to the edges
 * Output: integer that is a) =0 if the edges are equal b) >0 if edgeA > edgeB c) <0 if edgeA < edgeB
 * Coditions: existent and allocated edges
 * Side effects: none
*/
int Edge_Compare(void *edgeA, void *edgeB);

/**
 * Declaring the function that gets the 1º vertex of the edge:
 * Input: pointer to the edge
 * Output: 1º vertex of the edge
 * Conditions: existent and allocated edge
 * Side effects: none
*/
int Edge_GetVertex_1(Edge *e);

/**
 * Declaring the function that gets the 2º vertex of the edge:
 * Input: pointer to the edge
 * Output: 2º vertex of the edge
 * Conditions: existent and allocated edge
 * Side effects: none
*/
int Edge_GetVertex_2(Edge *e);

/**
 * Declaring the function that gets the euclidian distance of the edge:
 * Input: pointer to the edge
 * Output: euclidian distance of the edge
 * Conditions: existent and allocated edge
 * Side effects: none
*/
int Edge_GetDist(Edge *e);

#endif
