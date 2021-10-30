#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct ArrayList ArrayList;

ArrayList* createArrayList(int capacity);
int freeArrayList(ArrayList* list);
int getArrayListSize(const ArrayList *list);
void* getArrayListElement(ArrayList* list, int index);
int setArrayListElement(ArrayList* list, int index, void* data);
int addArrayListElement(ArrayList* list, void* data);
int removeArrayListElement(ArrayList* list);
int sortArrayList(ArrayList* list, int (*compar)(const void*, const void*));
int findInArrayList(ArrayList* list, const void* toFind, int (*compar)(const void*, const void*));

#endif