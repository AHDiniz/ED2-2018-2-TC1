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

    // Removing the top item and then destroying it:
    List *item = List_Remove(list, p1, Point_Compare);
    printf("Removed top point: ");
    Point_Print(List_Content(item), NULL);
    List_Destroy(item, Point_Destroy);

    // Printing the list:
    printf("\nCurrent list state:\n");
    List_RunThrough(list, Point_Print, NULL);

    // Removing a middle item and then destroying it:
    item3 = List_Remove(list, p3, Point_Compare);
    printf("Removed middle point: ");
    Point_Print(List_Content(item3), NULL);
    List_Destroy(item3, Point_Destroy);

    // Printing the list:
    printf("\nCurrent list state:\n");
    List_RunThrough(list, Point_Print, NULL);

    // Removing the bottom item and then destroying it:
    item5 = List_Remove(list, p5, Point_Compare);
    printf("Removed bottom point: ");
    Point_Print(List_Content(item5), NULL);
    List_Destroy(item5, Point_Destroy);

    // Printing the list:
    printf("\nCurrent list state:\n");
    List_RunThrough(list, Point_Print, NULL);

    // Destroying the list and it's items:
    List_Destroy(list, Point_Destroy);

    return 0;
}
