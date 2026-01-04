#include <stdio.h>
#include "queue.h"

int main() {
    Queue* q = initialize();

    enqueue(q, 1);
    enqueue(q, 3);
    enqueue(q, 2);
    enqueue(q, 5);

    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    printf("Front: %d\n", front(q));

    display(q);

    return 0;
}
