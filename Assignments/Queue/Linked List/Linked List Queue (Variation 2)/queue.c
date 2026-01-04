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
    return q->rear == NULL;
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = q->rear;
    q->rear = newNode;

    if (q->front == NULL) {
        q->front = newNode;
    }
}

int dequeue(Queue* q) {
    if (!isEmpty(q)) {
        Node* temp = q->rear;

        if (q->rear == q->front) {
            int value = temp->data;
            free(temp);
            q->rear = NULL;
            q->front = NULL;
            return value;
        }

        while (temp->next != q->front) {
            temp = temp->next;
        }

        int value = q->front->data;
        free(q->front);
        q->front = temp;
        q->front->next = NULL;

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
        Node* temp = q->rear;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
