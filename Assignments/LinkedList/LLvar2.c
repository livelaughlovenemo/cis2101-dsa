#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int count;
} List;

List* initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);

List* initialize() {
    List *list = (List *)malloc(sizeof(List));
    if (list == NULL) return NULL;
    list->head = NULL;
    list->count = 0;
    return list;
}

void empty(List *list) {
    Node *current = list->head;
    Node *temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    list->count = 0;
}

void insertFirst(List *list, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

void insertLast(List *list, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    list->count++;
}

void insertPos(List *list, int data, int index) {
    if (index < 0 || index > list->count) {
        printf("Invalid index\n");
        return;
    }

    if (index == 0) {
        insertFirst(list, data);
        return;
    }

    if (index == list->count) {
        insertLast(list, data);
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    Node *current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    list->count++;
}

void deleteStart(List *list) {
    if (list->head == NULL) return;

    Node *current = list->head;
    list->head = current->next;
    free(current);
    list->count--;
}

void deleteLast(List *list) {
    if (list->head == NULL) return;

    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
    } else {
        Node *current = list->head;
        for (int i = 0; i < list->count - 2; i++) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }

    list->count--;
}

void deletePos(List *list, int index) {
    if (index < 0 || index >= list->count) {
        printf("Invalid index\n");
        return;
    }

    if (index == 0) {
        deleteStart(list);
        return;
    }

    Node *current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    list->count--;
}

int retrieve(List *list, int index) {
    if (index < 0 || index >= list->count) {
        return -1;
    }

    Node *current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

int locate(List *list, int data) {
    Node *current = list->head;
    int index = 0;

    while (current != NULL) {
        if (current->data == data) return index;
        current = current->next;
        index++;
    }

    return -1;
}

void display(List *list) {
    int ctr = 0;
    Node *current = list->head;
    while (current != NULL) {
        printf("Index [%d] -> %d\n", ctr++, current->data);
        current = current->next;
    }
}

int main() {
    List *list = initialize();
    if (list == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    int data, choice, position;

    while (1) {
        printf("\nChoose Options:\n0. Free\n1. Insert First\n2. Insert Last\n3. Insert at Index\n4. Delete Start\n5. Delete Last\n6. Delete Index\n7. Retrieve\n8. Locate\n9. Display\n10. Exit\nYour Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                empty(list);
                break;

            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertFirst(list, data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertLast(list, data);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertPos(list, data, position);
                break;

            case 4:
                deleteStart(list);
                break;

            case 5:
                deleteLast(list);
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deletePos(list, position);
                break;

            case 7:
                printf("Enter index: ");
                scanf("%d", &position);
                data = retrieve(list, position);
                if (data != -1)
                    printf("Data at index %d: %d\n", position, data);
                else
                    printf("Invalid index\n");
                break;

            case 8:
                printf("Enter data to search: ");
                scanf("%d", &data);
                position = locate(list, data);
                if (position != -1)
                    printf("Data found at index: %d\n", position);
                else
                    printf("Data not found\n");
                break;

            case 9:
                display(list);
                break;

            case 10:
                empty(list);
                free(list);
                return 0;

            default:
                printf("Invalid Choice! Please choose within the said parameters!\n");
                break;
        }
    }
}
