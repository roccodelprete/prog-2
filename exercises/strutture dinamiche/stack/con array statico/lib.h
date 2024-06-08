#ifndef lib_h
#define lib_h
#include <stdlib.h>
#include <stdio.h>

typedef enum{false, true} boolean;

void push(int , int *, int *);
void pop(int *, int *, int *);
void show_stack(int *, int);
void invert(int *, int);

#endif

