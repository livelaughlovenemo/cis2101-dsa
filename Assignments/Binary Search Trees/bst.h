#ifndef BST_H
#define BST_H

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* insert(Node* root, int value);
Node* delete(Node* root, int value);
Node* search(Node* root, int value);

void inorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);
void bfs(Node* root);

#endif
