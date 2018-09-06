// ED2-2018-2-TC2
//
// Alan Herculano Diniz
// Rafael Belmock Pedruzzi
//
// list.c: generic list implementation file

#include "../include/list.h"
#include <stdlib.h>

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
    for (List *current = list; current != NULL; current = current->next)
        l++;
    return l;
}

// Defining the function that checks if the list is empty or not:
bool List_IsEmpty(List *list)
{
    return list == NULL;
}

// Defining the function that adds an item to a list in a given position:
bool List_Add(List *item, List *list, int position)
{
    if (item == NULL || list == NULL)
        return false;
    int length = List_Length(list);
    if (position < 0 || position > length)
        return false;
    if (position == 0)
    {
        item->next = list;
        list->prev = item;
        return true;
    }
    int i = 0;
    List *current = list;
    while (current != NULL && i <= length)
    {
        if (i == position)
        {
            item->next = current;
            item->prev = current->prev;
            current->prev->next = item;
            current->prev = item;
            return true;
        }
        current = current->next;
        i++;
    }
    return false;
}

// Declaring the function that removes an item from the list:
List *List_Remove(List *list, int position)
{
    if (list == NULL)
        return NULL;
    int length = List_Length(list);
    int i = 0;
    List *current = list;
    while (current != NULL && i < length)
    {
        if (i == position)
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            current->prev = current->next = NULL;
            return current;
        }
    }
    return NULL;
}
