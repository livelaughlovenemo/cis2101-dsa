#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* initialize() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->count = 0;
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isFull(Queue* q) {
    return q->count == MAX;
}

bool isEmpty(Queue* q) {
    return q->count == 0;
}

void enqueue(Queue* q, int value) {
    if (!isFull(q)) {
        if (isEmpty(q)) {
            q->front = 0;
            q->rear = 0;
        } else {
            q->rear = (q->rear + 1) % MAX;
        }
        q->items[q->rear] = value;
        q->count++;
    }
}

int dequeue(Queue* q) {
    if (!isEmpty(q)) {
        int value = q->items[q->front];
        if (q->count == 1) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
        q->count--;
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
        for (int c = 0; c < q->count; c++) {
            printf("%d ", q->items[i]);
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}
