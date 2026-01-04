#include <stdio.h>
#include "bitset.h"

void initialize(Set set) {
    for (int i = 0; i < SIZE; i++) {
        set[i] = false;
    }
}

void insert(Set set, int element) {
    if (element >= 0 && element < SIZE) {
        set[element] = true;
    }
}

void delete(Set set, int element) {
    if (element >= 0 && element < SIZE) {
        set[element] = false;
    }
}

bool find(Set set, int element) {
    if (element >= 0 && element < SIZE) {
        return set[element];
    }
    return false;
}

void set_union(Set A, Set B, Set C) {
    for (int i = 0; i < SIZE; i++) {
        C[i] = A[i] || B[i];
    }
}

void intersection(Set A, Set B, Set C) {
    for (int i = 0; i < SIZE; i++) {
        C[i] = A[i] && B[i];
    }
}

void difference(Set A, Set B, Set C) {
    for (int i = 0; i < SIZE; i++) {
        C[i] = A[i] && !B[i];
    }
}

void display(Set set) {
    printf("{");
    int first = 1;
    for (int i = 0; i < SIZE; i++) {
        if (set[i]) {
            if (!first) printf(", ");
            printf("%d", i);
            first = 0;
        }
    }
    printf("}\n");
}
