#include <stdio.h>
#include <stdlib.h>
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

void initialize(VHeap *V) {
    int i;
    V->avail = 0;
    for (i = 0; i < MAX - 1; i++) {
        V->H[i].next = i + 1;
    }
    V->H[MAX - 1].next = -1;  
}

void insertFirst(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    
}

void insertLast(int *L, VHeap* V, int elem){

}

void insertSorted(int* L, VHeap* V, int elem){
    
}

void display(int L, VHeap V){
    int trav = L;
    while (trav != -1){
        printf("%d ", V.H[trav].elem);
        trav = V.H[trav].next;
    }
    printf("\n");
}
