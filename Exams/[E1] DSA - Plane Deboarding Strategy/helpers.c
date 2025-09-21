#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

// TODO: Write helper functions here...

void initializeStack_v1(Group* g){
    g->top = -1;
}

bool isFull_v1(Group* g){
    return g->top = MAX_PASSENGERS;
}

bool isEmpty_v1(Group* g){
    return g->top = -1;
}

void push_v1(Group* g, char* value){
    g->top++;
    g->p[g->top] = &value;
}

void pop_v1(Group* g){
    int result = g->p[g->top];
    g->top--;
}

void initializeStack_v2(Group* g){
    g->top = 0;
}

bool isFull_v2(Group* g){
    return g->top = MAX_PASSENGERS;
}

bool isEmpty_v2(Group* g){
    return g->top = 0;
}

void push_v2(Group* g, char* value){
    g->top++;
    g->p[g->top] = &value;
}

void pop_v2(Group* g){
    int result = g->p[g->top];
    g->top;
}