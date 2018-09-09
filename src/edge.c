// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// edge.c: graphs edges implamentation file

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../include/edge.h"

// Declaring auxiliar function that calculate the euclidian distance between two cartesian points:
int compute_dist(Point *i, Point *j);

// Defining the edge structure:
struct edge {
    int node1, node2;
    int weight;
};

// Defining the function that allocates and returns a new edge:
Edge *Edge_Create(int numNode1, Point *node1, int numNode2, Point *node2)
{
    Edge *e = malloc(sizeof(Edge));
    e->node1 = numNode1;
    e->node2 = numNode2;
    e->weight = compute_dist(node1,node2);

    return e;
}

// Defining the function that destroys a given edge:
void Edge_Destroy(void *edge)
{
    free(edge);
}

// Defining the function that prints a given edge:
bool Edge_Print(void *edge, void *placeholder)
{
    Edge *e = (Edge*) edge;
    printf("p1 = %d, p2 = %d, weight = %d\n", e->node1, e->node2, e->weight);
    return false;
}


// Defining the function that prints a given edge on a given file:
bool Edge_PrintFile(void *edge, void *file)
{
    Edge *e = (Edge*) edge;
    FILE *out = (FILE*) file;
    fprintf(out, "%d %d\n", e->node1, e->node2);
    return false;
}

// Defining the function that compares two edges's weights:
int Edge_CompareWeight(void *edgeA, void *edgeB)
{
    Edge *eA = (Edge*) edgeA;
    Edge *eB = (Edge*) edgeB;
    return eA->weight - eB->weight;
}

// Defining the function that compares two edges:
bool Edge_Compare(void *edgeA, void *edgeB)
{
    Edge *eA = (Edge*) edgeA;
    Edge *eB = (Edge*) edgeB;
    return (eA->node1 == eB->node1 && eA->node2 == eB->node2);
}

// Defining the function that gets the 1º node of the edge:
int Edge_GetNode_1(Edge *e)
{
    return e->node1;
}

// Defining the function that gets the 2º node of the edge:
int Edge_GetNode_2(Edge *e)
{
    return e->node2;
}

// Defining the function that gets the weight of the edge:
int Edge_GetWeight(Edge *e)
{
    return e->weight;
}

// Defining auxiliar function that calculate the euclidian distance between two cartesian points:
int compute_dist(Point *i, Point *j)
{
    int xd = Point_GetX(i) - Point_GetX(j);
    int yd = Point_GetY(i) - Point_GetY(j);
    
    return round(sqrt(xd*xd + yd*yd));
}
