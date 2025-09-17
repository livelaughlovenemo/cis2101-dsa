#include <stdio.h>
#define MAX 20   // adjust as needed

typedef struct {
    int elem;
    int next;
} Node;

typedef struct {
    Node heap[MAX];
    int avail;   // index of the first free node
} VHeap;

void initialize(VHeap *V) {
    int i;
    V->avail = 0;
    for (i = 0; i < MAX - 1; i++) {
        V->heap[i].next = i + 1;   // link to next free cell
    }
    V->heap[MAX - 1].next = -1;     // end of free list
}

int allocSpace(VHeap *V) {
    int idx = V->avail;
    if (idx != -1) {               // check if available
        V->avail = V->heap[idx].next;
    }
    return idx;  // -1 if no space left
}

void deallocSpace(VHeap *V, int index) {
    if (index >= 0 && index < MAX) {
        V->heap[index].next = V->avail;
        V->avail = index;
    }
}

void insertFirst(int *L, VHeap *V, int elem) {
    int newNode = allocSpace(V);
    if (newNode != -1) {
        V->heap[newNode].elem = elem;
        V->heap[newNode].next = *L;
        *L = newNode;
    } else {
        printf("No space available.\n");
    }
}

void insertLast(int *L, VHeap *V, int elem) {
    int newNode = allocSpace(V);
    if (newNode != -1) {
        V->heap[newNode].elem = elem;
        V->heap[newNode].next = -1;

        if (*L == -1) {
            *L = newNode;   // empty list
        } else {
            int trav = *L;
            while (V->heap[trav].next != -1) {
                trav = V->heap[trav].next;
            }
            V->heap[trav].next = newNode;
        }
    } else {
        printf("No space available.\n");
    }
}

void insertSorted(int *L, VHeap *V, int elem) {
    int newNode = allocSpace(V);
    if (newNode != -1) {
        V->heap[newNode].elem = elem;
        int *trav = L;

        while (*trav != -1 && V->heap[*trav].elem < elem) {
            trav = &V->heap[*trav].next;
        }

        V->heap[newNode].next = *trav;
        *trav = newNode;
    } else {
        printf("No space available.\n");
    }
}

void delete(int *L, VHeap *V, int elem) {
    int *trav = L;

    while (*trav != -1 && V->heap[*trav].elem != elem) {
        trav = &V->heap[*trav].next;
    }

    if (*trav != -1) {
        int temp = *trav;
        *trav = V->heap[temp].next;
        deallocSpace(V, temp);
    }
}

void deleteAllOccurrence(int *L, VHeap *V, int elem) {
    int *trav = L;

    while (*trav != -1) {
        if (V->heap[*trav].elem == elem) {
            int temp = *trav;
            *trav = V->heap[temp].next;
            deallocSpace(V, temp);
        } else {
            trav = &V->heap[*trav].next;
        }
    }
}

void display(int L, VHeap V) {
    int trav = L;
    while (trav != -1) {
        printf("%d ", V.heap[trav].elem);
        trav = V.heap[trav].next;
    }
    printf("\n");
}

