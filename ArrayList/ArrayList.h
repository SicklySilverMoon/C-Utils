#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stddef.h>

typedef struct ArrayList ArrayList;

ArrayList* createArrayList(size_t capacity);
int freeArrayList(ArrayList* list);
size_t getArrayListSize(const ArrayList* list);
size_t getArrayListCapacity(const ArrayList* list);
void* getArrayListElement(ArrayList* list, size_t index);
int setArrayListElement(ArrayList* list, size_t index, void* data);
int addArrayListElement(ArrayList* list, void* data);
int removeArrayListElement(ArrayList* list);
int sortArrayList(ArrayList* list, int (*compar)(const void*, const void*));
size_t findInArrayList(ArrayList* list, const void* toFind, int (*compar)(const void*, const void*));

#endif