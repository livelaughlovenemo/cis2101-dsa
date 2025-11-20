#include <stdio.h>
#include <stdlib.h>
#include "arrayQueue.h"
#include "types.h"

int main() {

    Queue* regular = initialize();
    Queue* priority = initialize();
    int choice, customerNumber = 1;
    int nextCustomer; 
    
    while (1){
        printf("\n--- Pharmacy Queueing System ---\n");
        printf("1. Enter Regular Queue\n2. Enter Priority Queue\n3. Call Next Customer\n4. Display Queues\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice){
            case 1:
            if (isFull(regular)){
                printf("Regular queue is full. Please try again later.\n");
            } else {
                enqueue(regular, customerNumber);
                printf("You have entered the Regular queue. Your number is %d.\n", customerNumber);
                customerNumber++;
            }
            break;
            
            case 2:
            if (isFull(priority)){
                printf("Regular queue is full. Please try again later.\n");
            } else {
                enqueue(priority, customerNumber);
                printf("You have entered the Priority queue. Your number is %d.\n", customerNumber);
                customerNumber++;
            }
            break;
            
            case 3:
            if(!isEmpty(priority)){
                int next = dequeue(priority);
                printf("Calling next customer from Priority Queue. Customer number: %d\n", next);
            } else if(!isEmpty(regular)){
                int next = dequeue(regular);
                printf("Calling next customer from Regular Queue. Customer number: %d\n", next);
            } else {
                printf("No customers in queue.\n");
            }
            break;
            
            case 4:
            printf("\n-- Current Queue Status --\n");
            printf("Regular Queue: ");
            display(regular);
            printf("Priority Queue: ");
            display(priority);
            break;
            
            case 5:
            printf("Exiting program. Goodbye!\n");
            return 0;
            
            default:
            printf("Invalid Choice.\n");
        }
    
    }
    return 0;
}