#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "types.h"

// Write your functions here

/* void init_cache(HashTable *table) {}
initializes the hash table, setting all buckets to NULL
// char **lookup_cache(HashTable *table, const char *key) {}
// bool insert_cache(HashTable *table, const char *key) {}
*/
typedef struct {
    int size;
    int head;
    int tail;
    int current;
}Node*;

void init_cache(HashTable *table){
    int size;
   *table = (table*)malloc(sizeof(HASH_BUCKETS));
    if (table != NULL){
        table->head = NULL;
        table->size = 0;
    }
}

bool insert_cache(HashTable *table, const char *key){
    if (init_cache(table)) return false;
    Node* newNode = (Node)malloc(sizeof(Node));
    if (newNode == NULL) return false;
    newNode->next = table->head;
    table->head = newNode;
    table->size++;
    return true;
}