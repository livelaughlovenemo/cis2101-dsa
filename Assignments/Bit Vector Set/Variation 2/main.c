#include "bitset.h"

int main() {
    Set A, B, C;

    initialize(&A);
    insert(&A, 0);
    insert(&A, 4);
    insert(&A, 5);

    initialize(&B);
    insert(&B, 2);
    insert(&B, 5);

    C = set_union(A, B);
    display(C);

    C = intersection(A, B);
    display(C);

    C = difference(A, B);
    display(C);

    return 0;
}
