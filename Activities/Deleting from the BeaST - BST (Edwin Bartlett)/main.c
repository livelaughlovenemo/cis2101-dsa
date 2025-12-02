#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

/**
 * @brief Deletes a node with the given key from the BST.
 * @param root The current root of the BST.
 * @param key_data The string key to delete.
 * @return BST The new root of the BST after deletion.
 */
BST deleteNode(BST root, const char *key_data) {
    // TODO...
}

int main() {
    // 1. Create and initialize the tree
    BST myTree = NULL;

    printf("--- Building BST for Deletion Test ---\n");
    // Keys: Apple, Banana, Grape, Kiwi, Mango(ROOT), Orange, Pineapple
    insert(&myTree, "Mango");      // Root
    insert(&myTree, "Apple");      // Left of Mango
    insert(&myTree, "Pineapple");  // Right of Mango
    insert(&myTree, "Banana");     // Right of Apple
    insert(&myTree, "Grape");      // Left of Pineapple
    insert(&myTree, "Orange");     // Right of Grape
    insert(&myTree, "Kiwi");       // Left of Orange

    printf("\nInitial In-Order Traversal:\n   ");
    inorderTraversal(myTree);
    printf("\n");

    // --- Deletion Tests ---

    printf("\n--- Test 1: Delete Leaf Node (Kiwi) ---\n");
    // Kiwi is a leaf node (0 children)
    myTree = deleteNode(myTree, "Kiwi");
    printf("Resulting Traversal: ");
    inorderTraversal(myTree);
    printf("\n");

    printf("\n--- Test 2: Delete Node with 1 Child (Apple) ---\n");
    // Apple has 1 child (Banana)
    myTree = deleteNode(myTree, "Apple");
    printf("Resulting Traversal: ");
    inorderTraversal(myTree);
    printf("\n");

    printf("\n--- Test 3: Delete Node with 2 Children (Mango - the Root) ---\n");
    // Mango is replaced by its successor (Orange)
    myTree = deleteNode(myTree, "Mango");
    printf("Resulting Traversal: ");
    inorderTraversal(myTree);
    printf("\n");

    printf("\n--- Test 4: Delete Non-Existent Key (Zebra) ---\n");
    myTree = deleteNode(myTree, "Zebra");
    printf("No change expected: ");
    inorderTraversal(myTree);
    printf("\n");

    // 2. Clean up memory
    destroyTree(myTree);
    printf("\nTree destroyed and memory freed.\n");

    return 0;
}