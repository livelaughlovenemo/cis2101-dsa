#include "hash.h"

int main() {
    HashTable* ht = initialize();

    insert(ht, 12);
    insert(ht, 22);
    insert(ht, 32);
    insert(ht, 42);

    display(ht);

    delete(ht, 22);
    display(ht);

    return 0;
}
