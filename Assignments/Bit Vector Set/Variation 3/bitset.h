#ifndef BITSET_H
#define BITSET_H

#include <stdbool.h>

#define SIZE 8

typedef bool Set[SIZE];

void initialize(Set set);
void insert(Set set, int element);
void delete(Set set, int element);
bool find(Set set, int element);
void set_union(Set A, Set B, Set C);
void intersection(Set A, Set B, Set C);
void difference(Set A, Set B, Set C);
void display(Set set);

#endif
