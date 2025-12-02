#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h.>
#include <types.h>

#ifndef CURSORBASED_H
#define CURSORBASED_H

void initialize(VHeap* V){
    int i;
    V->avail = 0;
    for (i = 0; i < MAX - 1; i++) {
        V->H[i].next = i + 1;
    }
    V->H[MAX - 1].next = -1;
}

void insertFirst(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    if (newCell == -1) return; // No space available
    V->H[newCell].elem = elem;
    V->H[newCell].next = *L;
    *L = newCell;
}
void insertLast(int *L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    if (newCell == -1) return; // No space available
    V->H[newCell].elem = elem;
    V->H[newCell].next = -1;
    
    if (*L == -1) {
        *L = newCell;
    } else {
        int trav = *L;
        while (V->H[trav].next != -1) {
            trav = V->H[trav].next;
        }
        V->H[trav].next = newCell;
    }
}

void insertSorted(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    if (newCell == -1) return; // No space available
    V->H[newCell].elem = elem;
    
    if (*L == -1 || V->H[*L].elem >= elem) {
        V->H[newCell].next = *L;
        *L = newCell;
    } else {
        int trav = *L;
        while (V->H[trav].next != -1 && V->H[V->H[trav].next].elem < elem) {
            trav = V->H[trav].next;
        }
        V->H[newCell].next = V->H[trav].next;
        V->H[trav].next = newCell;
    }
}

void display(int L, VHeap V){
    int trav = L;
    while (trav != -1){
        printf("%d ", V.H[trav].elem);
        trav = V.H[trav].next;
    }
    printf("\n");
}
#endif
