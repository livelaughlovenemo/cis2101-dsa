#include "bitset.h"

int main() {
    unsigned char A, B, C;

    initialize(&A);
    insert(&A, 1);
    insert(&A, 6);

    initialize(&B);
    insert(&B, 3);
    insert(&B, 6);
    insert(&B, 7);

    C = set_union(A, B);
    display(C);

    C = intersection(A, B);
    display(C);

    C = difference(A, B);
    display(C);

    return 0;
}
