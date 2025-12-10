#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LENGTH 5

typedef struct {
    int *elem;
    int count;
    int max;
} List; // dynamic array, accessed by pointer

void initialize(List *L) {
    L->elem = (int*)malloc(LENGTH * sizeof(int));
    L->max = LENGTH;
    L->count = 0;
}

void resize(List *L) {
    L->max *= 2;
    L->elem = (int*)realloc(L->elem, L->max * sizeof(int));
}

void insertPos(List *L, int data, int position) {
    if (position < 0 || position > L->count) {
        printf("Invalid Position\n");
        return;
    }
    
    if (L->count == L->max) {
        resize(L);
    }

    for (int i = L->count; i > position; i--) {
        L->elem[i] = L->elem[i - 1];
    }
    L->elem[position] = data;
    L->count++;
}

void deletePos(List *L, int position) {
    if (position < 0 || position >= L->count) {
        printf("Invalid position\n");
        return;
    }

    for (int i = position; i < L->count - 1; i++) {
        L->elem[i] = L->elem[i + 1];
    }
    L->count--;
}

int locate(List *L, int data) {
    for (int i = 0; i < L->count; i++) {
        if (L->elem[i] == data) {
            return i; 
        }
    }
    return -1;
}

int retrieve(List *L, int position) {
    if (position < 0 || position >= L->count) {
        printf("Invalid position\n");
        return -1;
    }
    return L->elem[position];
}

void insertSorted(List *L, int data) {
    if (L->count == L->max) {
        resize(L);
    }

    int i = L->count - 1;
    while (i >= 0 && L->elem[i] > data) {
        L->elem[i + 1] = L->elem[i];
        i--;
    }
    L->elem[i + 1] = data;
    L->count++;
}

void display(List *L) {
    int ctr = 0;
    printf("List of Elements:");
    for (int i = 0; i < L->count; i++) {
        printf("\nElement[%d] = %d", ctr++, L->elem[i]);
    }
    printf("\n");
}

void makeNULL(List *L) {
    free(L->elem);
    L->elem = NULL;
    L->count = 0;
    L->max = 0;
}