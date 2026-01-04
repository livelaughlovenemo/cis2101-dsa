#ifndef BITSET_H
#define BITSET_H

#include <stdbool.h>

typedef struct {
    unsigned char field : 8;
} Set;

void initialize(Set *set);
void insert(Set *set, int element);
void delete(Set *set, int element);
bool find(Set set, int element);
Set set_union(Set A, Set B);
Set intersection(Set A, Set B);
Set difference(Set A, Set B);
void display(Set set);

#endif
