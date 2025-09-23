#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

// =============================
// Stack V1 (ABC, bottom is A, top grows upward) this shit is hopeless
// =============================
void initializeStack_v1(Group* g) {
    g->top = -1;
}

bool isFull_v1(Group* g) {
    return g->top == MAX_PASSENGERS - 1;
}

bool isEmpty_v1(Group* g) {
    return g->top == -1;
}

void push_v1(Group* g, const char* value) {
    if (isFull_v1(g)) {
        printf("Stack V1 full! Cannot push %s\n", value);
        return;
    }
    g->top++;
    strncpy(g->p[g->top].passengerName, value, sizeof(g->p[g->top].passengerName) - 1);
    g->p[g->top].passengerName[sizeof(g->p[g->top].passengerName) - 1] = '\0';
}

void pop_v1(Group* g) {
    if (isEmpty_v1(g)) {
        printf("Stack V1 empty! Cannot pop.\n");
        return;
    }
    g->top--;
}

// =============================
// Stack V2 (DEF, bottom is F, top grows upward)
// =============================
void initializeStack_v2(Group* g) {
    g->top = -1;   // same convention as v1 (empty = -1)
}

bool isFull_v2(Group* g) {
    return g->top == MAX_PASSENGERS - 1;
}

bool isEmpty_v2(Group* g) {
    return g->top == -1;
}

void push_v2(Group* g, const char* value) {
    if (isFull_v2(g)) {
        printf("Stack V2 full! Cannot push %s\n", value);
        return;
    }
    g->top++;
    strncpy(g->p[g->top].passengerName, value, sizeof(g->p[g->top].passengerName) - 1);
    g->p[g->top].passengerName[sizeof(g->p[g->top].passengerName) - 1] = '\0';
}

void pop_v2(Group* g) {
    if (isEmpty_v2(g)) {
        printf("Stack V2 empty! Cannot pop.\n");
        return;
    }
    g->top--;
}
