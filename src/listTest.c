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

    // Creating the list:
    List *list = List_Create(p1);
    list = List_Add(p2, list, NULL);
    list = List_Add(p3, list, NULL);
    list = List_Add(p4, list, NULL);
    list = List_Add(p5, list, NULL);

    // Printing the list:
    List_RunThrough(list, Point_Print, NULL);

    // Removing the top item:
    List *item = List_Remove(list, p1, Point_Compare);
    p1 = List_Content(item);
    printf("Removed item: ");
    Point_Print(p1, NULL);
    List_Destroy(item, Point_Destroy);

    // Printing the list:
    List_RunThrough(list, Point_Print, NULL);

    // Removing the second item in the current list:
    item = List_Remove(list, p3, Point_Compare);
    p3 = List_Content(item);
    printf("Removed item: ");
    Point_Print(p3, NULL);
    List_Destroy(item, Point_Destroy);

    // Printing the list:
    List_RunThrough(list, Point_Print, NULL);

    // Removing the last item:
    item = List_Remove(list, p5, Point_Compare);
    p5 = List_Content(item);
    printf("Removed item: ");
    Point_Print(p5, NULL);
    List_Destroy(item, Point_Destroy);

    // Printing the list:
    List_RunThrough(list, Point_Print, NULL);

    // Destroying the list:
    List_Destroy(list, Point_Destroy);

    return 0;
}
