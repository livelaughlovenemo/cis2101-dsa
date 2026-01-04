#include <stdio.h>
#include "bitset.h"

void initialize(unsigned char *set) {
    *set = 0;
}

void insert(unsigned char *set, int element) {
    if (element >= 0 && element < 8) {
        *set |= (1 << element);
    }
}

void delete(unsigned char *set, int element) {
    if (element >= 0 && element < 8) {
        *set &= ~(1 << element);
    }
}

bool find(unsigned char set, int element) {
    if (element >= 0 && element < 8) {
        return set & (1 << element);
    }
    return false;
}

unsigned char set_union(unsigned char A, unsigned char B) {
    return A | B;
}

unsigned char intersection(unsigned char A, unsigned char B) {
    return A & B;
}

unsigned char difference(unsigned char A, unsigned char B) {
    return A & ~B;
}

void display(unsigned char set) {
    printf("{");
    int first = 1;
    for (int i = 0; i < 8; i++) {
        if (set & (1 << i)) {
            if (!first) printf(", ");
            printf("%d", i);
            first = 0;
        }
    }
    printf("}\n");
}
