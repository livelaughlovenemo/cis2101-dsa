#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* initialize() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = MAX;
    return s;
}

bool isFull(Stack* s) {
    return s->top == 0;
}

bool isEmpty(Stack* s) {
    return s->top == MAX;
}

void push(Stack* s, int value) {
    if (!isFull(s)) {
        s->top--;
        s->items[s->top] = value;
    }
}

int pop(Stack* s) {
    if (!isEmpty(s)) {
        int value = s->items[s->top];
        s->top++;
        return value;
    }
    return -1;
}

int peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return -1;
}

int top(Stack* s) {
    return s->top;
}

void display(Stack* s) {
    if (!isEmpty(s)) {
        for (int i = s->top; i < MAX; i++) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}
