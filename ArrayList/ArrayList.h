typedef struct ArrayList ArrayList;

ArrayList* createArrayList(int capacity);
int freeArrayList(ArrayList* list);
int getArrayListSize(const ArrayList *list);
void* getArrayListElement(ArrayList* list, int index);
int setArrayListElement(ArrayList* list, int index, void* data);
int addArrayListElement(ArrayList* list, void* data);
int removeArrayListElement(ArrayList* list);
int sortArrayList(ArrayList* list, int (*compar)(const void*, const void*));
int findInArrayList(ArrayList* list, void* toFind, int (*compar)(const void*, const void*));