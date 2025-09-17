#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int arr[MAX];
    int count;
} List;

void initialize (List* L){
    L->count = 0;
}

void insertFirst(List* L, int data){
    for (int i = L->count; i > 0; i--){
        L->arr[i] = L->arr[i - 1];
    }
    L->arr[0] = data;
    L->count++;
}

void insertLast(List *L, int data){
    L->arr[L->count++] = data;
}

void insertAtIndex(List *L, int data, int position){
    for (int i = L->count; i > position; i--){
        L->arr[i] = L->arr[i-1];
    }
    L->arr[position] = data;
    L->count++;
}

void display(List* L, int data){
    printf("Array:");
    for (int i = 0; i < L->count; i++){
        printf("[%d]", L->arr[i]);
    }
}
 
void removeFirst(List* L){
    for (int i = 0; i < L->count - 1; i++){
        L->arr[i] = L->arr[i - 1];
    }
    L->count--;
}

void removeLast(List *L){
    L->count--;
}

void removeAtIndex(List* L, int position){
    for (int i = position; i < L->count; i++){
        L->arr[i] = L->arr[i + 1];
    }
    L->count--;
}

#endif