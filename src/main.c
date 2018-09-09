// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// main.c: program's entry point

#include <stdio.h>

#include "../include/tspio.h"
#include "../include/graph.h"

int main(int argc, char *argv[])
{
    int i;          // incrementation variable
    char name[20];  // problem's name
    int dimension;  // problem's dimension
    Point **p;      // array of pointers to Point struct
    List *edges;    // list of the edges
    Graph *g;       // graph structure

    // Reading input file, geting name, dimension and building a array with all points coordinates
    p = TSPIO_ReadEntry(argv[1], name, &dimension);

    //printf("name = %s\ndim = %d\n\n", name, dimension);

    // Building a list with all edges between two points
    edges = Graph_BuildEdgesList(p, dimension);

    g = Graph_Create(&edges,p,dimension);

    List_RunThrough(edges,Graph_MSTBuilder,g);

    List_RunThrough(edges,Edge_Print,NULL);
    printf("\nlenght = %d\n", List_Length(edges));

    // Destroing the utilized structures
    List_Destroy(edges,Edge_Destroy);
    TSPIO_DestroyArrey(p,dimension);

    return 0;
}
