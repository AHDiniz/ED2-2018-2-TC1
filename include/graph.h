// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// graph.h: graph header file

#ifndef GRAPH_H_

#define GRAPH_H_

#include "list.h"
#include "edge.h"
#include "point.h"

/**
 * Creating a new graph type based on a struct containing:
 * List **edges: list with the graph's edges
 * Point **points: array with the graph's points (cartesian coordenates)
*/
typedef struct graph Graph;

/**
 * Declaring the function that allocates the space for a new graph:
 * Inputs: pointer to edges list, pointer to the points array and the dimension of the array
 * Output: pointer to dynamically allocated graph structure
 * Conditions: existent and allocated list and array
 * Side effects: graph DYNAMICALLY allocated, remember to destroy it later
*/
Graph *Graph_Create(List **edges, Point **points, int dimension);

/**
 * Declaring the function that gets the graph's edges list:
 * Input: pointer to the graph
 * Output: graph's edges list
 * Conditions: existent and allocated graph
 * Side effects: none
*/
List **Graph_GetEdges(Graph *graph);

/**
 * Declaring the function that gets the graph's points array:
 * Input: pointer to the graph
 * Output: graph's points array
 * Conditions: existent and allocated graph
 * Side effects: none
*/
Point **Graph_GetPoints(Graph *graph);

/**
 * Declaring the function that build a list with all edges between two points:
 * Inputs: pointer to the array of point pointers and the number of points
 * Output: the pointer to the created list
 * Conditions: existent and allocated array
 * Side effects: the list is DYNAMICALLY allocated, remember to destroy it later
*/
List *Graph_BuildEdgesList(Point **p, int dimension);

/**
 * Declaring the auxiliar function that build the MST:
 * Inputs: pointer to a edge and the graph it belongs
 * Output: false
 * Conditions: existent and allocated edge and graph, must be used in the List_RunThrough function on a ordened list of edges
 * Side effects: the unnessessary edges will be remover from the list and destroyed
*/
bool Graph_MSTBuilder(void *edge,void *graph);

#endif
