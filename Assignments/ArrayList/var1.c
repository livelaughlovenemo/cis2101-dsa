#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List; //static array, accessed by value 

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

List initialize(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    if (position < 0 || position > L.count){
        printf("Invalid Position\n");
        return L;
    }
    
    if (L.count == MAX){
        printf("List is full\n");
        return L;
    }

    for (int i = L.count; i > position; i--){
        L.elem[i] = L.elem[i - 1];
    }
    L.elem[position] = data;
    L.count++;

    return L;
    }


List deletePos(List L, int position){
    if (position < 0 || position >= L.count) {
        printf("Invalid position\n");
        return L;
    }

    for (int i = position; i < L.count - 1; i++) {
        L.elem[i] = L.elem[i + 1];
    }
    L.count--;

    return L;
}

int locate(List L, int data){
    for (int i = 0; i < L.count; i++) {
        if (L.elem[i] == data) {
            return i; 
        }
    }
    return -1;

}

List insertSorted(List L, int data) {
    if (L.count == MAX) {
        printf("List is full!\n");
        return L;
    }

    int i = L.count - 1;
    while (i >= 0 && L.elem[i] > data) {
        L.elem[i + 1] = L.elem[i];
        i--;
    }
    L.elem[i + 1] = data;
    L.count++;

    return L;
}

void display(List L){
    int ctr = 0;
    printf("List of Elements:");
    for (int i = 0; i < L.count; i++){
        printf("\nElement[%d] = %d",ctr++, L.elem[i]);
    }
    printf("\n");
}


int main (){
    List L;
    L = initialize(L);
    int choice, data, position;

    while(1){
        printf("1. Insert\n2. Delete\n3. Locate\n4. Sorted\n5. Display\n6. Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter Position: ");
                scanf("%d", &position);
                L = insertPos(L, data, position);
                break;
            case 2:
                printf("Enter position:");
                scanf("%d", &position);
                L = deletePos(L, position);
                break;
            case 3:
                printf("Enter data to locate:");
                scanf("%d", &data);
                position = locate(L, data);
                if (position != -1){
                    printf("Element %d found at position %d\n", data, position);
                } else {
                    printf("Element not found!\n");
                }
                break; 
            case 4:
                printf("Enter data:");
                scanf("%d", &data);
                L = insertSorted(L, data);
                break;
            case 5:
                display(L);
                break;
            case 6:
                return 0;

            default:
                printf("di pwede\n");
        }
    }
}
