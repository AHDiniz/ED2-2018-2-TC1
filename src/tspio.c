// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// tspio.c: input and output implementation file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../include/tspio.h"

// Defining the function that reads the input file:
Point **TSPIO_ReadEntry(char *filename, char *name, int *dimension)
{
    FILE *in = fopen(filename,"r"); // opening the file for reading
    Point **p;                      // arrey of pointers to cartesian points
    int i;                          // incrementation variable
    float x, y;                     // auxiliars for coordenates reading
    char s[20];                     // auxiliar for strings reading

    // Finding and reading the problem's name
    fscanf(in,"%s", s);
    while(strcmp(s,"NAME:") != 0)
    {
        fscanf(in,"%*[^\n]%*c");
        fscanf(in,"%s", s);
    }
    fscanf(in,"%s", name);

    // Finding and reading the problem's type 
    fscanf(in,"%s", s);
    while(strcmp(s,"TYPE:") != 0)
    {
        fscanf(in,"%*[^\n]%*c");
        fscanf(in,"%s", s);
    }
    fscanf(in,"%s", s);
    // Checking the type
    if(strcmp(s,"TSP") != 0)
    {
        printf("ERROR: Type must be TSP\n");
        exit(1);
    }

    // Finding and reading the problem's dimension
    fscanf(in,"%s", s);
    while(strcmp(s,"DIMENSION:") != 0)
    {
        fscanf(in,"%*[^\n]%*c");
        fscanf(in,"%s", s);
    }
    fscanf(in,"%s", s);
    *dimension = atoi(s);

    // Finding and reading the problem's edge weight type
    fscanf(in,"%s", s);
    while(strcmp(s,"EDGE_WEIGHT_TYPE:") != 0)
    {
        fscanf(in,"%*[^\n]%*c");
        fscanf(in,"%s", s);
    }
    fscanf(in,"%s", s);
    // checking the edge weight type
    if(strcmp(s,"EUC_2D") != 0)
    {
        printf("ERROR: Edge Weight Type must be EUC_2D\n");
        exit(1);
    }

    // Finding and reading the problem's coordenates
    // Finding:
    fscanf(in,"%s", s);
    while(strcmp(s,"NODE_COORD_SECTION") != 0)
    {
        fscanf(in,"%*[^\n]%*c");
        fscanf(in,"%s", s);
    }

    p = malloc((*dimension)*sizeof(Point*)); // dynamically allocating the arrey
    // Reading:
    for(i = 0 ; i < *dimension ; i++)
    {
        fscanf(in,"%*s %f %f\n", &x, &y);
        p[i] = Point_Create(x,y);
    }

    fclose(in); // closing the file

    return p;
}

// Defining the function that destroy the arrey criated in TSPIO_ReadEntry:
void TSPIO_DestroyArrey(Point **p, int n)
{
    int i;
    for(i = 0 ; i < n ; i++)
    {
        Point_Destroy(p[i]);
    }
    free(p);
}
