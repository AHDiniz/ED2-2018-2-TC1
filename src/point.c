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
    int group;  // group the point belongs
};

// Defining the function that creates a new point:
Point *Point_Create(int num, int x, int y)
{
    Point *p = malloc(sizeof(*p));
    p->x = x;
    p->y = y;
    p->group = num;
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
    printf("x = %f, y = %f\n", p->x, p->y);
    return false;
}

// Defining the function that compares two points:
bool Point_Compare(void *pointA, void *pointB)
{
    Point *a = (Point *)pointA;
    Point *b = (Point *)pointB;
    return a->x == b->x && a->y == b->y;
}

// Defining the function that agroup two given points in a given point array:
void Point_Agroup(Point **points,int dimension, Point *pointA, Point *pointB)
{
    int Ag = pointA->group;
    int Bg = pointB->group;
    for(int i = 0 ; i < dimension ; i++) {
        if(points[i]->group == Bg) {
            points[i]->group = Ag;
        }
    }
}

// Defining the function that returns the group of a given point:
int Point_GetGroup(Point *point)
{
    return point->group;
}

// Defining the function that returns the x coordinate of the point:
int Point_GetX(Point *point)
{
    return point->x;
}

// Defining the function that returns the y coordinate of the point:
int Point_GetY(Point *point)
{
    return point->y;
}