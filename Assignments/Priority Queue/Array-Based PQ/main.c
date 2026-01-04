#include <stdio.h>
#include "priority_queue.h"

int main() {
    PriorityQueue* pq = initialize();

    enqueue(pq, 30);
    enqueue(pq, 10);
    enqueue(pq, 50);
    enqueue(pq, 20);

    display(pq);

    printf("Dequeued: %d\n", dequeue(pq));
    printf("Peek: %d\n", peek(pq));

    display(pq);

    return 0;
}
