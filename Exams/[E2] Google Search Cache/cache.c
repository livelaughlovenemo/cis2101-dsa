#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "types.h"

// Initialize all buckets to NULL
void init_cache(HashTable *table) {
    for (int i = 0; i < HASH_BUCKETS; i++) {
        table->buckets[i] = NULL;
    }
}

// Look up a key in the cache (separate chaining implementation)
char **lookup_cache(HashTable *table, const char *key) {
    // Check for null pointers
    if (table == NULL || key == NULL) {
        return NULL;
    }
    
    // Compute hash index
    unsigned int index = hash(key);
    
    // Traverse the linked list at this bucket
    CacheEntry *current = table->buckets[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            // Key found - cache hit
            return current->results;
        }
        current = current->next;
    }
    
    // Key not found - cache miss
    return NULL;
}

// Insert a key into the cache (open hashing with separate chaining)
bool insert_cache(HashTable *table, const char *key) {
    // Check for null pointers
    if (table == NULL || key == NULL) {
        return false;
    }
    
    // Check if key already exists in cache
    if (lookup_cache(table, key) != NULL) {
        // Key already exists - according to test case 3, this should return true
        // (redundant insertion is "skipped" successfully)
        return true;
    }
    
    // Simulate database fetch for new key
    char **results = simulate_database_fetch(key);
    if (results == NULL) {
        // Database returned no results - insertion fails
        return false;
    }
    
    // Create new cache entry
    CacheEntry *new_entry = malloc(sizeof(CacheEntry));
    if (new_entry == NULL) {
        // Cleanup results on allocation failure
        for (int i = 0; i < RESULT_COUNT; i++) {
            free(results[i]);
        }
        free(results);
        return false;
    }
    
    // Allocate and copy key string
    new_entry->key = malloc(strlen(key) + 1);
    if (new_entry->key == NULL) {
        free(new_entry);
        for (int i = 0; i < RESULT_COUNT; i++) {
            free(results[i]);
        }
        free(results);
        return false;
    }
    strcpy(new_entry->key, key);
    
    // Store results
    new_entry->results = results;
    
    // Compute hash index
    unsigned int index = hash(key);
    
    // Insert at beginning of chain (head insertion for O(1) time)
    new_entry->next = table->buckets[index];
    table->buckets[index] = new_entry;
    
    return true;
}