#include "ArrayList.h"
#include <stddef.h>
#include <stdlib.h>

#include <stdio.h>

struct ArrayList
{
  size_t size;
  size_t capacity;
  void** elements;
};

static void expandArrayList(ArrayList* list);

//size is final index +1, meaning add just does elements[size] = x, whereas remove would do elements[--size] = NULL

/**
* A function that creates and returns a pointer to an ArrayList for usage, returns NULL on error
*/
ArrayList* createArrayList(size_t capacity) {
    ArrayList* list = malloc(sizeof(ArrayList));
    if (list == NULL)
        return NULL;
    list->size = 0;
    list->capacity = capacity;
    list->elements = malloc(sizeof(void*) * capacity);
    
    return list;
}

/**
* Removes the ArrayList struct from memory, does not free the actual pointers themselves, that's up to the programmer to manage, returns -1 on error
*/
int freeArrayList(ArrayList* list) {
    if (list == NULL)
        return -1;
    
    free(list->elements);
    free(list);
    return 0;
}

/**
* Returns the size of the list (defined as number of elements currently in the list), returns (size_t) -1 on error
*/
size_t getArrayListSize(const ArrayList* list) {
    if (list == NULL)
        return (size_t) -1;
    
    return list->size;
}

/**
* Returns the capacity of the list (defined as number of elements that can be added to the list before it must expand), returns (size_t) -1 on error
*/
size_t getArrayListCapacity(const ArrayList* list) {
    if (list == NULL)
        return (size_t) -1;
    
    return list->capacity;
}

/**
* Returns the element (a void pointer) at the given index, returns NULL on error
*/
void* getArrayListElement(ArrayList* list, size_t index) {
    if (list == NULL || index >= list->size || index < 0)
        return NULL;
    return list->elements[index];
}

/**
* Sets the element at the given index to a void pointer to the given element, returns -1 on error
*/
int setArrayListElement(ArrayList* list, size_t index, void* data) {
    if (list == NULL || index >= list->size || index < 0)
        return -1;
    list->elements[index] = data;
    return 0;
}

/**
* Appends an item onto the end of the list, returns -1 on error
*/
int addArrayListElement(ArrayList* list, void* data) {
    if (list == NULL)
        return -1;
    
    if (list->size == list->capacity)
        expandArrayList(list);
    list->elements[list->size++] = data;
    return 0;
}

/**
* Removes the final element of the list, returns -1 on error
*/
int removeArrayListElement(ArrayList* list) {
    if (list == NULL)
        return -1;
    
    if (list->size == 0)
        return -1;
    list->elements[--list->size] = NULL;
    return 0;
}

/**
* Sorts the list via the qsort function, the passed function must cast from (void*) to (type**) before dereferencing, example compare function on ints:
*
*  int compare(const void* a, const void* b) {
*      int first = **(int**)a;
*      int second = **(int**)b;
*      if (first > second) return 1;
*      if (first < second) return -1;
*      return 0;
*  }
*
* Returns -1 on error;
*/
int sortArrayList(ArrayList* list, int (*compar)(const void*, const void*)) {
    if (list == NULL)
        return -1;
    
    qsort(list->elements, list->size, sizeof(void*), compar);
    return 0;
}

/**
* Finds the given element (passed as a void pointer) when the passed function returns zero, enabling the ability to use the same compare function for both sortArrayList and findInArrayList.
*
* Returns the index of the element if found, (size_t) -1 if no match exists or there was an error
*/
size_t findInArrayList(ArrayList* list, const void* toFind, int (*compar)(const void*, const void*)) {
    if (list == NULL)
        return -1;
    
    for (size_t i = 0; i < list->size; i++) {
        if (compar(&toFind, &(list->elements[i])) == 0)
            return i;
    }
    return (size_t) -1;
}

//internal methods
static void expandArrayList(ArrayList* list) {
    if (list->capacity < 1)
        list->capacity = 2;
    else
        list->capacity *= 2;
    list->elements = realloc(list->elements, list->capacity * sizeof(void*));
}