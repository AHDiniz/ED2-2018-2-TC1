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
List *List_Add(void *item, List *list, List_Compare Compare)
{
    // Checking if the list and item are valid:
    if (list == NULL)
        return NULL;
    if (item == NULL)
        return list;
    // If there's no comparision function, the item will be added in the top of the list:
    if (Compare == NULL)
    {
        List *new = List_Create(item);
        new->next = list;
        list->prev = new;
        return new;
    }
    // If there's only one item in the list:
    if (list->next == NULL)
    {
        // The comparision will be made and, if the item is smaller then the top, it becomes the top:
        if (Compare(item, list->content) <= 0)
        {
            List *new = List_Create(item);
            new->next = list;
            list->prev = new;
            return new;
        }
        else // If the item is bigger, then it's added to the end of the list:
        {
            List *new = List_Create(item);
            list->next = new;
            new->prev = list;
            return list;
        }
    }
    // If there are multiple items in the list:
    for (List *current = list->next; current != NULL; current = current->next)
    {
        if (Compare(item, current->content) == -1) // If the item is smaller then the current one, it will be added to the list:
        {
            List *new = List_Create(item);
            new->next = current;
            new->prev = current->prev;
            if (current->prev->next != NULL)
                current->prev->next = new;
            current->prev = new;
            return list;
        }
        // If the current item is the last of the list and the item is bigger:
        if (current->next == NULL && Compare(item, current->content) >= 0)
        {
            List *new = List_Create(item);
            current->next = new;
            new->prev = current;
            return list;
        }
    }
    return list; // Returning the list if there was any problem
}

// Defining the function that searches an item in the list:
List *List_Search(List *list, void *item, List_Operation Compare)
{
    // If the inputs are not valid, the function will return NULL
    if (list == NULL || item == NULL || Compare == NULL)
        return NULL;
    // Returning the first item with the desired content:
    for (List *current = list; current != NULL; current = current->next)
        if (Compare(item, current->content))
            return current;
    return NULL; // Returning NULL if the item is not in the list
}

// Defining the function that removes an item from the list:
List *List_Remove(List *list, void *content, List_Operation Compare)
{
    List *item = List_Search(list, content, Compare);
    if (item == NULL) return item; // If the item is not in the list or the input are not valid, the function returns NULL
    if (Compare(content, list->content)) // If the target item is the top of the list:
        list = item->next; // The list will point to the second item in it
    else
        item->prev->next = item->next; // Making the previous item point to the current item's next
    if (item->next != NULL) // If the target item isn't the last item in the list
        item->next->prev = item->prev; // MAking the next item point to the current item's previous
    return item;
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
    if (list == NULL || Operation == NULL)
        return false;
    for (List *current = list; current != NULL; current = current->next)
        if (Operation(current->content, data))
            return true;
    return false;
}
