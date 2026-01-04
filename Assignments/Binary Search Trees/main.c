#include <stdio.h>
#include "bst.h"

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    bfs(root);
    printf("\n");

    root = delete(root, 50);
    inorder(root);
    printf("\n");

    return 0;
}
