#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

HashTable* initialize() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

int hash(int key) {
    return key % TABLE_SIZE;
}

bool isEmpty(HashTable* ht, int index) {
    return ht->table[index] == NULL;
}

void insert(HashTable* ht, int key) {
    int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

bool search(HashTable* ht, int key) {
    int index = hash(key);
    Node* temp = ht->table[index];
    while (temp != NULL) {
        if (temp->key == key) return true;
        temp = temp->next;
    }
    return false;
}

void delete(HashTable* ht, int key) {
    int index = hash(key);
    Node* temp = ht->table[index];
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->key == key) {
            if (prev == NULL) {
                ht->table[index] = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void display(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d:", i);
        Node* temp = ht->table[i];
        while (temp != NULL) {
            printf(" %d", temp->key);
            temp = temp->next;
        }
        printf("\n");
    }
}
