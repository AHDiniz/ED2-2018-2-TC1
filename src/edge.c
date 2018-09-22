// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// edge.c: graphs edges implamentation file

#include <stdio.h>
#include <stdlib.h>

#include "../include/edge.h"

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
int Edge_CompareWeight(const void *edgeA, const void *edgeB)
{
    Edge *a = (Edge*)edgeA;
    Edge *b = (Edge*)edgeB;
    return a->weight - b->weight;
}

// Defining the function that compares two edges:
bool Edge_Compare(const void *edgeA, const void *edgeB)
{
    Edge *eA = (Edge*) edgeA;
    Edge *eB = (Edge*) edgeB;
    return (eA->node1 == eB->node1 && eA->node2 == eB->node2);
}
