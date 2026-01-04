#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdbool.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int count;
} PriorityQueue;

PriorityQueue* initialize();
bool isEmpty(PriorityQueue* pq);
bool isFull(PriorityQueue* pq);
void enqueue(PriorityQueue* pq, int value);
int dequeue(PriorityQueue* pq);
int peek(PriorityQueue* pq);
void display(PriorityQueue* pq);

#endif
