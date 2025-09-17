#include <stdio.h>
#include <stdlib.h>
#include "insertCursorBasedTypes.h"
#include "cursorBased.h"

int main(){
    VHeap V;
    int choice, elem;

    while (1){
        printf("\n--- Cursor Based List Operations ---\n");
        printf("1. Insert First\n2.Insert Last\n3. Insert Sorted\n4. Display List\n5. Exit\n");

        scanf("%d", &choice);

        switch (choice){
            case 1:
            printf("Enter element to insert at the beginning: ");
            scanf("%d", &elem);

        }
    }
}