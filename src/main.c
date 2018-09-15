// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// main.c: program's entry point

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../include/tspio.h"
#include "../include/point.h"
#include "../include/edge.h"

void RemoveRepeated(int *array, int size);

// Defining auxiliar function to calculate the euclidian distance between two cartesian points:
int compute_dist(Point *a, Point *b)
{
    float xd = a->x - b->x;
    float yd = a->y - b->y;
    
    return round(sqrt(xd*xd + yd*yd));
}

// Function that build a list with all edges between two points:
Edge *BuildEdgesList(Point *p, int dimension, int nEdges)
{
    int i, j, k=0; // incrementation variables
    Edge *edges = malloc(nEdges*sizeof(Edge));

    // building a edge between each point in the array
    for(i = 0 ; i < dimension ; i++) {          // selecting a point "i"
        for(j = i+1 ; j < dimension ; j++) {    // building a edge between "i" and each subsequent point
            edges[k].node1 = i+1;
            edges[k].node2 = j+1;
            edges[k].weight = compute_dist(&p[i],&p[j]);
            //printf("%d ", k);
            //Edge_Print(&edges[k],NULL);
            k += 1;
        }
    }
    return edges; // returning list
}

// Function that build the MST
Edge **BuildMST(Edge *edges,Point *points, int nEdges, int dimension)
{
    int i, j=0;
    int nA, nB;
    Edge **mst = malloc((dimension-1)*sizeof(Edge*));

    for(i = 0 ; i < nEdges ; i++)
    {
        if(j == dimension-1) break;

        nA = edges[i].node1; // getting the 1º edge's node
        nB = edges[i].node2; // getting the 2º edge's node

        // If both nodes of the edge are already of the same group, so this edge is removed from the list
        if(points[nA-1].group != points[nB-1].group) {
            mst[j] = &edges[i];
            j += 1;
            Point_Group(points, dimension, &points[nA-1], &points[nB-1]);
        }
    }
    
    return mst;
}

// Function that build the tour
int *BuildTour(Edge **mst, int dimension)
{
    int i,j=0;                                      // incrementation variable
    int *t = malloc(2*(dimension-1)*sizeof(int));   // arrey of integers representing the tour

    // for each edge on the edge array include its nodes on the tour array
    for(i = 0 ; i < dimension-1 ; i++)
    {
        t[j] = mst[i]->node1;
        j += 1;
        t[j] = mst[i]->node2;
        j += 1;
    }

    RemoveRepeated(t, 2 * (dimension - 1));

    return t;
}

// Function that removes the repeated items of an integer array:
// The repeated items are changed to 0
void RemoveRepeated(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (array[i] == array[j])
                array[j] = 0;
}

int main(int argc, char *argv[])
{
    int i;          // incrementation variable
    char name[20];  // problem's name
    int dimension;  // problem's dimension
    int nEdges;     // number of edges
    Point *p;       // array of points
    Edge *e;        // array of edges
    Edge **mst;     // array of the MST edges
    int *tour;

    // Reading input file, geting name, dimension and building an array with every point coordinate:
    p = TSPIO_ReadEntry(argv[1], name, &dimension);

    // Calculating number of edges
    nEdges = ((dimension-1)*dimension)/2;

    // Building a array with all edges between two points
    e = BuildEdgesList(p,dimension,nEdges);

    qsort(e,nEdges,sizeof(Edge),Edge_CompareWeight);

    // Building the MST
    mst = BuildMST(e,p,nEdges,dimension);

    // Printing the MST file
    TSPIO_PrintMST(mst,name,dimension);

    // Building the tour
    tour = BuildTour(mst,dimension);

    // Printing the tour file
    TSPIO_PrintTour(tour,name,dimension);

    //for(i = 0 ; i < 2*(dimension-1) ; i++) {
    //    Edge_Print(mst[i],NULL);
    //    printf("%d\n", tour[i]);
    //}
    //printf("comp = %d\n", Edge_CompareWeight(&e[nEdges-2],&e[nEdges-1]));

    // Destroing the utilized structures
    free(p);
    free(e);
    free(mst);

    return 0;
}
