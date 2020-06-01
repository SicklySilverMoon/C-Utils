#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sortCompare(const void* a, const void* b);
int findCompare(const void* a, const void* b);

int main(int argc, char* argv[]) {
    ArrayList* list = createArrayList(4);
    
    srand(time(NULL));
    int a=rand();
    addArrayListElement(list, &a);
    int b=rand();
    addArrayListElement(list, &b);
    int c=rand();
    addArrayListElement(list, &c);
    int d=rand();
    addArrayListElement(list, &d);
    int e=rand();
    addArrayListElement(list, &e);
    int f=rand();
    addArrayListElement(list, &f);
    
    sortArrayList(list, sortCompare);
    
    for (int i=0; i<getArrayListSize(list); i++) {
        printf("%d\n", *(int*)(getArrayListElement(list, i)));
    }
    
    removeArrayListElement(list);
    printf("\nLAST ELEMENT REMOVED\n\n");
    
    for (int i=0; i<getArrayListSize(list); i++) {
        printf("%d\n", *(int*)(getArrayListElement(list, i)));
    }
    
    printf("\nindex of first added element is: %d\n", (findInArrayList(list, &a, findCompare)));
    
    int testSet = 2;
    setArrayListElement(list, getArrayListSize(list)/2, &testSet);
    
    printf("\nMID ELEMENT SET TO 2\n\n");
    for (int i=0; i<getArrayListSize(list); i++) {
        printf("%d\n", *(int*)(getArrayListElement(list, i)));
    }
    
    freeArrayList(list);
    return 0;
}

int sortCompare(const void* a, const void* b) {
    return (**(int**)a - **(int**)b);
}

int findCompare(const void* a, const void* b) {
    if (*(int*)a == *(int*)b) return 1;
    return 0;
}