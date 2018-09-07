// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// list.c: generic list implementation file

#include "../include/list.h"
#include <stdlib.h>
#include <stdio.h>

// Defining a list struct:
struct list
{
    void *content; // Content of the item
    List *next; // Pointer to next item
    List *prev; // Pointer to previous item
};

// Defining the list item creation function:
List *List_Create(void *content)
{
    List *list = malloc(sizeof(*list)); // Allocating space for the list item
    list->content = content; // Making the item point to the content
    list->next = NULL; // Making the item point to the next item of the list
    list->prev = NULL; // Making the item point to the previous item of the list
    return list; // Returning the item's adress
}

// Defining the function that returns the item's content:
void *List_Content(List *item)
{
    return item->content;
}

// Defining the function that returns the list's length:
int List_Length(List *list)
{
    if (list == NULL)
        return -1;
    int l = 0;
    // Looping through every item in the list:
    for (List *current = list; current != NULL; current = current->next)
        l++; // For each item, the counter will be incremented
    return l;
}

// Defining the function that checks if the list is empty or not:
bool List_IsEmpty(List *list)
{
    return list == NULL;
}

// Defining the function that adds an item to a list in the end of it:
bool List_Add(List *item, List *list)
{
    if (item != NULL && list != NULL) // Checking if the input is valid
    {
        List *current;
        for (current = list; current->next != NULL; current = current->next);
        current->next = item;
        return true;
    }
    else return false;
}

// Defining the function that removes an item from the list:
List *List_Remove(List *list, void *content, List_Operation Compare)
{
    if (list == NULL || content == NULL || Compare == NULL)
        return NULL;
    for (List *current = list; current != NULL; current = current->next)
        if (Compare(current->content, content))
            return current;
    return NULL;
}

// Defining the function that destroys a list:
bool List_Destroy(List *list, List_DestroyContent Destroy)
{
    if (list == NULL) // Checking if the list is valid:
        return false;
    List *current = list;
    List *target;
    while (current != NULL) // Looping through the list and destroying every item:
    {
        target = current;
        current = current->next;
        if (Destroy != NULL)
            Destroy(target->content);
        free(target);
    }
    list = NULL; // Making the list pointer point to NULL when the operation is done
    return true;
}

// Defining the function that runs through the list applying an operation on the items:
bool List_RunThrough(List *list, List_Operation Operation, void *data)
{
    for (List *current = list; current != NULL; current = current->next)
        if (Operation(current->content, data))
            return true;
    return false;
}
