#include <stdio.h>
#include <stdbool.h>
#define MAX 100

typedef struct {
    char students[MAX];
    int front, rear;
} Queue;

// Alternating Lines by Ma. Crista Niña Ariosa

// HELPER FUNCTIONS
/* -------------- */
void initQueue(Queue *q);
bool isEmpty(Queue q);
bool isFull(Queue q);
void enqueue(Queue *q, char x);
void dequeue(Queue *q);
char peek(Queue q);
void display(Queue q);
/* --------------- */

void mergeStudents(Queue *q); // TODO

/*------------------------------------*/
int main() {
    Queue q;
    initQueue(&q);

    int boys, girls;

    printf("How many boys?: ");
    scanf("%d", &boys);

    printf("How many girls?: ");
    scanf("%d", &girls);

    for (int i = 0; i < boys; i++) {
        enqueue(&q, 'b');
    }
    for (int i = 0; i < girls; i++) {
        enqueue(&q, 'g');
    }

    printf("Original queue of students: ");
    display(q);

    mergeStudents(&q);
    printf("Merged queue of students: ");
    display(q);

    return 0;
}

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

bool isEmpty(Queue q) {
    return (q.rear + 1) % MAX == q.front;
}

bool isFull(Queue q) {
    return (q.rear + 2) % MAX == q.front;
}

void enqueue(Queue *q, char x) {
    if (!isFull(*q)) {
        q->rear = (q->rear + 1) % MAX;
        q->students[q->rear] = x;
    }
}

void dequeue(Queue *q) {
    if (!isEmpty(*q)) {
        q->front = (q->front + 1) % MAX;
    }
}

char peek(Queue q) {
    return (!isEmpty(q)) ? q.students[q.front] : -1;
}

void display(Queue q) {
    for (int i = q.front; i <= q.rear; i++) {
        printf("%c ", q.students[i]);
    }
    printf("\n");
}
/*------------------------------------*/

void mergeStudents(Queue *q) {
    // TODO

    Queue boysQ, girlsQ;
    initQueue(&boysQ);
    initQueue(&girlsQ);

    while(!isEmpty(*q)){
        char x = peek(*q);
        dequeue(q);
        if (x == 'b'){
            enqueue(&boysQ, x);
        } else {
            enqueue(&girlsQ, x);
        }
    }

    while(!isEmpty(boysQ) && !isEmpty(girlsQ)){
        enqueue(q, peek(boysQ));
        dequeue(&boysQ);

        enqueue(q, peek(girlsQ));
        dequeue(&girlsQ);
    }

    while(!isEmpty(boysQ)){
        enqueue(q, peek(boysQ));
        dequeue(&boysQ);
    }

    while(!isEmpty(girlsQ)){
        enqueue(q, peek(girlsQ));
        dequeue(&girlsQ);
    }
}
