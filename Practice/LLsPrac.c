#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int data;
    struct Node* next;
} Node;

typedef struct{
    Node* head;
    int count;
}List;

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

int main(){


}

List* initalize(){
    
}