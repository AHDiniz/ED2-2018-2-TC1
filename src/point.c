// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// point.c: cartesian point implementation file

#include "../include/point.h"
#include <stdlib.h>
#include <stdio.h>

// Defining the function that prints a point:
bool Point_Print(void *point, void *placeholder)
{
    Point *p = (Point*)point;
    printf("x = %f, y = %f\n", p->x, p->y);
    return false;
}

// Defining the function that compares two points:
bool Point_Compare(void *pointA, void *pointB)
{
    Point *a = (Point*)pointA;
    Point *b = (Point*)pointB;
    return a->x == b->x && a->y == b->y;
}

// Defining the function that agroup two given points in a given point array:
void Point_Agroup(Point *points, int dimension, Point *pointA, Point *pointB)
{
    int gA = pointA->group;
    int gB = pointB->group;
    for(int i = 0 ; i < dimension ; i++) {
        if(points[i].group == gB) {
            points[i].group = gA;
        }
    }
}
