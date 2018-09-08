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
    int vertex1, vertex2;
    int dist;
};

// Defining the function that allocates and returns a new edge:
Edge *Edge_Create(int numVertex1, Point *vertex1, int numVertex2, Point *vertex2)
{
    Edge *e = malloc(sizeof(Edge));
    e->vertex1 = numVertex1;
    e->vertex2 = numVertex2;
    e->dist = compute_dist(vertex1,vertex2);

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
    printf("p1 = %d, p2 = %d, dist = %d\n", e->vertex1, e->vertex2, e->dist);
    return false;
}


// Defining the function that prints a given edge on a given file:
bool Edge_PrintFile(void *edge, void *file)
{
    Edge *e = (Edge*) edge;
    FILE *out = (FILE*) file;
    fprintf(out, "%d %d\n", e->vertex1, e->vertex2);
    return false;
}

// Defining the function that compares two edges:
int Edge_Compare(void *edgeA, void *edgeB)
{
    Edge *eA = (Edge*) edgeA;
    Edge *eB = (Edge*) edgeB;
    return eA->dist - eB->dist;
}

// Defining the function that gets the 1º vertex of the edge:
int Edge_GetVertex_1(Edge *e)
{
    return e->vertex1;
}

// Defining the function that gets the 2º vertex of the edge:
int Edge_GetVertex_2(Edge *e)
{
    return e->vertex2;
}

// Defining the function that gets the euclidian distance of the edge:
int Edge_GetDist(Edge *e)
{
    return e->dist;
}

// Defining auxiliar function that calculate the euclidian distance between two cartesian points:
int compute_dist(Point *i, Point *j)
{
    int xd = (int)(Point_GetX(i) - Point_GetX(j));
    int yd = (int)(Point_GetY(i) - Point_GetY(j));
    
    return round(sqrt(xd*xd + yd*yd));
}
