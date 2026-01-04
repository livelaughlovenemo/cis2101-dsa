#include <stdio.h>
#include "bitset.h"

void initialize(Set *set) {
    set->field = 0;
}

void insert(Set *set, int element) {
    if (element >= 0 && element < 8) {
        set->field |= (1 << element);
    }
}

void delete(Set *set, int element) {
    if (element >= 0 && element < 8) {
        set->field &= ~(1 << element);
    }
}

bool find(Set set, int element) {
    if (element >= 0 && element < 8) {
        return set.field & (1 << element);
    }
    return false;
}

Set set_union(Set A, Set B) {
    Set C;
    C.field = A.field | B.field;
    return C;
}

Set intersection(Set A, Set B) {
    Set C;
    C.field = A.field & B.field;
    return C;
}

Set difference(Set A, Set B) {
    Set C;
    C.field = A.field & ~B.field;
    return C;
}

void display(Set set) {
    printf("{");
    int first = 1;
    for (int i = 0; i < 8; i++) {
        if (set.field & (1 << i)) {
            if (!first) printf(", ");
            printf("%d", i);
            first = 0;
        }
    }
    printf("}\n");
}
