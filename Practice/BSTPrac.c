#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *LC;
    struct node *RC;
} Node, *BST;

void insert(BST* B, int value){
    BST* trav = B;

    while(*trav != NULL && (*trav)->data != value){
        trav = (value >(*trav)->data) 
        ? &((*trav)->RC)
        : &((*trav)->LC);
    }
    //CALLOC VERSION
    if (*trav == NULL){
        *trav = (BST)calloc(1, sizeof(Node));
        (*trav)->data = value;
    }
    /* MALLOC VERSION
    if (*trav == NULL) {
        Node *temp = (BST)malloc(sizeof(Node));
        temp->LC = NULL;
        temp->RC = NULL;
        temp->data = value;
        *trav = temp;
    }
    */ 
}
// Recursion 
void inOrder(BST B){
    if (B != NULL){
        inOrder(B->LC);
        printf("%d ", B->data);
        inOrder(B->RC);
    }
}

void preOrder(BST B){
    if (B != NULL){
        printf("%d ", B->data);
        preOrder(B->LC);
        preOrder(B->RC);
    }
}

void postOrder(BST B){
    if (B != NULL){
        postOrder(B->LC);
        postOrder(B->RC);
        printf("%d ", B->data);
    }
}
/* 
3 concepts of deletion:
Delete(1):Leaf Node
    - dealloc the node

Delete(2):Node has one child(either left or right)
    - replace node with LC/RC
    - save the parent in a temp
Delete(3): two children
    - replace node with either:
        - leftmost node with the right subtree (smallest value)
        - rightmost node with the left subtree (largest value)
1st condition (left child):
trav->LC != NULL;

2nd condition
trav->LC != NULL
replace trav with LC

3rd condition 


*/

Node* deleteNode(BST *B, int value) {
    BST *trav = B;

    // Step 1: Find the node
    while (*trav != NULL && (*trav)->data != value) {
        trav = (value > (*trav)->data)
                ? &((*trav)->RC)
                : &((*trav)->LC);
    }

    // Value NOT found
    if (*trav == NULL) return NULL;

    Node *target = *trav;

    // CASE 1: Leaf node
    if (target->LC == NULL && target->RC == NULL) {
        *trav = NULL;
        free(target);
        return NULL;
    }

    // CASE 2: One child (LEFT only)
    if (target->LC != NULL && target->RC == NULL) {
        *trav = target->LC;
        free(target);
        return *trav;
    }

    // CASE 2: One child (RIGHT only)
    if (target->LC == NULL && target->RC != NULL) {
        *trav = target->RC;
        free(target);
        return *trav;
    }

    // CASE 3: Two children
    // Get INORDER SUCCESSOR = leftmost of RIGHT subtree
    BST *succTrav = &target->RC;
    while ((*succTrav)->LC != NULL) {
        succTrav = &((*succTrav)->LC);
    }

    // Copy successor data → target
    target->data = (*succTrav)->data;

    // Delete successor node
    Node *succ = *succTrav;

    // Successor may have right child only
    *succTrav = (succ->RC != NULL) ? succ->RC : NULL;

    free(succ);
    return *trav;
}


int main() {
    BST B = NULL;

    insert(&B, 50);
    insert(&B, 30);
    insert(&B, 70);
    insert(&B, 10);
    insert(&B, 40);
    insert(&B, 60);
    insert(&B, 80);

    printf("In-order traversal: ");
    inOrder(B);
    printf("\n");

    printf("Pre-Order traversal: ");
    preOrder(B);
    printf("\n");

    printf("Post-Order traversal: ");
    postOrder(B);
    printf("\n");

    return 0;
}