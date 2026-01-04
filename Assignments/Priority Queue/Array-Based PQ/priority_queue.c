#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

PriorityQueue* initialize() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->count = 0;
    return pq;
}

bool isEmpty(PriorityQueue* pq) {
    return pq->count == 0;
}

bool isFull(PriorityQueue* pq) {
    return pq->count == MAX;
}

void enqueue(PriorityQueue* pq, int value) {
    if (!isFull(pq)) {
        int i = pq->count - 1;
        while (i >= 0 && pq->data[i] < value) {
            pq->data[i + 1] = pq->data[i];
            i--;
        }
        pq->data[i + 1] = value;
        pq->count++;
    }
}

int dequeue(PriorityQueue* pq) {
    if (!isEmpty(pq)) {
        int value = pq->data[0];
        for (int i = 1; i < pq->count; i++) {
            pq->data[i - 1] = pq->data[i];
        }
        pq->count--;
        return value;
    }
    return -1;
}

int peek(PriorityQueue* pq) {
    if (!isEmpty(pq)) {
        return pq->data[0];
    }
    return -1;
}

void display(PriorityQueue* pq) {
    if (!isEmpty(pq)) {
        for (int i = 0; i < pq->count; i++) {
            printf("%d ", pq->data[i]);
        }
        printf("\n");
    }
}
