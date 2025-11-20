#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "arrayStack.h"

int main() {
  
    Stack stacks[3];
    for (int i = 0; i < 3; i++){
        initialize(&stacks[i]);
    }
    
    int choice, value, found;
    
    while (1){
        printf("\n--- Warehouse Inventory Management System ---\n");
        printf("1. Push a container\n2. Pop a container\n3. Check if a container exists\n4. Display all stacks\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice){
            case 1:
            printf("Enter container ID to push: ");
            scanf("%d", &value);
            int added = 0;
            for(int i = 0; i < 3; i++){
                if (!isFull(&stacks[i])){
                    push(&stacks[i], value);
                    added = 1; 
                    
                    printf("Container %d pushed successfully.\n", value);
                    break;
                }
            }
            if (!added) {
                printf("All stacks are full.\n");
            }
            break;
            
            case 2:
            int removed = 0;
            for (int i = 2; i >= 0; i--){
                if (!isEmpty(&stacks[i])){
                    printf("Container %d popped successfully.\n", pop(&stacks[i]));
                    removed = 1;
                    break;
                }
            }
            if (!removed){
                printf("Error: All stacks are empty. Cannot pop container.\n");
            }
            break;
            
            case 3: 
            printf("Enter container ID to check: ");
            scanf("%d", &value);
            found = 0;
            for (int i = 0; i < 3;i++){
                for (int j = 0; j <= stacks[i].top; j++){
                    if (stacks[i].items[j] == value){
                        printf("Container %d exists in a stack.\n", value);
                        found = 1;
                        break;
                    }
                }
                if (found) break;
            }
            if (!found){
                printf("Container %d does not exist in any stack.\n", value);
            }
            break;
            
            case 4:
            for (int i = 0; i < 3; i++){
                printf("\n--- Stack %d ---\n", i + 1);
                display(&stacks[i]);
            }
            break;
            
            case 5:
            printf("Exiting program.\n");
            return 0;
            
            default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}