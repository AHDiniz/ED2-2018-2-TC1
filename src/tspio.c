// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// tspio.c: input and output functions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../include/tspio.h"

Point* TSPIO_ReadEntry(char* filename, char* name, int* dimension)
{
    FILE* in = fopen(filename,"r");
    Point* pontos;
    int i;

    char s[20];

    while(strcmp(s,"NAME:") != 0)
    {
        fscanf(in,"%s", s); printf("s = %s\n", s);
    }
    fscanf(in,"%s", name); printf("name = %s\n", name);

    fscanf(in,"%s", s);
    while(strcmp(s,"TYPE:") != 0)
    {
        fscanf(in,"%s", s); printf("s = %s\n", s);
    }
    fscanf(in,"%s", s); printf("s = %s\n", s);
    if(strcmp(s,"TSP") != 0)
    {
        exit(1);
    }

    fscanf(in,"%s", s);
    while(strcmp(s,"DIMENSION:") != 0)
    {
        fscanf(in,"%s", s); printf("s = %s\n", s);
    }
    fscanf(in,"%s", dimension); printf("s = %s\n", s);
    *dimension = atoi(s); printf("dim = %d\n", *dimension);

    fscanf(in,"%s", s);
    while(strcmp(s,"EDGE_WEIGHT_TYPE:") != 0)
    {
        fscanf(in,"%s", s); printf("s = %s\n", s);
    }
    fscanf(in,"%*c");
/*
    pontos = malloc((*dimension)*sizeof(Point));
    for(i = 0 ; i < *dimension ; i++)
    {
        //fscanf(in,"%d ");
        fscanf(in,"%*d %f %f\n", &pontos[i].x, &pontos[i].y); printf("%d %f %f\n", i+1, pontos[i].x, pontos[i].y);
    }
*/
    fclose(in);

    return pontos;
}
