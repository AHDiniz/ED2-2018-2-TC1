// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// main.c: program's entry point

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "../include/tspio.h"
#include "../include/point.h"
#include "../include/edge.h"

void RemoveRepeated(int *array, int size);
void Add_Adjacency(int *adj, int nodeA, int nodeB);

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
        for(j = i+1 ; j < dimension ; j++, k++) {    // building a edge between "i" and each subsequent point
            edges[k].node1 = i+1;
            edges[k].node2 = j+1;
            edges[k].weight = compute_dist(&p[i],&p[j]);
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
int *BuildTour(Edge **mst, Point *nodes, int dimension)
{
    int i,j=0;                                      // incrementation variable
    //int *t = malloc(2*(dimension-1)*sizeof(int));   // arrey of integers representing the tour
    int *t = malloc(dimension*sizeof(int));
    int adj[dimension*6];

    for(i = 0 ; i < dimension*6 ; i++) { adj[i] = 0; }

    // for each edge on the edge array include its nodes on the tour array
    for(i = 0 ; i < dimension-1 ; i++)
    {
        Add_Adjacency(adj,mst[i]->node1,mst[i]->node2);
        Add_Adjacency(adj,mst[i]->node2,mst[i]->node1);

        //t[j] = mst[i]->node1;
        //j += 1;
        //t[j] = mst[i]->node2;
        //j += 1;
    }

    //RemoveRepeated(t, 2 * (dimension - 1));

    Tour(t,adj,nodes,0,j);

    return t;
}

void Add_Adjacency(int *adj, int nodeA, int nodeB)
{
    int i=0;
    int nA = nodeA * 6;
    while(adj[nA+i] != 0) {
        i += 1;
    }
    adj[nA+i] = nodeB;
}

void Tour(int *tour, int *adj, Point *nodes, int current, int *tourTam)
{
    int i=0;
    int next;
    int position = current * 6;

    for(next = adj[position+i] ; next != 0 && i < 6 ; next = adj[position+(++i)]) {
        if( nodes[current].group != 0) {
            tour[*tourTam] = next;
            *tourTam += 1;
            nodes[current].group = 0;
            Tour(tour,adj,nodes,next,tourTam);
        }
    }
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
    //int i;          // incrementation variable
    char name[20];  // problem's name
    int dimension;  // problem's dimension
    int nEdges;     // number of edges
    Point *p;       // array of points
    Edge *e;        // array of edges 
    Edge **mst;     // array of the MST edges
    int *tour;

    double totalExecTime = 0.0; // Total execution time of the program in seconds (not considering I/O)

    // Reading input file, geting name, dimension and building an array with every point coordinate:

    p = TSPIO_ReadEntry(argv[1], name, &dimension);

    clock_t init = clock();

    // Calculating number of edges
    nEdges = ((dimension-1)*dimension)/2;

    // Building a array with all edges between two points
    e = BuildEdgesList(p,dimension,nEdges);

    qsort(e,nEdges,sizeof(Edge),Edge_CompareWeight);

    // Building the MST
    mst = BuildMST(e,p,nEdges,dimension);

    clock_t end = clock();

    totalExecTime += ((double)(end - init)) / CLOCKS_PER_SEC;

    // Printing the MST file
    TSPIO_PrintMST(mst,name,dimension);

    init = clock();

    // Building the tour
    tour = BuildTour(mst,p,dimension);

    end = clock();

    totalExecTime += ((double)(end - init)) / CLOCKS_PER_SEC;

    printf("Total program execution: %fs\n", totalExecTime);

    // Printing the tour file
    TSPIO_PrintTour(tour,name,dimension);

    // Destroing the utilized structures
    free(p);
    free(e);
    free(mst);
    free(tour);

    return 0;
}
