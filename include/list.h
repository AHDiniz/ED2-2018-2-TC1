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
 * Declaring a type that's a callback to a function that destroys an item's content:
 * Input: void pointer to the item's content
 * Output: none
*/
typedef void (*List_DestroyContent) (void *);

/**
 * Declaring a type that's a callback to a function that applys a operation to a list item:
 * Inputs: pointer to the item's content and to the operation's other data
 * Output: boolean that tells if the operation was or not a success
*/
typedef bool (*List_Operation) (void *, void *);

/**
 * Declaring a type that's a callback to a function that compares two data and tells if the first is less then,
 * equal to or bigger then the second:
 * Inputs: pointers to the data to be compared
 * Output: -1 if the 1st is less then the 2nd, 0 if they are equal and 1 if the 1st is bigger then the 2nd
*/
typedef int (*List_Compare) (void *, void *);

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
 * Declaring the function thar adds a content to the list in the end of the list:
 * Inputs: pointers to the item's content and to the list
 * Output: the new list
 * Conditions: existent and allocated item and list
 * Side effects: the item is added to the end of list
*/
List *List_Add(void *item, List *list, List_Compare Compare);

/**
 * Declaring the function that searches an item given it's content and the list:
 * Inputs: the pointer to the item's content, the pointer to the list and a function to compare the contents
 * Output: the pointer to the item
 * Conditions: existent and allocated content, list and function
 * Side effects: none
*/
List *List_Search(List *list, void *item, List_Operation Compare);

/**
 * Declaring the function that removes an item that has a certain content from the list:
 * Inputs: pointer to the list, the content of the target item and and comparision operation (true if equal, false if not)
 * Output: pointer to the removed item
 * Conditions: existent and allocated list, valid content and function
 * Side effects: the target item won't be in the list anymore, and the first one found will be returned
*/
List *List_Remove(List *list, void *content, List_Operation Compare);

/**
 * Declaring the function that destroys a list and it's items:
 * Inputs: pointer to the list and function that destroys the item's content
 * Output: boolean that tells if the operation was a success or not
 * Conditions: existent and allocated list and valid function
 * Side effects: all items are destroyed and the entry pointer points to NULL
*/
bool List_Destroy(List *list, List_DestroyContent Destroy);

/**
 * Declaring the function that allows the user to make a given operation on every item on the list:
 * Inputs: pointer to the list and the desired operation function
 * Output: boolean that says if the operation was or not a success
 * Conditions: existent and allocated list and valid function
 * Side effects: that depends on the operation that the user pass
 * Observation: if you want to run through every item, pass an operation that always returns false
*/
bool List_RunThrough(List *list, List_Operation Operation, void *data);

#endif // LIST_H_
