#ifndef HASH_H
#define HASH_H

#include <stdbool.h>

#define TABLE_SIZE 10
#define EMPTY -1
#define DELETED -2

typedef struct {
    int table[TABLE_SIZE];
} HashTable;

HashTable* initialize();
int hash(int key);
bool isFull(HashTable* ht);
void insert(HashTable* ht, int key);
bool search(HashTable* ht, int key);
void delete(HashTable* ht, int key);
void display(HashTable* ht);

#endif
