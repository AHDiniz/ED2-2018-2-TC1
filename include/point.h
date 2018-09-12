// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// point.h: cartesian point header file

#ifndef POINT_H_

#define POINT_H_

#include <stdbool.h>

/**
 * Creating a new point type based on a struct containing:
 * float x: horizontal coordinate of the point
 * float y: vertical coordinate of the point
 * int group: representative of conected points
*/
typedef struct {
    float x, y; // Cartesian coordinates of the point
    int group;  // group the point belongs
} Point;

/**
 * Declaring the function that prints a given point:
 * Inputs: pointer to the point and a NULL pointer (allows callback to the list destruction function)
 * Output: false
 * Conditions: existent and allocated function and a NULL pointer
 * Side effects: none
*/
bool Point_Print(void *point, void *placeholder);

/**
 * Declaring the function that compares two points:
 * Inputs: pointers to the points
 * Output: boolean that tells if the points are equal
 * Coditions: existent and allocated points
 * Side effects: none
*/
bool Point_Compare(void *pointA, void *pointB);

/**
 * Declaring the function that agroup two given points in a given point array:
 * Input: pointer to the point array, dimension of the array and pointers to the points
 * Output: none
 * Conditions: existent and allocated points and array
 * Side effects: all points of group B bacome group A
*/
void Point_Agroup(Point *points,int dimension, Point *pointA, Point *pointB);

#endif // POINT_H_
