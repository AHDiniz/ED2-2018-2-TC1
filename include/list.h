// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// list.h: generic list header file

#ifndef LIST_H_

#define LIST_H_

#include <stdbool.h>

/**
 * Declaring a new list type based on a struct containing:
 * void *content => Content of the list item;
 * List *next => Pointer to next item;
 * List *prev => Pointer to previous item;
*/
typedef struct list List;

/**
 * Declaring the function that allocates the space for a new list item:
 * Inputs: pointer to content, pointer to next and previous items of the list
 * Output: pointer to dynamically allocated list item structure
 * Conditions: existent content and existent and allocated items or NULL items
 * Side effects: item DYNAMICALLY allocated, remember to destroy it later!!!
*/
List *List_Create(void *content);

/**
 * Declaring the function that returns the pointer to the item's content:
 * Input: pointer to the list item
 * Output: pointer to the entry item's content
 * Conditions: existent and allocated item
 * Side effects: none
*/
void *List_Content(List *item);

/**
 * Declaring a function that returns the amount of items in the list:
 * Input: pointer to the list
 * Output: length of the list
 * Conditions: existent and allocated list
 * Side effects: none
*/
int List_Length(List *list);

/**
 * Declaring the function that verifies of a list is empty or not:
 * Input: pointer to the list
 * Output: boolean that says if the list is or isn't empty
 * Conditions: existent list
 * Side effects: none
*/
bool List_IsEmpty(List *list);

/**
 * Declaring the function thar adds an item to the list in a certain position:
 * Inputs: pointers to the item and to the list and the desired position of the item
 * Output: bool that tells the success of the operation
 * Conditions: existent and allocated item and list and valid position
 * Side effects: the item is added to the list
*/
bool List_Add(List *item, List *list, int position);

/**
 * Declaring the function that removes an item in a certain position from the list:
 * Inputs: pointer to the list and the target's position
 * Output: pointer to the removed item
 * Conditions: existent and allocated list and valid position
 * Side effects: the target item won't be in the list anymore
*/
List *List_Remove(List *list, int position);

#endif // LIST_H_
