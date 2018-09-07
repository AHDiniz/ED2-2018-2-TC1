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

List *BuildEdgesList(Point **p, int dimension);

int main(int argc, char *argv[])
{
    char name[20];
    int dimension, i;
    Point **p;
    List *edgesList;

    p = TSPIO_ReadEntry(argv[1], name, &dimension);

    edgesList = BuildEdgesList(p, dimension);

    List_RunThrough(edgesList,Edge_Print,NULL);

    

    List_Destroy(edgesList,Edge_Destroy);
    TSPIO_DestroyArrey(p,dimension);
    return 0;
}

List *BuildEdgesList(Point **p, int dimension)
{
    int i, j;
    List *l;
    Edge *e;

    for(i = 0 ; i < dimension ; i++) {
        for(j = i+1 ; j < dimension ; j++) {
            e = Edge_Create(i+1,p[i],j+1,p[j]);
            if(i == 0 && j == 1) {
                l = List_Create(e);
            }
            else {
                List_Add(List_Create(e),l);
            }
        }
    }
    return l;
}
