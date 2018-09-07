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
    float x, y; // Cartesian coordinates of the point
    bool isMarked;
};

// Defining the function that creates a new point:
Point *Point_Create(float x, float y)
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

// Defining the function that compares two points:
bool Point_Compare(void *pointA, void *pointB)
{
    Point *a = (Point *)pointA;
    Point *b = (Point *)pointB;
    return a->x == b->x && a->y == b->y;
}

// Defining the function that marks a point:
void Point_Mark(Point *point)
{
    point->isMarked = true;
}

// Defining the function that checks if a point is marked:
bool Point_IsMarked(Point *point)
{
    return point->isMarked;
}

// Defining the function that returns the x coordinate of the point:
float Point_GetX(Point *point)
{
    return point->x;
}

// Defining the function that returns the y coordinate of the point:
float Point_GetY(Point *point)
{
    return point->y;
}