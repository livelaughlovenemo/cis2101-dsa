#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int count;
} List;

List initialize();
List empty(List L);
List insertFirst(List L, int data);
List insertLast(List L, int data);
List insertPos(List L, int data, int index);
List deleteStart(List L);
List deleteLast(List L);
List deletePos(List L, int index);
int retrieve(List L, int index);
int locate(List L, int data);
void display(List L);

List initialize() {
    List L;
    L.head = NULL;
    L.count = 0;
    return L;
}

List empty(List L) {
    Node *current = L.head;
    Node *temp;
    
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    
    L.head = NULL;
    L.count = 0;
    return L;
}

List insertFirst(List L, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return L;
    }
    
    newNode->data = data;
    newNode->next = L.head;
    L.head = newNode;
    L.count++;
    
    return L;
}

List insertLast(List L, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return L;
    }
    
    newNode->data = data;
    newNode->next = NULL;
    
    if (L.head == NULL) {
        L.head = newNode;
    } else {
        Node *current = L.head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    L.count++;
    return L;
}

List insertPos(List L, int data, int index) {
    if (index < 0 || index > L.count) {
        printf("Invalid index\n");
        return L;
    }
    
    if (index == 0) {
        return insertFirst(L, data);
    }
    
    if (index == L.count) {
        return insertLast(L, data);
    }
    
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return L;
    }
    
    newNode->data = data;
    
    Node *current = L.head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    L.count++;
    
    return L;
}

List deleteStart(List L) {
    if (L.head == NULL) {
        return L;
    }
    
    Node *current = L.head;
    L.head = current->next;
    free(current);
    L.count--;
    
    return L;
}

List deleteLast(List L) {
    if (L.head == NULL) {
        return L;
    }
    
    if (L.head->next == NULL) {
        free(L.head);
        L.head = NULL;
        L.count = 0;
        return L;
    }
    
    Node *current = L.head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    free(current->next);
    current->next = NULL;
    L.count--;
    
    return L;
}

List deletePos(List L, int index) {
    if (index < 0 || index >= L.count) {
        printf("Invalid index\n");
        return L;
    }
    
    if (index == 0) {
        return deleteStart(L);
    }
    
    Node *current = L.head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    
    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    L.count--;
    
    return L;
}

int retrieve(List L, int index) {
    if (index < 0 || index >= L.count) {
        printf("Invalid index\n");
        return -1;
    }
    
    Node *current = L.head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    
    return current->data;
}

int locate(List L, int data) {
    Node *current = L.head;
    int index = 0;
    
    while (current != NULL) {
        if (current->data == data) {
            return index;
        }
        current = current->next;
        index++;
    }
    
    return -1;
}

void display(List L) {
    Node *current = L.head;
    int index = 0;
    
    printf("List elements: ");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
        index++;
    }
    printf(" -> NULL\n");
    printf("Count: %d\n", L.count);
}

int main() {
    List L = initialize();
    int data, choice, position;
    
    while (1) {
        printf("\nChoose Options:\n");
        printf("0. Empty\n");
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Insert at Position\n");
        printf("4. Delete Start\n");
        printf("5. Delete Last\n");
        printf("6. Delete Position\n");
        printf("7. Retrieve\n");
        printf("8. Locate\n");
        printf("9. Display\n");
        printf("10. Exit\n");
        printf("Your Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                L = empty(L);
                break;
                
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                L = insertFirst(L, data);
                break;
                
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                L = insertLast(L, data);
                break;
                
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                L = insertPos(L, data, position);
                break;
                
            case 4:
                L = deleteStart(L);
                break;
                
            case 5:
                L = deleteLast(L);
                break;
                
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                L = deletePos(L, position);
                break;
                
            case 7:
                printf("Enter index: ");
                scanf("%d", &position);
                data = retrieve(L, position);
                if (data != -1) {
                    printf("Data at index %d: %d\n", position, data);
                }
                break;
                
            case 8:
                printf("Enter data to search: ");
                scanf("%d", &data);
                position = locate(L, data);
                if (position != -1) {
                    printf("Data found at index: %d\n", position);
                } else {
                    printf("Data not found\n");
                }
                break;
                
            case 9:
                display(L);
                break;
                
            case 10:
                L = empty(L);
                return 0;
                
            default:
                printf("Invalid Choice!\n");
                break;
        }
    }
    
    return 0;
}