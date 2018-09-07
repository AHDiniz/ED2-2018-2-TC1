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
 * int x: horizontal coordinate of the point
 * int y: vertical coordinate of the point
*/
typedef struct point Point;

/**
 * Declaring the function that allocates and returns a new point:
 * Inputs: the coordinates of the point
 * Output: the pointer to the point structure
 * Conditions: none
 * Side effects: the structure is DYNAMICALLY allocated, remember to destroy it later!!!
*/
Point *Point_Create(int x, int y);

/**
 * Declaring the function that destroys a given point:
 * Input: pointer to the point
 * Output: none
 * Conditions: existent and allocated point
 * Side effects: the pointer will point to NULL
*/
void Point_Destroy(void *point);

/**
 * Declaring the function that prints a given point:
 * Inputs: pointer to the point and a NULL pointer (allows callback to the list destruction function)
 * Output: false
 * Conditions: existent and allocated function and a NULL pointer
 * Side effects: none
*/
bool Point_Print(void *point, void *placeholder);

#endif // POINT_H_
