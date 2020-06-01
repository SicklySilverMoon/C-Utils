#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void* a, const void* b);

int main() {
    ArrayList* list = createArrayList(1);
    
    srand(time(NULL));
    int a=rand();
    printf("value of added first element: %d\n", a);
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
    
    printf("\nUNSORTED LIST:\n\n");
    for (int i=0; i<getArrayListSize(list); i++) {
        printf("%d\n", *(int*)(getArrayListElement(list, i)));
    }
    
    sortArrayList(list, compare);
    
    printf("\nSORTED LIST:\n\n");
    for (int i=0; i<getArrayListSize(list); i++) {
        printf("%d\n", *(int*)(getArrayListElement(list, i)));
    }
    
    removeArrayListElement(list);
    printf("\nLAST ELEMENT REMOVED\n\n");
    
    for (int i=0; i<getArrayListSize(list); i++) {
        printf("%d\n", *(int*)(getArrayListElement(list, i)));
    }
    
    printf("\nindex of first added element is: %d\n", (findInArrayList(list, &a, compare)));
    
    int testSet = 2;
    setArrayListElement(list, getArrayListSize(list)/2, &testSet);
    
    printf("\nMID ELEMENT SET TO 2\n\n");
    for (int i=0; i<getArrayListSize(list); i++) {
        printf("%d\n", *(int*)(getArrayListElement(list, i)));
    }
    
    freeArrayList(list);
    return 0;
}

int compare(const void* a, const void* b) {
    int first = **(int**)a;
    int second = **(int**)b;
    
    if (first > second) return 1;
    if (first < second) return -1;
    return 0;
}