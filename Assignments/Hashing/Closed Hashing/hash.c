#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

HashTable* initialize() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = EMPTY;
    }
    return ht;
}

int hash(int key) {
    return key % TABLE_SIZE;
}

bool isFull(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i] == EMPTY) return false;
    }
    return true;
}

void insert(HashTable* ht, int key) {
    if (isFull(ht)) return;

    int index = hash(key);
    while (ht->table[index] != EMPTY && ht->table[index] != DELETED) {
        index = (index + 1) % TABLE_SIZE;
    }
    ht->table[index] = key;
}

bool search(HashTable* ht, int key) {
    int index = hash(key);
    int start = index;

    while (ht->table[index] != EMPTY) {
        if (ht->table[index] == key) return true;
        index = (index + 1) % TABLE_SIZE;
        if (index == start) break;
    }
    return false;
}

void delete(HashTable* ht, int key) {
    int index = hash(key);
    int start = index;

    while (ht->table[index] != EMPTY) {
        if (ht->table[index] == key) {
            ht->table[index] = DELETED;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start) break;
    }
}

void display(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i] >= 0)
            printf("%d ", ht->table[i]);
        else
            printf("_ ");
    }
    printf("\n");
}
