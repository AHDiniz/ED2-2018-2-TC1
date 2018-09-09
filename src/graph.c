// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// graph.c: graph implementation file

#include <stdio.h>
#include <stdlib.h>

#include "../include/graph.h"

struct graph{
    List **edges;
    Point **points;
    int dimension;
};


// Defining the function that allocates the space for a new graph:
Graph *Graph_Create(List **edges, Point **points, int dimension)
{
    Graph *g = malloc(sizeof(Graph));
    g->edges = edges;
    g->points = points;
    g->dimension = dimension;
    return g;
}

// Defining the function that gets the graph's edges list:
List **Graph_GetEdges(Graph *graph)
{
    return graph->edges;
}

// Defining the function that gets the graph's points array:
Point **Graph_GetPoints(Graph *graph)
{
    return graph->points;
}

// Function that build a list with all edges between two points:
List *Graph_BuildEdgesList(Point **p, int dimension)
{
    int i, j; // incrementation variables
    Edge *e;  // auxiliar variable
    List *l;  // new list

    // building a edge between each point in the array
    for(i = 0 ; i < dimension ; i++) {          // selecting a point "i"
        for(j = i+1 ; j < dimension ; j++) {    // building a edge between "i" and each subsequent point
            e = Edge_Create(i+1,p[i],j+1,p[j]); // initializing edge
            if(i == 0 && j == 1) {              // if it is the first edge the list is initialized
                l = List_Create(e);
            }                                   // else, the edge is added to the list preserving it's ordination
            else {
                l = List_Add(e,l,Edge_CompareWeight);
            }
        }
    }
    return l; // returning list
}

// Function that build the MST
bool Graph_MSTBuilder(void *edge,void *graph)
{
    Edge *e = (Edge*) edge;     // getting the edge
    Graph *g = (Graph*) graph;  // getting the graph
    int nA = Edge_GetNode_1(e); // getting the 1º edge's node
    int nB = Edge_GetNode_2(e); // getting the 2º edge's node

    // If both nodes of the edge are already marked they already belong to the tree, so this edge is removed from the list
    if(Point_GetGroup(g->points[nA-1]) == Point_GetGroup(g->points[nB-1])) {
        List *l = List_Remove(g->edges,edge,Edge_Compare);
        List_Destroy(l,Edge_Destroy); // freeing the removed edge
        return false;
    }

    // else, Marking both nodes (including them in the MST)
    Point_Agroup(g->points, g->dimension, g->points[nA-1],g->points[nB-1]);
    return false;
}