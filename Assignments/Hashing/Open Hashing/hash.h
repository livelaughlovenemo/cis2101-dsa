#ifndef HASH_H
#define HASH_H

#include <stdbool.h>

#define TABLE_SIZE 10

typedef struct node {
    int key;
    struct node* next;
} Node;

typedef struct {
    Node* table[TABLE_SIZE];
} HashTable;

HashTable* initialize();
int hash(int key);
bool isEmpty(HashTable* ht, int index);
void insert(HashTable* ht, int key);
bool search(HashTable* ht, int key);
void delete(HashTable* ht, int key);
void display(HashTable* ht);

#endif
