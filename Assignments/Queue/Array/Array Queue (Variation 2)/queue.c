#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* initialize() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 1;
    q->rear = 0;
    return q;
}

bool isEmpty(Queue* q) {
    return q->front == (q->rear + 1) % MAX;
}

bool isFull(Queue* q) {
    return q->front == (q->rear + 2) % MAX;
}

void enqueue(Queue* q, int value) {
    if (!isFull(q)) {
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    if (!isEmpty(q)) {
        int value = q->items[q->front];
        q->front = (q->front + 1) % MAX;
        return value;
    }
    return -1;
}

int front(Queue* q) {
    if (!isEmpty(q)) {
        return q->items[q->front];
    }
    return -1;
}

void display(Queue* q) {
    if (!isEmpty(q)) {
        int i = q->front;
        while (i != (q->rear + 1) % MAX) {
            printf("%d ", q->items[i]);
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}
