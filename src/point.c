// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// point.c: cartesian point implementation file

#include "../include/point.h"
#include <stdlib.h>
#include <stdio.h>

// Defining the point structure:
struct point
{
    int x, y; // Cartesian coordinates of the point
    bool isMarked;
};

// Defining the function that creates a new point:
Point *Point_Create(int x, int y)
{
    Point *p = malloc(sizeof(*p));
    p->x = x;
    p->y = y;
    p->isMarked = false;
    return p;
}

// Defining the function that destroys the point:
void Point_Destroy(void *point)
{
    free(point);
}

// Defining the function that prints a point:
bool Point_Print(void *point, void *placeholder)
{
    Point *p = (Point *)point;
    printf("x = %d, y = %d\n", p->x, p->y);
    return false;
}

void Point_Mark(Point* point)
{
    point->isMarked = true;
}

bool Point_IsMarked(Point* point)
{
    return point->isMarked;
}
