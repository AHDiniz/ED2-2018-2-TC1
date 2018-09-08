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
#include "../include/edge.h"

// Defining the function that reads the input file:
Point **TSPIO_ReadEntry(char *filename, char *name, int *dimension)
{
    FILE *in = fopen(filename,"r"); // opening the file for reading
    Point **p;                      // array of pointers to cartesian points
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

    p = malloc((*dimension)*sizeof(Point*)); // dynamically allocating the array
    // Reading:
    for(i = 0 ; i < *dimension ; i++)
    {
        fscanf(in,"%*s %f %f\n", &x, &y);
        p[i] = Point_Create(x,y);
    }

    fclose(in); // closing the file

    return p;
}

// Defining the function that destroy the array criated in TSPIO_ReadEntry:
void TSPIO_DestroyArrey(Point **p, int n)
{
    int i;
    // Destroing every position on the array
    for(i = 0 ; i < n ; i++)
    {
        Point_Destroy(p[i]);
    }
    // Destroing the array
    free(p);
}

// Defining the function that prints the MST file:
void TSPIO_PrintMST(List *edges, char *name, int dimension)
{
    // Starting the file's name as <name>.mst
    char *fileName = malloc(strlen(name)+5);
    strcpy(fileName,name);
    strcat(fileName,".mst");

    // Opening output file
    FILE *out = fopen(fileName,"w"); // criating output file

    // Printing header
    fprintf(out, "NAME: %s\nTYPE: MST\nDIMENSION: %d\nMST_SECTION\n", name, dimension);
    // Printing edges
    List_RunThrough(edges,Edge_PrintFile,out);
    fprintf(out, "EOF");

    // Closing file and destroing filename
    fclose(out);
    free(fileName);
}

// Defining the function that prints the tour file:
void TSPIO_PrintTour(int *vertices, char *name, int dimension)
{
    int i;

    // Starting the file's name as <name>.tour
    char *fileName = malloc(strlen(name)+6);
    strcpy(fileName,name);
    strcat(fileName,".tour");

    // Opening output file
    FILE *out = fopen(fileName,"w");

    // Printing header
    fprintf(out, "NAME: %s\nTYPE: TOUR\nDIMENSION: %d\nTOUR_SECTION\n", name, dimension);
    // Printing tour
    for(i = 0 ; i < dimension ; i++)
    {
        fprintf(out, "%d\n", vertices[i]);
    }
    fprintf(out, "EOF");

    // Closing file and destroing filename
    fclose(out);
    free(fileName);
}
