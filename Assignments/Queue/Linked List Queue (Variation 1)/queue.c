#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* initialize() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isFull(Queue* q) {
    return false;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (!isEmpty(q)) {
        Node* temp = q->front;
        int value = temp->data;
        q->front = temp->next;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        free(temp);
        return value;
    }
    return -1;
}

int front(Queue* q) {
    if (!isEmpty(q)) {
        return q->front->data;
    }
    return -1;
}

void display(Queue* q) {
    if (!isEmpty(q)) {
        Node* temp = q->front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
