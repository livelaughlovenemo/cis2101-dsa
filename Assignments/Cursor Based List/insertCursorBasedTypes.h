#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 4

typedef struct {
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;

void initialize(VHeap *V);
void insertFirst(int* L, VHeap* V, int elem);
void insertLast(int *L, VHeap* V, int elem);
void insertSorted(int* L, VHeap* V, int elem);
void display(int L, VHeap V);

#endif