#include <stdio.h>

#ifndef STRUCT_VAR
#define STRUCT_VAR

struct innerStruct {
    int b;
};

typedef struct {
    int a;
    struct innerStruct b;
    struct list *next;
} list;

typedef struct {
    int a;
    struct innerStruct b;
    struct list2 *next;
    char* text;
} list2;

typedef struct {
    int a;
    struct innerStruct b;
    list2 * innerList;
    struct listOfList *next;
} listOfList;

#endif
