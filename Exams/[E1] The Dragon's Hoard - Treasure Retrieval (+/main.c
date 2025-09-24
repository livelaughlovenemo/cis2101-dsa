#include <stdio.h>
#include <stdbool.h>
#include "dragonHoard.h"

// TREASURE RETRIEVAL ENCHANTMENT (Pop Function)
void retrieveTreasure(Stack *s) {
    if (s == NULL) {
        printf("No satchel found!\n");
        return;
    }

    // Check if the satchel is empty
    if (s->top == -1) {
        printf("Retrieval FAILED - Satchel is empty!\n");
        return;
    }

    // Index of the top treasure node
    int topIndex = s->top;
    Node *node = &s->vs->nodes[topIndex];

    // Copy the item for display
    Item retrieved = node->item;

    // Update the satchel: move top to the next node
    s->top = node->next;

    // Reduce current weight
    s->currentWeight -= retrieved.weight;

    // Deallocate node manually (add back to free list)
    node->next = s->vs->avail;
    s->vs->avail = topIndex;

    // Display retrieved treasure
    printf("Retrieved '%c': SUCCESS (Remaining: %.1f)\n", 
       retrieved.itemName, s->currentWeight);
}



// Main adventure function
int main() {
    printf("The Dragon's Hoard Adventure\n");
    printf("Testing treasure pickup and retrieval\n\n");

    // Show menu and get single choice
    int choice;
    Stack kiraSatchel;
    VSpace mysticalStorage;

    // Initialize
    initVSpace(&mysticalStorage);
    initStack(&kiraSatchel, &mysticalStorage, 25.0);

    showAdventureMenu();
    scanf("%d", &choice);

    switch(choice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            runCaveScenario(choice, &kiraSatchel, &mysticalStorage);
            break;

        case 7:
        case 8:
        case 9:
        case 10:
            runGuildScenario(choice, &kiraSatchel, &mysticalStorage);
            break;

        case 11:
            runAllScenarios();
            break;

        case 12:
            runInteractiveMode();
            break;

        case 0:
            printf("Program ended.\n");
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}