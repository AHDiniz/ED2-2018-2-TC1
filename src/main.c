// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// main.c: program's entry point

#include <stdio.h>

#include "../include/tspio.h"
#include "../include/point.h"
#include "../include/list.h"
#include "../include/edge.h"

/** Function that build a list with all edges between two points:
 * Inputs: array with all points and problem's dimension
 * Outputs: list with all edges between two points
*/
List *BuildEdgesList(Point **p, int dimension);

int main(int argc, char *argv[])
{
    int i;          // incrementation variable
    char name[20];  // problem's name
    int dimension;  // problem's dimension
    Point **p;      // array of pointers to Point struct
    List *edges;    // List of the edges (graph representation)

    // Reading input file, geting name, dimension and building a array with all points coordinates
    p = TSPIO_ReadEntry(argv[1], name, &dimension);

    printf("name = %s\ndim = %d\n\n", name, dimension);

    // Building a list with all edges between two points
    edges = BuildEdgesList(p, dimension);

    List_RunThrough(edges,Edge_Print,NULL);

    printf("\nlenght = %d\n", List_Length(edges));

    // Destroing the utilized structures
    List_Destroy(edges,Edge_Destroy);
    TSPIO_DestroyArrey(p,dimension);

    return 0;
}

// Function that build a list with all edges between two points:
List *BuildEdgesList(Point **p, int dimension)
{
    int i, j; // incrementation variables
    Edge *e;  // auxiliar variable
    List *l;

    // building a edge between each point in the array
    for(i = 0 ; i < dimension ; i++) {
        for(j = i+1 ; j < dimension ; j++) {
            e = Edge_Create(i+1,p[i],j+1,p[j]);
            if(i == 0 && j == 1) {
                l = List_Create(e);
            }
            else {
                l = List_Add(e,l,Edge_CompareWeight);
            }
        }
    }
    return l;
}
