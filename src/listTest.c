// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// listTest.c: list and point tester entry point

#include <stdio.h>
#include "../include/list.h"
#include "../include/point.h"

int main(int argc, char *argv[])
{
    // Creating random points:
    Point *p1 = Point_Create(1, 1);
    Point *p2 = Point_Create(2, 2);
    Point *p3 = Point_Create(3, 3);
    Point *p4 = Point_Create(4, 4);
    Point *p5 = Point_Create(5, 5);

    // Creating a list to store the points:
    List *list = List_Create(p1);
    List *item2 = List_Create(p2);
    List *item3 = List_Create(p3);
    List *item4 = List_Create(p4);
    List *item5 = List_Create(p5);
    List_Add(item2, list);
    List_Add(item3, list);
    List_Add(item4, list);
    List_Add(item5, list);

    // Printing the list:
    List_RunThrough(list, Point_Print, NULL);

    // Destroying the list and it's items:
    List_Destroy(list, Point_Destroy);

    return 0;
}
