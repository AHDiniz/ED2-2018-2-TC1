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

int TSPIO_ReadEntry(char *filename, char *name, Point *p[])
{
    FILE *in = fopen(filename,"r");
    int dimension;
    int i;
    //char x[20], y[20];
    float x, y;

    char s[20];

    fscanf(in,"%s", s);// printf("s = %s\n", s);
    while(strcmp(s,"NAME:") != 0)
    {
        fscanf(in,"%[^\n]%*c");
        fscanf(in,"%s", s);// printf("s = %s\n", s);
    }
    fscanf(in,"%s", name);// printf("name = %s\n", name);

    fscanf(in,"%s", s);// printf("s = %s\n", s);
    while(strcmp(s,"TYPE:") != 0)
    {
        fscanf(in,"%[^\n]%*c");
        fscanf(in,"%s", s);// printf("s = %s\n", s);
    }
    fscanf(in,"%s", s);// printf("s = %s\n", s);
    if(strcmp(s,"TSP") != 0)
    {
        exit(1);
    }

    fscanf(in,"%s", s);// printf("s = %s\n", s);
    while(strcmp(s,"DIMENSION:") != 0)
    {
        fscanf(in,"%[^\n]%*c");
        fscanf(in,"%s", s);// printf("s = %s\n", s);
    }
    fscanf(in,"%s", s);// printf("s = %s\n", s);
    dimension = atoi(s);
    //printf("dim = %d\n", dimension);

    fscanf(in,"%s", s);// printf("s = %s\n", s);
    while(strcmp(s,"EDGE_WEIGHT_TYPE:") != 0)
    {
        fscanf(in,"%[^\n]%*c");
        fscanf(in,"%s", s);// printf("s = %s\n", s);
    }
    fscanf(in,"%s", s);
    if(strcmp(s,"EUC_2D") != 0)
    {
        exit(1);
    }

    fscanf(in,"%s", s);// printf("s = %s\n", s);
    while(strcmp(s,"NODE_COORD_SECTION") != 0)
    {
        fscanf(in,"%[^\n]%*c");
        fscanf(in,"%s", s);// printf("s = %s\n", s);
    }

    p = malloc(dimension*sizeof(Point*));
    for(i = 0 ; i < dimension ; i++)
    {
        fscanf(in,"%*s %f %f\n", &x, &y);// printf("xl = %f yl = %f\n", x, y);
        p[i] = Point_Create(x,y);// printf("xp = %f yp = %f\n", Point_GetX(p[i]), Point_GetY(p[i]));
        //Point_Print(p[i],NULL);
    }

    fclose(in);

    return dimension;
}

void TSPIO_DestroyVector(Point *p[], int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        Point_Destroy(p[i]);
    }
    free(p);
}
