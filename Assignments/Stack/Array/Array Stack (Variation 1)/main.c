#include <stdio.h>
#include "stack.h"

int main() {
    Stack* s = initialize();

    push(s, 1);
    push(s, 3);
    push(s, 2);
    push(s, 5);

    display(s);

    printf("Popped: %d\n", pop(s));
    printf("Peek: %d\n", peek(s));
    printf("Top index: %d\n", top(s));

    display(s);

    return 0;
}
