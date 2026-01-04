#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* initialize() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

bool isFull(Stack* s) {
    return false;
}

bool isEmpty(Stack* s) {
    return s->top == NULL;
}

void push(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) {
    if (!isEmpty(s)) {
        Node* temp = s->top;
        int value = temp->data;
        s->top = temp->next;
        free(temp);
        return value;
    }
    return -1;
}

int peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->top->data;
    }
    return -1;
}

void display(Stack* s) {
    if (!isEmpty(s)) {
        Node* temp = s->top;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
