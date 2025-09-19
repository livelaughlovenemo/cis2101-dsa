#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} Queue;

Queue* createQueue();

int size(Queue* queue);

bool isEmpty(Queue* queue);

int peek(Queue* queue, bool *status);

void enqueue(Queue* queue, int value);

int dequeue(Queue* queue, bool *status);

void destroyQueue(Queue* queue);

int main(){

    //first in, first out order
    Queue* q = createQueue();
    
    if(isEmpty(q)) printf("Queue is Empty!\n");


    return 0;
}

Queue* createQueue(){
    Queue* queue = malloc(sizeof(Queue));

    queue->head = NULL;
    queue->head = NULL;
    queue->size = 0;

    return queue;
}

int size(Queue* queue){
    return queue->size;
}

bool isEmpty(Queue* queue){
    return (queue->size == 0);
}

int peek(Queue* queue, bool* status){
    if (isEmpty(queue)){
     *status = false;
     return NULL;
    }

    *status = true;

    return queue->head->value;
}

void enqueue(Queue* queue, int value){
    Node* newNode = malloc(sizeof(Node));

    newNode->value = value;
    newNode->next = NULL;

    if(isEmpty(queue)){
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }

    queue->size++;

}

int dequeue(Queue* queue, bool* status){
    if(isEmpty(queue)){
        *status = false;
        return NULL;
    }

    *status = true;

    int value = queue->head->value;

    Node *oldHead = queue->head;

    if(queue->size == 1){
        queue->head = NULL;
        queue->tail = NULL;
    } else {
        queue->head = queue->head->next;
    }
    free(oldHead);

    queue->size--;

    return value;
}


void destroyQueue(Queue* queue){
    Node* currNode = queue->head;

    while(currNode != NULL){
        Node* temp = currNode;
        currNode = currNode->next;
        free(temp);
    }

    free(queue);
}
