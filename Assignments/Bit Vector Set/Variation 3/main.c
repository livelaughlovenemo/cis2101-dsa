#include "bitset.h"

int main() {
    Set A, B, C;

    initialize(A);
    insert(A, 0);
    insert(A, 2);
    insert(A, 7);

    initialize(B);
    insert(B, 2);
    insert(B, 4);
    insert(B, 5);

    set_union(A, B, C);
    display(C);

    intersection(A, B, C);
    display(C);

    difference(A, B, C);
    display(C);

    return 0;
}
